#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
    friend class Group;
    protected:
        string name;
        string surname;
        unsigned age;
    public:
        Person()
        {
            string buffs1, buffs2;
            unsigned buffu;
            cout << "Insert person's name: ";
            cin >> buffs1;
            cout << "Insert person's surname: ";
            cin >> buffs2;
            cout << "Insert person's age: ";
            cin >> buffu;
            name = buffs1;
            surname = buffs2;
            age = buffu;
        }
        Person(string nm, string srnm, int a)
        {
            name = nm;
            surname = srnm;
            age = a;
        }
        void print()
        {
            cout << "Name: " << name << endl << "Surname: " << surname << endl
            << "Age: " << age << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Person person)
        {
            stream << "Name: " << person.name << endl << "Surname: " << person.surname << endl
            << "Age: " << person.age << endl;
            return stream;
        }
};

class Student : public Person
{
    private:
        string group;
        unsigned year;
    public:
        Student() : Person()
        {
            string buffs;
            unsigned buffu;
            cout << "Insert student's group: ";
            cin >> buffs;
            cout << "Insert student's year: ";
            cin >> buffu;
            group = buffs;
            year = buffu;
        }
        Student(string gr, unsigned yr) : Person()
        {
            group = gr;
            year = yr;
        }
        Student(string nm, string srnm, unsigned a, string gr, unsigned yr) : Person(nm,srnm,a)
        {
            group = gr;
            year = yr;
        }
        void print()
        {
            cout << "   Name: " << name << endl << "   Surname: " << surname << endl
            << "   Age: " << age << endl << "   Group: " << group << endl 
            << "   Year: " << year << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Student student)
        {
            cout << "   Name: " << student.name << endl << "   Surname: " << student.surname << endl
            << "   Age: " << student.age << endl << "   Group: " << student.group << endl 
            << "   Year: " << student.year << endl;
            return stream; 
        }
        bool operator < (const Student& other) const {
            return name < other.name;
        }
};

class Group 
{
    friend class Institute;
    private:
        string groupName;
        unsigned year;
        vector<Student> students;
    public:
        Group()
        { 
            string grnm;
            unsigned yr,n;
            cout << "Insert group's name: ";
            cin >> grnm;
            cout << "Insert group's year: ";
            cin >> yr;
            cout << "Insert a number of student: ";
            cin >> n;
            for (int i=0;i<n;i++) {
                cout << i+1 << " student:" << endl;
                Student student(grnm,yr);
                students.push_back(student);
            }
            sort(students.begin(),students.end());
            groupName = grnm;
            year = yr;
        }
        Group(vector<Person>& persons, string grnm, unsigned yr)
        {
            for (int i=0;i<persons.size();i++) {
                Student student(persons[i].name,persons[i].surname,persons[i].age,grnm,yr);
                students.push_back(student);
            }
            sort(students.begin(),students.end());
            groupName = grnm;
            year = yr;
        }
        void add_student(Person person)
        {
            Student student(person.name,person.surname,person.age,groupName,year);
            students.push_back(student);
            sort(students.begin(),students.end());
            return;
        }
        void delete_student(Person person)
        {
            for (int i=0;i<students.size();i++) {
                if (students[i].name == person.name && students[i].surname == person.surname
                && students[i].age == person.age) {
                    students.erase(students.begin() + i);
                    cout << "Student " << person.name << ' ' << person.surname
                    << " is deleted successfully" << endl;
                    return;
                }
            }
            cout << "Student is not found!" << endl;
            return;
        }
        void print()
        {
            cout << "\tGroup: " << groupName << " Year: " << year << endl;
            for (int i=0;i<students.size();i++) {
                cout << "Student " << i+1 << ':' << endl;
                students[i].print();
            }
            return;
        }
        friend ostream& operator << (ostream& stream, Group group)
        {
            stream << "\tGroup: " << group.groupName << " Year: " << group.year << endl;
            for (int i=0;i<group.students.size();i++) {
                stream << "Student " << i+1 << ':' << endl;
                stream << group.students[i];
            }
            return stream;
        }
        bool operator < (const Group& other) const {
            return groupName < other.groupName;
        }
};

