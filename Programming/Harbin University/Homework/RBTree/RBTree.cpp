#include <iostream>

using namespace std;

// Цвет узла: RED (красный) или BLACK (чёрный)
enum Color { RED, BLACK };

// Структура узла красно-чёрного дерева
struct Node {
    int data;       // Значение узла
    Color color;    // Цвет узла
    Node *left;     // Левый потомок
    Node *right;    // Правый потомок
    Node *parent;   // Родительский узел

    // Конструктор узла
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node *root;     // Корень дерева
    Node *nil;      // Фиктивный лист (NIL-узел)

    // Левый поворот относительно узла x
    void leftRotate(Node *x) {
        Node *y = x->right;  // y - правый потомок x
        x->right = y->left;  // Перемещаем левое поддерево y в правое поддерево x
        
        if (y->left != nil) {
            y->left->parent = x;  // Обновляем родителя для перемещённого поддерева
        }
        
        y->parent = x->parent;  // Переносим родителя x на y
        
        // Обновляем ссылку родителя x на новый узел y
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        
        y->left = x;      // Делаем x левым потомком y
        x->parent = y;    // Обновляем родителя x
    }

    // Правый поворот относительно узла y
    void rightRotate(Node *y) {
        Node *x = y->left;   // x - левый потомок y
        y->left = x->right;  // Перемещаем правое поддерево x в левое поддерево y
        
        if (x->right != nil) {
            x->right->parent = y;  // Обновляем родителя для перемещённого поддерева
        }
        
        x->parent = y->parent;  // Переносим родителя y на x
        
        // Обновляем ссылку родителя y на новый узел x
        if (y->parent == nil) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        
        x->right = y;     // Делаем y правым потомком x
        y->parent = x;    // Обновляем родителя y
    }

    // Балансировка после вставки
    void fixInsert(Node *z) {
        // Пока родитель z красный (нарушение свойства 4)
        while (z->parent->color == RED) {
            // Если родитель - левый потомок деда
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right;  // Дядя z
                
                // Случай 1: дядя красный
                if (y->color == RED) {
                    z->parent->color = BLACK;      // Родитель -> чёрный
                    y->color = BLACK;             // Дядя -> чёрный
                    z->parent->parent->color = RED;  // Дед -> красный
                    z = z->parent->parent;        // Переходим к деду
                } else {
                    // Случай 2: дядя чёрный и z - правый потомок
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);  // Превращаем в случай 3
                    }
                    // Случай 3: дядя чёрный и z - левый потомок
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                // Симметричный случай, если родитель - правый потомок деда
                Node *y = z->parent->parent->left;  // Дядя z
                
                if (y->color == RED) {
                    // Случай 1
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    // Случай 2
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    // Случай 3
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;  // Свойство 2: корень всегда чёрный
    }

    // Замена поддерева u поддеревом v
    void transplant(Node *u, Node *v) {
        if (u->parent == nil) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // Поиск узла с минимальным значением в поддереве
    Node *minimum(Node *x) {
        while (x->left != nil) {
            x = x->left;
        }
        return x;
    }

    // Балансировка после удаления
    void fixDelete(Node *x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                // x - левый потомок 
                Node *w = x->parent->right;  // Брат x
                
                // Случай 1: брат красный
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                
                // Случай 2: оба потомка брата чёрные
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    // Случай 3: правый потомок брата чёрный
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    
                    // Случай 4: правый потомок брата красный
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                // Симметричный случай, если x - правый потомок
                Node *w = x->parent->left;
                
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // Вспомогательная функция для вывода дерева
    void printHelper(Node *root, string indent, bool last) {
        if (root != nil) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            } else {
                cout << "L----";
                indent += "|    ";
            }
            
            string sColor = (root->color == RED) ? "RED" : "BLACK";
            cout << root->data << "(" << sColor << ")" << endl;
            
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

public:
    // Конструктор
    RedBlackTree() {
        nil = new Node(0);
        nil->color = BLACK;
        root = nil;
    }

    // Вставка нового узла
    void insert(int data) {
        Node *z = new Node(data);
        Node *y = nil;
        Node *x = root;

        // Поиск места для вставки
        while (x != nil) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        
        z->parent = y;
        if (y == nil) {
            root = z;
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }
        
        z->left = nil;
        z->right = nil;
        z->color = RED;  // Новый узел всегда красный
        
        fixInsert(z);    // Балансировка
    }

    // Удаление узла
    void deleteNode(int data) {
        Node *z = root;
        // Поиск удаляемого узла
        while (z != nil) {
            if (z->data == data) {
                break;
            } else if (data < z->data) {
                z = z->left;
            } else {
                z = z->right;
            }
        }
        
        if (z == nil) {
            cout << "Node not found!" << endl;
            return;
        }

        Node *y = z;
        Color yOriginalColor = y->color;
        Node *x;

        if (z->left == nil) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        
        if (yOriginalColor == BLACK) {
            fixDelete(x);
        }
        
        delete z;
    }

    // Поиск значения в дереве
    bool search(int data) {
        Node *current = root;
        while (current != nil) {
            if (current->data == data) {
                return true;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    // Вывод дерева
    void printTree() {
        if (root != nil) {
            printHelper(root, "", true);
        } else {
            cout << "Tree is empty!" << endl;
        }
    }
};

void displayMenu()
{
	cout << "\nMenu: \n";
	cout << "1. Insert elements\n";
	cout << "2. Delete element\n";
	cout << "3. Search element\n";
	cout << "4. Show the tree\n";
	cout << "5. Exit\n";
	cout << "Choose action: ";
}

void clearInput()
{
	cin.clear();
}

void demoValues(RedBlackTree& tree) {
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    cout << "Added test values: 7, 3, 18, 10, 22, 8, 11, 26, 2, 6, 13\n";
}

int main() {
    RedBlackTree rbt;
	int choice, value;
	
	do {
		displayMenu();
		
		cin >> choice;
		switch(choice)
		{
            case 1:
                demoValues(rbt);
                break;
							
			case 2: 
 			cout << "Enter the values to delete: ";
            if(!(cin >> value)) {
                cout << "Input error! Please, enter number.\n";
                clearInput();
                break;
            }
            rbt.deleteNode(value);
            cout << "The value " << value << " is delete from the tree.\n";
            break;
                
            case 3:
                cout << "Enter the value to serach: ";
                if(!(cin >> value)) {
                    cout << "Input error! Please, enter number.\n";
                    clearInput();
                    break;
                }
                if(rbt.search(value))
                    cout << "The value " << value << " found in tree.\n";
                else
                    cout << "The value " << value << " not found in tree.\n";
                break;
                
            case 4:
                cout << "Tree contents: ";
                rbt.printTree();
                break;
                                
            case 5:
                cout << "Exit the program.\n";
                break;
                
			default:{
				cout << "Wrong choice. Please select from 1 to 5";
				clearInput();
				break;
			}
				
		}
	} while(choice != 5);
	
	return 0;
}