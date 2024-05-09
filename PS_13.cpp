
// Implement all the functions of a dictionary (ADT) using open hashing technique: separate
// chaining using linked list Data: Set of (key, value) pairs, Keys are mapped to values, Keys
// must be comparable, and Keys must be unique. Standard Operations: Insert (key, value),
// Find(key), Delete(key). Use hash function as H(x) = (3x+5) %10


#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int k, int v) {
        this->key = k;
        this->value = v;
        next = nullptr;
    }
};

class LinkList {
public:
    Node* root;

    LinkList() {
        root = nullptr;
    }

    void Insert(int key , int value) {
        if (root == nullptr) {
            root = new Node(key, value);
            return;
        }

        Node* temp = root;
        Node* prev = nullptr;

        while (temp != nullptr && temp->key < key) {
            prev = temp;
            temp = temp->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = temp;

        if (prev == nullptr) {
            root = newNode; 
        } else {
            prev->next = newNode;
        }
    }

    Node* Search(int key) {
        Node* temp = root;

        while (temp != nullptr) {
            if (temp->key == key) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void Delete(int x) {
        if (root == nullptr) {
            cout << "The Root is empty" << endl;
            return;
        }

        Node* temp = root;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == x) {
                if (prev == nullptr) {
                    root = temp->next; 
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "The Node " << x << " has been deleted successfully" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Node Not found for deletion" << endl;
    }
};

class Hashing {
public:
    LinkList H[10];

    int hashing(int key) {
        return ((3*key) + 5) % 10;
    }

    void Insert(int k, int v) {
        int index = hashing(k);
        H[index].Insert(k, v);
    }

    void Delete(int k) {
        int index = hashing(k);
        H[index].Delete(k);
    }

    Node* Search(int k) {
        int index = hashing(k);
        return H[index].Search(k);
    }
};

int main() {
    Hashing h;

    h.Insert(10, 1234);
    h.Insert(22, 2345);
    h.Insert(12,3456);
    h.Insert(7, 4567);
    h.Delete(12);

    // Search for an element
    Node* temp = h.Search(22);
    if (temp != nullptr) {
        cout << "Found: " << temp->key << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}