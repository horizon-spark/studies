#include <iostream>
#include <cmath>
using namespace std;

class Piece
{
    protected:
        char x;
        int y;
        string side;
        string name;
    public:
        Piece(char X, int Y, string Side)
        {
            this->x = X;
            this->y = Y;
            this->side = Side;
            this->name = "NO_NAME";
        }
        void print()
        {
            std::cout << "Piece name: " << name << "\nSide: " << side << "\nLocation: " << x << y << endl;
        }
        bool onBoard(char x, int y)
        {
            if (x > 'h' || x < 'a' || y > 8 || y < 1) return false;
            return true;
        }
        bool checkDiag(char destX, int destY) 
        {
            if (abs((int)(destX - x)) == abs(destY - y))
                return true;
            return false;
        }
        bool checkVert(char destX, int destY) 
        {
            if (x == destX || y == destY)
                return true;
            return false;
        }
        friend ostream& operator << (ostream& stream, const Piece& p)
        {
            stream << "Piece name: " << p.name << "\nSide: " << p.side << "\nLocation: " << p.x << p.y << endl;
        }
};

class Pawn : public Piece
{
    public: 
        using Piece :: onBoard;
        using Piece :: print;
        Pawn(char x, int y, string side) : Piece(x,y,side)
        {
            this->name = "pawn";
        }
        void travel(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Travel to " << destX << destY << " is ";
            if (this->side == "white") {
                if (this->x == destX && this->y + 1 == destY) {
                    // cout << "possible" << endl;
                    cout << 'X' << "  ";
                    return;
                }
            } else {
                if (this->x == destX && this->y - 1 == destY) { 
                    // cout << "possible" << endl;
                    cout << 'X' << "  ";
                    return;
                }
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
        void attack(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Attack of " << destX << destY << " is ";
            if (this->side == "white") {
                if ((this->x - 1 == destX || this->x + 1 == destX) && this->y + 1 == destY) {
                    // cout << "possible" << endl;
                    cout << 'X' << "  ";
                    return;
                } 
            } else {
                if ((this->x - 1 == destX || this->x + 1 == destX) && this->y - 1 == destY) {
                    // cout << "possible" << endl;
                    cout << 'X' << "  ";
                    return;
                }
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
};

class Bishop : public Piece
{
    public:
        using Piece :: onBoard;
        using Piece :: checkDiag;
        using Piece :: print;
        Bishop(char x, int y, string side) : Piece(x,y,side)
        {
            this->name = "bishop";
        }
        void travel(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Travel to " << destX << destY << " is "; 
            if (checkDiag(destX,destY)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
        void attack(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Attack of " << destX << destY << " is "; 
            if (checkDiag(destX,destY)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
};

class Castle : public Piece
{
    public:
        using Piece :: onBoard;
        using Piece :: checkVert;
        using Piece :: print;
        Castle(char x, int y, string side) : Piece(x,y,side) 
        {
            this->name = "castle";
        }
        void travel(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Travel to " << destX << destY << " is "; 
            if (checkVert(destX,destY)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
        void attack(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Attack of " << destX << destY << " is "; 
            if (checkVert(destX,destY)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
};

class Queen : public Piece
{
    public:
        using Piece :: onBoard;
        using Piece :: checkDiag;
        using Piece :: checkVert;
        using Piece :: print;
        Queen(char x, int y, string side) : Piece(x,y,side)
        {
            this->name = "queen";
        }
        void travel(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Travel to " << destX << destY << " is "; 
            if (checkDiag(destX,destY) || checkVert(destX,destY)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            } 
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
        void attack(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Attack of " << destX << destY << " is "; 
            if (checkDiag(destX,destY) || checkVert(destX,destY)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            }
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
};

class Knight : public Piece
{
    public: 
        using Piece :: onBoard;
        using Piece :: print;
        Knight(char x, int y, string side) : Piece(x,y,side) 
        {
            this->name = "knight";
        }
        void travel(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Travel to " << destX << destY << " is ";
            if ((abs((int)(destY - y)) + abs(destX - x) == 3) && destY != y && destX != x) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            } 
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
        void attack(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Attack of " << destX << destY << " is ";
            if ((abs((int)(destY - y)) + abs(destX - x) == 3) && destY != y && destX != x) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            } 
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
};

class King : public Piece
{
    public:
        using Piece :: onBoard;
        using Piece :: print;
        King(char x, int y, string side) : Piece(x,y,side)
        {
            this->name = "king";
        }
        void travel(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Travel to " << destX << destY << " is ";
            if (((abs((int)(destY - y)) + abs(destX - x) == 1) && (destX == x || destY == y)) || 
            ((abs((int)(destY - y)) + abs(destX - x) == 2) && destX != x && destY != y)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            } 
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
        void attack(char destX, int destY)
        {
            if (!onBoard(destX,destY)) {
                cout << "Cell " << destX << destY << " is not on the board" << endl;
                return;
            }
            if (this->x == destX && this->y == destY) {
                cout << 'O' << "  ";
                return;
            }
            // cout << "Attack of " << destX << destY << " is ";
            if (((abs((int)(destY - y)) + abs(destX - x) == 1) && (destX == x || destY == y)) || 
            ((abs((int)(destY - y)) + abs(destX - x) == 2) && destX != x && destY != y)) {
                // cout << "possible" << endl;
                cout << 'X' << "  ";
                return;
            } 
            // cout << "impossible" << endl;
            cout << '-' << "  ";
            return;
        }
};
void write_field()
{
    cout << "  ";
    for (char i = 'a'; i <= 'h'; i++) {
        cout << i << "  ";
    }
}
void test_pawn(char x, int y, string side)
{
    Pawn p(x,y,side);
    p.print();
    cout << endl << "Attack";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.attack(i,j);
        }
    }
    cout << endl;
    write_field();
    cout << endl << "Travel";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.travel(i,j);
        }
    }
    cout << endl;
    write_field();
    return;
}
void test_bishop(char x, int y, string side)
{
    Bishop p(x,y,side);
    p.print();
    cout << endl << "Attack";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.attack(i,j);
        }
    }
    cout << endl;
    write_field();
    cout << endl << "Travel";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.travel(i,j);
        }
    }
    cout << endl;
    write_field();
    return;
}
void test_castle(char x, int y, string side)
{
    Castle p(x,y,side);
    p.print();
    cout << endl << "Attack";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.attack(i,j);
        }
    }
    cout << endl;
    write_field();
    cout << endl << "Travel";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.travel(i,j);
        }
    }
    cout << endl;
    write_field();
    return;
}
void test_queen(char x, int y, string side)
{
    Queen p(x,y,side);
    p.print();
    cout << endl << "Attack";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.attack(i,j);
        }
    }
    cout << endl;
    write_field();
    cout << endl << "Travel";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.travel(i,j);
        }
    }
    cout << endl;
    write_field();
    return;
}
void test_knight(char x, int y, string side)
{
    Knight p(x,y,side);
    p.print();
    cout << endl << "Attack";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.attack(i,j);
        }
    }
    cout << endl;
    write_field();
    cout << endl << "Travel";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.travel(i,j);
        }
    }
    cout << endl;
    write_field();
    return;
}
void test_king(char x, int y, string side)
{
    King p(x,y,side);
    p.print();
    cout << endl << "Attack";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.attack(i,j);
        }
    }
    cout << endl;
    write_field();
    cout << endl << "Travel";
    for (int j = 8; j >= 1; j--) {
        cout << endl << j << ' ';
        for (char i = 'a'; i <= 'h'; i++) {
            p.travel(i,j);
        }
    }
    cout << endl;
    write_field();
    return;
}

int main()
{
    test_queen('a',1,"white");
}