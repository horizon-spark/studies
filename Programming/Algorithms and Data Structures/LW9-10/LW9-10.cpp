#include <iostream>

using namespace std;

class Node
{
    friend class Tree;
    public:
        int iData;
        Node* leftChild;
        Node* rightChild;

        Node()
        {
            iData = 0;
            leftChild = NULL;
            rightChild = NULL;
        }
        void diplayNode()
        {
            cout << '(' << iData << ", ";
            if (leftChild)
                cout << leftChild->iData;
            else 
                cout << "null";
            if (rightChild)
                cout << ", " << rightChild->iData << ')';
            else 
                cout << ", null)";
        }
};

class Tree
{
    public:
        Node* root; 

        Tree()
        {
            root = NULL;
        }
        Node* find(int key)
        {
            Node* current = root;
            while (current->iData != key) {
                if (key < current->iData)
                    current = current->leftChild;
                else 
                    current = current->rightChild;
                if (current == NULL)
                    return NULL;
            }
            return current;
        }
        void insert(int id)
        {
            Node* newNode = new Node();
            newNode->iData = id;
            if (root == NULL)
                root = newNode;
            else {
                Node* current = root;
                Node* parent;
                while (1) {
                    parent = current;
                    if (id < current->iData) {
                        current = current->leftChild;
                        if (current = NULL) {
                            parent->leftChild = newNode;
                            root->diplayNode();
                            return;
                        }
                    } else {
                        current = current->rightChild;
                        if (current = NULL) {
                            parent->rightChild = newNode;
                            return;
                        }
                    }
                }
            }
        }
};

int main()
{
    Tree* theTree = new Tree();
    int key;
    theTree->insert(50);
    theTree->insert(25);
    theTree->insert(75);
    theTree->insert(12);
    theTree->insert(37);
    theTree->insert(43);
    theTree->insert(30);
    theTree->insert(33);
    theTree->insert(87);
    theTree->insert(93);
    theTree->insert(97);
    cout << "Insert a key: ";
    cin >> key;
    Node* found = theTree->find(key);
    if (found) 
        found->diplayNode();
    else 
        cout << "The key is not found" << endl;
}   