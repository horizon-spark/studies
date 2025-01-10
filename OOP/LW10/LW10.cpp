#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};
unordered_map<string,int> noteCoord 
{
    {"C",0}, {"C#",1}, {"Db",1}, {"D",2}, {"D#",3}, {"Eb",3}, {"E",4}, {"F",5}, {"F#",6},
    {"Gb",6}, {"G",7}, {"G#",8}, {"Ab",8}, {"A",9}, {"A#",10}, {"Bb",10}, {"B",11}
};
unordered_map<int,string> noteName
{
    {0,"C"}, {1,"C#"}, {2,"D"}, {3,"D#"}, {4,"E"}, {5,"F"}, {6,"F#"}, {7,"G"}, {8,"G#"},
    {9,"A"}, {10,"A#"}, {11,"B"}
};
unordered_map<int,string> intervals
{
    {0,"Unison"}, {1,"Minor second"}, {2,"Major second"}, {3, "Minor third"}, {4,"Major third"},
    {5,"Perfect fourth"}, {6,"Augmented fourth"}, {7,"Perfect fifth"}, {8,"Minor sixth"},
    {9,"Major sixth"}, {10,"Minor seventh"}, {11,"Major seventh"}
};
unordered_map<pair<int,int>,string,pair_hash> chords
{
    {make_pair(2,4),"Major Trichord"}, {make_pair(2,3),"Minor Trichord"}, {make_pair(1,3),"Phrygian Trichord"},
    {make_pair(4,7),"Major triad"}, {make_pair(3,7),"Minor triad"}, {make_pair(3,6),"Diminished triad"},
    {make_pair(5,7),"Csus4"}, {make_pair(6,7),"Csus#4"}, {make_pair(5,6),"C°sus4"},
    {make_pair(7,11),"Cmaj7no3"}, {make_pair(7,10),"C7no3"}, {make_pair(6,10),"C-7b5 no3"},
    {make_pair(4,11),"Cmaj7 no5"}, {make_pair(4,10),"C7 no5"}, {make_pair(3,10),"Cm7 no5"},
    {make_pair(1,2),"Chromatic cluster"}, {make_pair(4,8),"Augmeted triad"},
    {make_pair(1,4),"Phrygian major trichord"}, {make_pair(3,4),"#2 trichord"}
};

class Note 
{
    friend class Interval;
    friend class Chord;
    private:
        string name;
        int octave, length;

        string get_name(int coord)
        {
            if (coord < 9 || coord > 96) {
                cout << "Note is out of standart bounds!" << endl;
                if (coord < 9) {
                    cout << "The closest note (A, octave 0) is returned" << endl;
                    return "A";
                } else {
                    cout << "The closest note (C, octave 8) is returned" << endl;
                    return "C";
                }
            } else {
                return noteName[coord % 12];
            }
            return "";
        }
        int get_octave(int coord)
        {
            if (coord < 9) return 0;
            else if (coord > 96) return 8;
            return coord / 12;
        }
        int get_coord()
        {
            return octave * 12 + noteCoord[name];
        }
        Note(int coord, int len)
        {
            name = get_name(coord);
            octave = get_octave(coord);
            length = len;
        }
    public:
        Note(string nm, int octv, int len)
        {
            name = nm;
            octave = octv;
            length = len;
        }  
        ~Note()
        {
            cout << "Note: " << name << ", octave: " << octave << ", length: 1/"
            << length << endl;
        }
        Note operator + (int n)
        {
            int coord = get_coord() + n;
            Note res(coord,length);
            return res;
        }
        Note operator - (int n)
        {
            int coord = get_coord() - n;
            Note res(coord,length);
            return res;
        }
        Note operator * (int n)
        {
            if (octave + n > 8 || octave + n < 0) {
                cout << "The new octave is out of bounds! No changes were applied." << endl;
                return (*this);
            }
            Note res(name,octave + n,length);
            return res;
        }
        Note operator / (int n)
        {
            if (octave - n > 8 || octave - n < 0) {
                cout << "The new octave is out of bounds! No changes were applied." << endl;
                return (*this);
            }
            Note res(name,octave - n,length);
            return res;
        }
        Note operator ++ ()
        {
            return (*this) + 1;
        } 
        Note operator ++ (int)
        {
            return ++(*this);
        }  
        Note operator -- ()
        {
            return (*this) - 1;
        }
        Note operator -- (int)
        {
            return --(*this);
        }
        bool operator < (Note other)
        {
            return get_coord() < other.get_coord();
        }
        bool operator > (Note other)
        {
            return get_coord() > other.get_coord();
        }
        bool operator <= (Note other)
        {
            return get_coord() <= other.get_coord();
        }
        bool operator >= (Note other)
        {
            return get_coord() >= other.get_coord();
        }
        bool operator == (Note other)
        {
            return get_coord() == other.get_coord();
        }
        bool operator != (Note other)
        {
            return get_coord() != other.get_coord();
        }
        void print()
        {
            cout << "Note: " << name << ", octave: " << octave << ", length: 1/"
            << length << endl;
            return; 
        }
        friend ostream& operator << (ostream& stream, Note note)
        {
            stream << "Note: " << note.name << ", octave: " << note.octave << ", length: 1/"
            << note.length << endl;
            return stream; 
        }
};

