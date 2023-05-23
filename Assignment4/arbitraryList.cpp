#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

struct Node{ 

    int data; //struct for the LL. This is what the 'node' contains, integer data
    Node *next; //pointer to the 'next' node
};

class linkedList {
public:
    Node *head;

    linkedList() {
        head = nullptr;
    }

    void add(int data, int position) {
        Node *newNode = new Node;
        newNode->data = data;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Not enough positions" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    int remove(int position) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return -1;
        }

        Node *temp;
        int removedValue;

        if (position == 0) {
            temp = head;
            head = head->next;
        } else {
            Node *current = head;
            int currentPosition = 0;

            while (current->next != nullptr && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }

            if (current->next == nullptr || currentPosition != position - 1) {
                cout << "Invalid position" << endl;
                return -1;
            }

            temp = current->next;
            current->next = current->next->next;
        }

        removedValue = temp->data;
        delete temp;
        return removedValue;
    }

    int get(int position){
        if (head == nullptr){
            cout << "Empty" << endl;
            return -1;
        }

        Node *current = head;
        int currentPosition = 0;

        while(current != nullptr && currentPosition < position){
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr || currentPosition != position){
            cout << "Invalid" << endl;
            return -1;
        }

        return current->data;
    }

    void print() {
        Node  *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    linkedList myList;

    myList.add(10, 0);
    myList.add(20, 1);
    myList.add(30, 2);
    myList.add(40, 3);
    myList.add(50, 4);
    myList.get(1);
    myList.print();

    myList.add(60, 1);
    myList.print();

    myList.add(60, 50);


    return 0;
}