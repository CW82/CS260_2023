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
        head = nullptr; //empty list
    }

    //creates newNode pointer with data
    void add(int data, int position) {
        Node *newNode = new Node;
        newNode->data = data;

        //checks if where you want to add is the head of the list
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        //if so, the next part of newNode is set as the current head and the head pointer
        //if updates to point at newNode

        //traversing through the list to find the postition -1 from the desired position
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        //as it traverses, if the temp is every == nullptr, there's not enough positions
        //to add to the list
        if (temp == nullptr) {
            cout << "Not enough positions" << endl;
            delete newNode;
            return;
        }

        //the newNode's next is set to the temps next
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //check for an empty list
    int remove(int position) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return -1;
        }
        //creates a temp pointer and a removedValue var
        Node *temp;
        int removedValue;

        //updates the head pointer if the desired remove posistion is the head
        if (position == 0) {
            temp = head;
            head = head->next;
        } else {
            Node *current = head;
            int currentPosition = 0;
            //otherwise, traveres the list to find node right before the desired position

            while (current->next != nullptr && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }

            //checks for out of bounds or if the desired position cannot be reached
            if (current->next == nullptr || currentPosition != position - 1) {
                cout << "Invalid position" << endl;
                return -1;
            }

            temp = current->next;
            current->next = current->next->next;
        }

        //deletes the temp pointer and returns the removedValue
        removedValue = temp->data;
        delete temp;
        return removedValue;
    }

    //check for an empty list
    int get(int position){
        if (head == nullptr){
            cout << "Empty" << endl;
            return -1;
        }

        //creats a current pointer and currentPos var to traverse list
        Node *current = head;
        int currentPosition = 0;

        //will do while current isn't null
        while(current != nullptr && currentPosition < position){
            current = current->next;
            currentPosition++;
        }
        //makes current pointer point to the next node and increases the position by 1

        //checks if end of list was reached or if the position was out of bounds
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
    myList.print();

    myList.add(60, 1);
    myList.print();

    myList.add(60, 50);
    myList.print();

    myList.remove(2);
    myList.print();

    myList.get(1);
    myList.print();

    return 0;
}