#include <iostream>

using namespace std;

class Node
{
    friend class Tree;
    public:
        int iData;
        Node* leftChild;
        Node* rightChild;
        Node* parent;

        Node()
        {
            iData = 0;
            leftChild = NULL;
            rightChild = NULL;
            parent = NULL;
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
        Node* findNode(int key)
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
        Node* findNextNode(Node* current) 
        {
            Node* parent;
            while (current) {
                parent = current;
                current = current->leftChild;
            }
            return parent;
        }
        void insertNode(int id)
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
                        if (current == NULL) {
                            parent->leftChild = newNode;
                            parent->leftChild->parent = parent;
                            return;
                        }
                    } else {
                        current = current->rightChild;
                        if (current == NULL) {
                            parent->rightChild = newNode;
                            parent->rightChild->parent = parent;
                            return;
                        }
                    }
                }
            }
        }
        void deleteNode(int id)
        {   
            if (!root) {
                cout << "The tree is empty!" << endl;
                return;
            } 
            Node* nodeToDelete = findNode(id);
            if (!nodeToDelete) {
                cout << "The node with id = " << id << " doesn't exist!" << endl;
                return;
            }
            if (!(nodeToDelete->leftChild) && !(nodeToDelete->rightChild)) { // Если у удаляемого элемента нет детей
                if (!(nodeToDelete->parent)) {
                    delete(nodeToDelete);
                } else if (nodeToDelete->iData > nodeToDelete->parent->iData) { // Если удаляемый элемент - правый сын (ключ больше родительского)
                    nodeToDelete->parent->rightChild = NULL;
                    delete(nodeToDelete);
                } else {                                                    // Если удаляемый элемент - левый сын
                    nodeToDelete->parent->leftChild = NULL;
                    delete(nodeToDelete);
                }
            } else if (!(nodeToDelete->leftChild) && nodeToDelete->rightChild) { // Если у удаляемого элемента есть только правый сын
                if (!nodeToDelete->parent) {
                    root = nodeToDelete->rightChild;
                } else if (nodeToDelete->iData > nodeToDelete->parent->iData) {
                    nodeToDelete->parent->rightChild = nodeToDelete->rightChild;
                } else {
                    nodeToDelete->parent->leftChild = nodeToDelete->rightChild;
                }
                nodeToDelete->rightChild->parent = nodeToDelete->parent;
                delete(nodeToDelete);
            } else if (nodeToDelete->leftChild && !(nodeToDelete->rightChild)) { // Если у удаляемого элемента есть только левый сын
                if (!nodeToDelete->parent) {
                    root = nodeToDelete->leftChild;
                } else if (nodeToDelete->iData > nodeToDelete->parent->iData) {
                    nodeToDelete->parent->rightChild = nodeToDelete->leftChild;
                } else {
                    nodeToDelete->parent->leftChild = nodeToDelete->leftChild;
                }
                nodeToDelete->leftChild->parent = nodeToDelete->parent;
                delete(nodeToDelete);
            } else {                                                           // Если у удаляемого элемента есть и левый, и правый сыновья
                Node* nextNode = findNextNode(nodeToDelete->rightChild);
                if (nextNode->parent != nodeToDelete) {                     // Если левое поддерево правого сына удаляемого элемента не пустое
                    if (nextNode->rightChild) {                             // Если у найденного минимального элемента в правом поддереве есть правый сын (его нельзя просто удалить)
                        nextNode->parent->leftChild = nextNode->rightChild;
                        nextNode->rightChild->parent = nextNode->parent;
                    } else {
                        nextNode->parent->leftChild = NULL;
                    }                              
                    nextNode->rightChild = nodeToDelete->rightChild;
                    nodeToDelete->rightChild->parent = nextNode;
                } 
                nextNode->leftChild = nodeToDelete->leftChild;
                if (nodeToDelete->parent) {                            // Если удаляем не корень
                    if (nodeToDelete->iData > nodeToDelete->parent->iData) {
                        nodeToDelete->parent->rightChild = nextNode;
                    } else {
                        nodeToDelete->parent->leftChild = nextNode;
                    }
                    nextNode->parent = nodeToDelete->parent;
                } else {
                    nextNode->parent = NULL;
                    root = nextNode;
                }
                nodeToDelete->leftChild->parent = nextNode;
                delete(nodeToDelete);
            }

        }
        void displayTree(Node* root)
        {
            if (root->leftChild) {
                displayTree(root->leftChild);
            }
            root->diplayNode();
            if (root->rightChild) {
                displayTree(root->rightChild);
            }
            return;
        }
};

int main()
{
    Tree* theTree = new Tree();
    int key;

    theTree->insertNode(100);
    theTree->insertNode(110);
    theTree->insertNode(50);
    theTree->insertNode(12);
    theTree->insertNode(87);
    theTree->insertNode(137);
    theTree->insertNode(104);
    theTree->insertNode(105);
    theTree->insertNode(102);

    theTree->displayTree(theTree->root);
    cout << endl;
    theTree->deleteNode(100);
    
    theTree->displayTree(theTree->root);

    cout << "\ninsert a key: ";
    cin >> key;
    Node* found = theTree->findNode(key);
    if (found) 
        found->diplayNode();
    else 
        cout << "The key is not found" << endl;
}   