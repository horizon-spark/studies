#include <iostream>
#include <vector>

using namespace std;

class Engine
{
    friend class Auto;
    private:
        bool state;
    public:
        Engine()
        {
            state = false;
        }
};

class Door
{
    friend class Auto;
    private:
        bool state, lock;
    public:
        Door()
        {
            state = false;
            lock = false;
        }
};

class Brake                                                                                    
{
    friend class Auto;
    private:
        bool state;
    public:
        Brake()
        {
            state = false;
        }
};

class Auto
{
    private:
        string brand;
        string model;
        Engine engine;
        vector<Door> doors = vector<Door>(5);
        Brake brake;
    public:
        Auto()
        {
            string br,mdl;
            cout << "Insert auto's brand: ";
            cin >> br;
            cout << "Insert auto's model: ";
            cin >> mdl; 
            brand = br;
            model = mdl;
        }
        void print()
        {
            cout << "Auto's brand: " << brand << endl 
            << "Auto's model: " << model << endl;
            return;
        }
        void start_engine()
        {
            if (!engine.state) {
                engine.state = true;
                cout << "Engine is now running" << endl;
            } else {
                cout << "Engine is alredy running" << endl;
            }
            return;
        }
        void stop_engine()
        {
            if (engine.state) {
                engine.state = false;
                cout << "Engine is now still" << endl;
            } else {
                cout << "Engine is already still" << endl;
            }
            return;
        }
        void check_engine()
        {
            if (engine.state)
                cout << "Engine is on" << endl;
            else 
                cout << "Engine is off" << endl; 
            return;
        }
        void open_door()
        {
            int n;
            cout << "Insert a number of a door to open (0-4): ";
            cin >> n;
            if (n > 4 || n < 0) {
                cout << "Incorrect input of a door's number!" << endl;
                return;
            }
            if (!doors[n].state && !doors[n].lock) {
                doors[n].state = true;
                cout << "Door " << n << " is now opened" << endl;
            } else if (doors[n].lock) {
                cout << "Door " << n << " is locked - unable to open" << endl;
            } else if (doors[n].state) {
                cout << "Door " << n << " is already opened" << endl;
            }
            return;
        }
        void close_door()
        {
            int n;
            cout << "Insert a number of a door to close (0-4): ";
            cin >> n;
            if (n > 4 || n < 0) {
                cout << "Incorrect input of a door's number!" << endl;
                return;
            }
            if (doors[n].state) {
                doors[n].state = false;
                cout << "Door " << n << " is now closed" << endl;
            } else {
                cout << "Door " << n << " is already closed" << endl;
            }
            return;
        }
        void lock_door()
        {
            int n;
            cout << "Insert a number of a door to lock (0-4): ";
            cin >> n;
            if (n > 4 || n < 0) {
                cout << "Incorrect input of a door's number!" << endl;
                return;
            } 
            if (!doors[n].state && !doors[n].lock) {
                doors[n].lock = true;
                cout << "Door " << n << " is now locked" << endl;
            } else if (doors[n].state) {
                cout << "Door is opened - unable to lock" << endl;
            } else {
                cout << "Door is already locked" << endl;
            }
            return;
        }
        void check_doors()
        {
            cout << "Checking doors: " << endl;
            for (int i=0;i<5;i++) {
                if (doors[i].state)
                    cout << "Door " << i << " is opened" << endl;
                else {
                    cout << "Door " << i << " is closed";
                    if (doors[i].lock) 
                        cout << " and locked" << endl;
                    else 
                        cout << " and unlocked" << endl;
                }
            }
            return;
        }
        void apply_parking_brake()
        {
            if (!brake.state) {
                brake.state = true;
                cout << "Parking brake is set" << endl;
            } else {
                cout << "Parking brake is already set" << endl;
            }
            return;
        }
        void remove_parking_brake()
        {
            if (brake.state) {
                brake.state = false;
                cout << "Parking brake is removed" << endl;
            } else {
                cout << "Parking brake is already removed" << endl;
            }
            return;
        }
        void check_parking_brake()
        {
            if (brake.state) {
                cout << "Parking brake is set" << endl;
            } else {
                cout << "Parking brake is removed" << endl;
            }
            return;
        }
};

int main()
{
    Auto a;
    string buff;
    int cond1, cond2;
    while(1) {
        cout << endl << "What do you want to do?" << endl
        << "1 - print information about the car" << endl
        << "2 - choose engine action" << endl
        << "3 - choose doors action" << endl
        << "4 - choose parking brake action" << endl
        << "0 or any other key - exit the program" << endl << endl;
        cin >> cond1;
        if (cond1 == 1) {
            a.print();
        } else if (cond1 == 2) {
            while(1) {
                cout << endl << "What do you want to do?" << endl
                << "1 - check engine's status" << endl
                << "2 - start engine" << endl
                << "3 - stop engine" << endl
                << "0 or any other key - go back" << endl << endl;
                cin >> cond2;
                if (cond2 == 1) {
                    a.check_engine();
                } else if (cond2 == 2) {
                    a.start_engine();
                } else if (cond2 == 3) {
                    a.stop_engine();
                } else {
                    break;
                }
                cout << "Enter anything to continue" << endl;
                cin >> buff;
                printf("\e[1;1H\e[2J");
            }
        } else if (cond1 == 3) {
            while(1) {
                cout << endl << "What do you want to do?" << endl
                << "1 - check doors' status" << endl
                << "2 - open a door" << endl
                << "3 - close a door" << endl
                << "4 - lock a door" << endl 
                << "0 or any other key - go back" << endl << endl;
                cin >> cond2;
                if (cond2 == 1) {
                    a.check_doors();
                } else if (cond2 == 2) {
                    a.open_door();
                } else if (cond2 == 3) {
                    a.close_door();
                } else if (cond2 == 4) {
                    a.lock_door();
                } else {
                    break;
                }
                cout << "Enter anything to continue" << endl;
                cin >> buff;
                printf("\e[1;1H\e[2J");
            }
        } else if (cond1 == 4) {
            while(1) {
                cout << endl << "What do you want to do?" << endl
                << "1 - check parking brake's status" << endl
                << "2 - set parking brake" << endl
                << "3 - remove parking brake" << endl
                << "0 or any other key - go back" << endl << endl;
                cin >> cond2;
                if (cond2 == 1) {
                    a.check_parking_brake();
                } else if (cond2 == 2) {
                    a.apply_parking_brake();
                } else if (cond2 == 3) {
                    a.remove_parking_brake();
                } else {
                    break;
                }
                cout << "Enter anything to continue" << endl;
                cin >> buff;
                printf("\e[1;1H\e[2J");
            }
        } else {
            break;
        }
        cout << "Enter anything to continue" << endl;
        cin >> buff;
        printf("\e[1;1H\e[2J");
    }
}