class Interval
{
    private:
        string name;
        vector<Note> notes;
    public:
        Interval(vector<Note> nts)
        {
            sort(nts.begin(),nts.end());
            notes = nts;
            if (nts[0].get_octave(nts[0].get_coord()) != nts[1].get_octave(nts[1].get_coord())) {
                cout << "Notes are from different octaves - unknown interval!" << endl;
                name = "Unknown";
                return;
            } else if (intervals.count(nts[1].get_coord() - nts[0].get_coord()) == 0) {
                cout << "Unknown interval!" << endl;
                name = "Unknown";
                return;
            }
            name = intervals[nts[1].get_coord() - nts[0].get_coord()];
        }
        void print()
        {
            cout << "Interval " << name << ':' << " note 1: " << notes[0] << ", note 2: "
            << notes[1] << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Interval intrvl)
        {
            stream << "Interval " << intrvl.name << ':' << " note 1: " << intrvl.notes[0] << ", note 2: "
            << intrvl.notes[1] << endl;
            return stream;
        }
};

class Chord 
{
    friend class Melody;
    private:
        string name;
        vector<Note> notes;
        int length;
    public:
        Chord(vector<Note> nts, int len)
        {
            sort(nts.begin(),nts.end());
            notes = nts;
            length = len;
            if (!(nts[0].get_octave(nts[0].get_coord()) == nts[1].get_octave(nts[1].get_coord()) && 
            nts[1].get_octave(nts[1].get_coord()) == nts[2].get_octave(nts[2].get_coord()))) {
                cout << "Notes are from different octaves - unknown chord!" << endl;
                name = "Unknown";
                return;
            } else if (chords.count(make_pair(nts[1].get_coord() - nts[0].get_coord(), 
            nts[2].get_coord() - nts[0].get_coord())) == 0) {
                cout << "Unknown chord!" << endl;
                name = "Unknown";
                return;
            }
            name = chords[make_pair(nts[1].get_coord() - nts[0].get_coord(), 
            nts[2].get_coord() - nts[0].get_coord())];
        }
        ~Chord()
        {
            cout << "Chord " << name << ':' << endl << "note 1 - " << notes[0] << "note 2 - "
            << notes[1] << "note 3 - " << notes[2] << endl;
        }
        void print()
        {
            cout << "Chord " << name << ':' << endl << "note 1 - " << notes[0] << "note 2 - "
            << notes[1] << "note 3 - " << notes[2] << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Chord chord)
        {
            stream << "Chord " << chord.name << ':' << " note 1: " << chord.notes[0] << ", note 2: "
            << chord.notes[1] << ", note 3: " << chord.notes[2] << endl;
            return stream;
        }
};

class Melody
{
    private:
        vector<Note*> notes;
        vector<Chord*> chords;
    public:
        Melody(vector<Note*> nts, vector<Chord*> chrds)
        {
            for (int i=0;i<max(nts.size(),chrds.size());i++) {
                if (nts[i] == NULL) {
                    chords.push_back(chrds[i]);
                    notes.push_back(NULL);
                    continue;
                }
                chords.push_back(NULL);
                notes.push_back(nts[i]);
            }
        }
        void push_note_back(Note note)
        {
            notes.push_back(&note);
            chords.push_back(NULL);
            return;
        }
        void push_chord_back(Chord chord)
        {
            chords.push_back(&chord);
            notes.push_back(NULL);
            return;
        }
        void pop_element_back()
        {
            if (notes.empty()) {
                cout << "Melody doesn't contain elements" << endl;
                return;
            }
            notes.pop_back();
            chords.pop_back();
            return;
        }
        void play()
        {
            for (int i=0;i<notes.size();i++) {
                if (notes[i]) notes[i]->print();
                else chords[i]->print();
            }
        }
        void transpose(int n)
        {
            for (int i=0;i<notes.size();i++) {
                if (notes[i]) 
                    *(notes[i]) = *(notes[i]) + n;
                else {
                    for (int j=0;j<3;j++) {
                        chords[i]->notes[j] = chords[i]->notes[j] + n;
                    }
                }
            }
        }
};

int main()
{
    vector<Note> notes
    {
        Note("E",1,2),
        Note("C",1,3),
        Note("G#",1,4)
    };
    Chord ch1(notes,2);
    // ch1.print();
}