class Institute
{
    friend class University;
    private:
        string instName;
        vector<Group> groups;
    public:
        Institute()
        {
            string instnm;
            unsigned n;
            cout << "Insert institute's name: ";
            cin >> instnm;
            cout << "Insert a number of groups: ";
            cin >> n;
            for (int i=0;i<n;i++) {
                cout << i+1 << " group:" << endl;
                Group group;
                groups.push_back(group);
            }
            sort(groups.begin(),groups.end());
            instName = instnm;
        }
        Institute(vector<Group>& grps, string instnm)
        {
            for (int i=0;i<grps.size();i++) {
                groups.push_back(grps[i]);
            }
            sort(groups.begin(),groups.end());
            instName = instnm;
        }
        void add_group(Group group)
        {
            groups.push_back(group);
            sort(groups.begin(),groups.end());
            return;
        }
        void delete_group(string name)
        {
            for (int i=0;i<groups.size();i++) {
                if (groups[i].groupName == name) {
                    groups.erase(groups.begin() + i);
                    cout << "Group " << name << " is deleted successfully" << endl;
                    return;
                }
            }
            cout << "Group is not found" << endl;
            return;
        }
        void print()
        {
            cout << "\t\tInstitute: " << instName << endl;
            for (int i=0;i<groups.size();i++) {
                groups[i].print();
            }
            return;
        }
        friend ostream& operator << (ostream& stream, Institute inst)
        {
            stream << "\t\tInstitute: " << inst.instName << endl;
            for (int i=0;i<inst.groups.size();i++) {
                stream << inst.groups[i];
            }
            return stream;
        }
        bool operator < (const Institute& other) const {
            return instName < other.instName; 
        }
};

class University
{
    private:
        string univName;
        vector<Institute> institutes;
    public:
        University()
        {
            string unvstnm;
            unsigned n;
            cout << "Insert univercity's name: ";
            cin >> unvstnm;
            cout << "Insert a number of institutes: ";
            cin >> n;
            for (int i=0;i<n;i++) {
                cout << i+1 << " institute:" << endl;
                Institute institute;
                institutes.push_back(institute);
            }
            sort(institutes.begin(),institutes.end());
            univName = unvstnm;
        }
        University(vector<Institute>& instts, string unvstnm)
        {
            for (int i=0;i<instts.size();i++) {
                institutes.push_back(instts[i]);
            }
            sort(institutes.begin(),institutes.end());
            univName = unvstnm;
        }
        void add_institute(Institute institute)
        {
            institutes.push_back(institute);
            sort(institutes.begin(),institutes.end());
            return;
        }
        void delete_institute(string name)
        {
            for (int i=0;i<institutes.size();i++) {
                if (institutes[i].instName == name) {
                    institutes.erase(institutes.begin() + i);
                    cout << "Institute " << name << " is deleted successfully" << endl;
                    return;
                }
            }
            cout << "Institute is not found" << endl;
            return;
        }
        void print()
        {
            cout << "\t\t\tUniversity: " << univName << endl;
            for (int i=0;i<institutes.size();i++) {
                institutes[i].print();
            }
            return;
        }
        friend ostream& operator << (ostream& stream, University univ)
        {
            stream << "\t\t\tUniversity: " << univ.univName << endl;
            for (int i=0;i<univ.institutes.size();i++) {
                stream << univ.institutes[i];
            }
            return stream; 
        }
};

int main()
{
    vector<Person> persons1 {
        Person("Egor", "Kovalev", 19), 
        Person("Evgeniy", "Bodrov", 19),
        Person("Artem", "Smirnov", 19),
        Person ("Dmitry", "Kadarmetov", 20)
    };
    vector<Person> persons2 {
        Person("Alice", "Meshkova", 19),
        Person("Matvey", "Kuklin", 22),
        Person("Michail", "Talalaev", 19),
        Person("Dmitry", "Kornilov", 19)  
    };
    vector<Person> persons3 {
        Person("Ivan", "Lebedko", 20),
        Person("Vladislav", "Kalugin", 20),
        Person("Alina", "Babkina", 20),
        Person("Alexander", "Kvasnikov", 20)
    };
    vector<Group> groups1 {
        Group(persons1, "BICT-WA-23", 2),
        Group(persons2, "BICT-VTD-23", 2)
    };
    vector<Group> group2 {
        Group(persons3, "Bld-b-22", 3)
    };
    vector<Institute> institutes {
        Institute(groups1, "IISDT"),
        Institute(group2, "IAAT")
    };
    University MAU(institutes, "MAU");
    cout << MAU;

}