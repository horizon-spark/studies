#include <iostream>
#include <ctime>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const vector<string> names{"2","3","4","5","6","7","8","9","10","jack","queen","king","ace"};
const vector<string> suits{"hearts","diamonds","clubs","spades"};

class Deck
{
    private:
        vector<pair<string,string>> cards;
        int random(int start, int end)
        {
            srand(time(0));
            int x = rand() % (end - start + 1) + start;
            return x;
        }
    public:
        Deck()
        {
            pair<string,string> buff;
            for (int i=4;i<names.size();i++) {
                for (int j=0;j<suits.size();j++) {
                    buff.first = names[i];
                    buff.second = suits[j];
                    cards.push_back(buff);
                }
            }
        }
        Deck(int n) 
        {
            switch(n)
            {
                case 36:
                {
                    pair<string,string> buff;
                    for (int i=4;i<names.size();i++) {
                        for (int j=0;j<suits.size();j++) {
                            buff.first = names[i];
                            buff.second = suits[j];
                            cards.push_back(buff);
                        }
                    }
                    break;
                }
                case 52:
                {
                    pair<string,string> buff;
                    for (int i=0;i<names.size();i++) {
                        for (int j=0;j<suits.size();j++) {
                            buff.first = names[i];
                            buff.second = suits[j];
                            cards.push_back(buff);
                        }
                    }
                    break;
                }
                case 54:
                {
                    pair<string,string> buff;
                    for (int i=0;i<names.size();i++) {
                        for (int j=0;j<suits.size();j++) {
                            buff.first = names[i];
                            buff.second = suits[j];
                            cards.push_back(buff);
                        }
                    }
                    cards.push_back(make_pair("Joker","Red"));
                    cards.push_back(make_pair("Joker","Black"));
                    break;
                }
                default:
                {
                    pair<string,string> buff;
                    for (int i=4;i<names.size();i++) {
                        for (int j=0;j<suits.size();j++) {
                            buff.first = names[i];
                            buff.second = suits[j];
                            cards.push_back(buff);
                        }
                    }
                    cout << "Error! It's only possible to create decks with 36, 52 or 54 cards" << endl;
                    cout << "A deck with 36 was created" << endl;
                }
            }
        }
        void Fisher_Yates()
        {
            int j;
            for (int i=cards.size()-1;i>=0;i--) {
                j = (*this).random(0,i);
                iter_swap(cards.begin() + i, cards.begin() + j);
            }
            return;
        }
        void Sattolo()
        {
            int j;
            for (int i=cards.size()-1;i>0;i--) {
                j = (*this).random(0,i-1);
                iter_swap(cards.begin() + i, cards.begin() + j);
            }
        }
        void find(string name, string suit)
        {
            for (int i=0;i<cards.size();i++) {
                if (cards[i].first == name && cards[i].second == suit) {
                    cout << "Card " << name << ':' << suit << " is found!" << endl;
                    cout << "Location: " << i+1 << " from the top" << endl;
                    return;
                }
            }
            cout << "Card " << name << ':' << suit << " is not found" << endl;
            return;
        }
        pair<string,string> get_top()
        {
            pair<string,string> res;
            res.first = cards[0].first;
            res.second = cards[0].second;
            cards.erase(cards.begin());
            return res;
        }
        pair<string,string> get_bottom()
        {
            pair<string,string> res;
            int n = cards.size() - 1;
            res.first = cards[n].first;
            res.second = cards[n].second;
            cards.erase(cards.end());
            return res;
        }
        pair<string,string> get_middle()
        {
            pair<string,string> res;
            int n = cards.size() - 1;
            res.first = cards[n/2].first;
            res.second = cards[n/2].second;
            cards.erase(cards.begin() + n/2);
            return res;    
        }
        void print()
        {
            for (int i=0;i<cards.size();i++) {
                cout << i+1 << ' ' << cards[i].first << ':' << cards[i].second << endl;
            }
            return;
        }
        friend ostream& operator << (ostream& stream, Deck& deck)
        {
            for (int i=0;i<deck.cards.size();i++) {
                cout << i+1 << ' ' << deck.cards[i].first << ':' << deck.cards[i].second << endl;
            }
            return stream;
        }
};

int main()
{
    Deck d1;
    d1.print();
    pair<string,string> p = d1.get_middle();
    cout << p.first << ':' << p.second << endl;
    d1.print();

}