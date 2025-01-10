#include <iostream>
#include <vector>
#include <utility> 
#include <map>
using namespace std;

const vector<pair<string,int>> dishes{make_pair("Classic",200), make_pair("Spicy",210), make_pair("Cheesy",210),
make_pair("BBQ",210), make_pair("Vegetarian",110), make_pair("Freestylo",300)};

class Dish
{
    friend class Receipt;
    private:
        string name;
        int price;
    public:
        Dish()
        {
            name = dishes[0].first;
            price = dishes[0].second;
        }
        Dish(const pair<string,int>& dish)
        {
            name = dish.first;
            price = dish.second;
        }
        void print()
        {
            cout << name << " kebab, price: " << price;
        }
        friend ostream& operator << (ostream& stream, Dish dish)
        {
            stream << dish.name << " kebab, price: " << dish.price;
            return stream;
        }
        bool operator < (const Dish& other) const { // Сравнение, необходимое для использования map с классом Dish
            return name < other.name;  
        }
};

class Menu
{
    protected: 
        vector<Dish> menu;
    public:
        Menu() 
        {
            for (int i=0;i<dishes.size();i++) {
                Dish dish(dishes[i]);
                menu.push_back(dish);
            }
        }
        Menu(string mode)
        {
            if (mode == "custom" || mode == "Custom") {
                string name;
                int price, n;
                cout << "Insert a number of kebabs in menu: ";
                cin >> n;
                for (int i=0;i<n;i++) {
                    cout << "Insert a name of " << i+1 << " kebab: ";
                    cin >> name;
                    cout << "Insert a price of " << i+1 << " kebab: ";
                    cin >> price;
                    Dish dish(make_pair(name,price));
                    menu.push_back(dish);
                }
            } else {
                cout << "Default menu was created" << endl;
                for (int i=0;i<dishes.size();i++) {
                    Dish dish(dishes[i]);
                    menu.push_back(dish);
                }
            }
        }
        void print()
        {
            for (int i=0;i<menu.size();i++) {
                cout << i+1 << ')';
                menu[i].print();
                cout << endl;
            }
        }
        friend ostream& operator << (ostream& stream, Menu m)
        {
            for (int i=0;i<m.menu.size();i++) {
                stream << i+1 << ')' << (m.menu[i]) << endl;
            }
            return stream;
        }
};

class Receipt : public Menu
{
    private:
        map<Dish,int> quantities;
    public:
        Receipt() : Menu()
        {
            int n;
            for (int i=0;i<menu.size();i++) {
                cout << "Insert a quantity of " << menu[i].name << ": ";
                cin >> n;
                quantities[menu[i]] = n;
            }
        }
        Receipt(string mode) : Menu(mode)
        {
            int n;
            for (int i=0;i<menu.size();i++) {
                cout << "Insert a quantity of " << menu[i].name << ": ";
                cin >> n;
                quantities[menu[i]] = n;
            }
        }
        int count_total()
        {
            int res = 0;
            for (int i=0;i<menu.size();i++) {
                res += menu[i].price * quantities[menu[i]];
            }
            return res;
        }
        void print()
        {
            for (int i=0;i<menu.size();i++) {
                cout << i+1 << ')';
                menu[i].print();
                cout << ", quantity: " << quantities[menu[i]] << endl;
            }
        }
        friend ostream& operator << (ostream& stream, Receipt rec)
        {
            for (int i=0;i<rec.menu.size();i++) {
                cout << i+1 << ')' << rec.menu[i] << ", quantity: "
                << rec.quantities[rec.menu[i]] << endl;
            }
            return stream;
        }
        Receipt operator + (Receipt& other)
        {
            Receipt copy(*this);
            for (int i=0;i<other.menu.size();i++) {
                copy.quantities[other.menu[i]] += other.quantities[other.menu[i]];
            }
            return copy;
        }
        Receipt operator * (int n)
        {
            Receipt copy(*this);
            for (int i=0;i<menu.size();i++) {
                copy.quantities[copy.menu[i]] *= n;
            }
            return copy;
        }
        bool operator < (Receipt& other)
        {
            return (*this).count_total() < other.count_total();
        }
        bool operator > (Receipt& other)
        {
            return (*this).count_total() > other.count_total();
        }
        bool operator <= (Receipt& other)
        {
            return (*this).count_total() <= other.count_total();
        }
        bool operator >= (Receipt& other)
        {
            return (*this).count_total() >= other.count_total();
        }
        bool operator == (Receipt& other)
        {
            return (*this).count_total() == other.count_total();
        }
        bool operator != (Receipt& other)
        {
            return (*this).count_total() != other.count_total();
        }
};

int main()
{
    Receipt r1, r2, r3 = r1 + r2;
    cout << "Receipt 1: " << endl << r1;
    cout << "Receipt 2: " << endl << r2;
    cout << "Receipt 3: " << endl << r3;
    cout << "Total price: " << r3.count_total() << endl;
}