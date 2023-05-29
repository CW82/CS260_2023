#include <iostream>
#include <cstdio>

using namespace std;

//Node structure, 
struct Node {
	int data; //struct for the LL. This is what the 'node' contains, integer data
	Node *next; //pointer to the 'next' node

};

//Defines linkedList class
class linkedList {

	public:
		Node *head; //head pointer 

		linkedList () {
			head = NULL; //sets head to NULL, empty list

		}

		//sorts the list into acsending order
		void acsending (int data) { 
			Node *newNode = new Node; //creates newNode 
			newNode->data = data; //sets the newNode's data to
			newNode->next = NULL; //sets the newNode's next to NULL

			if (head == NULL) { //checks if the head is NULL
				head = newNode; //if it is, set the head pointer to point at the new node

			} else { //do this if head isn't NULL
				if (data < head->data) { //checks id the data is smaller than head's data
				newNode->next = head; //if it is, the newNode is now the head
				head = newNode;
				return;

			}			
				Node *current = head; //create 'current' pointer and set to head

				//loop that finds the position to put the value
				for (int i = 0; current->next != NULL && data > current->next->data; i++) {
					current = current->next; 

				}
				newNode->next = current->next;
				current->next = newNode; //the newNode's next is set to the currents, and current's next is set to newNode

			}
		}
	
		//searches linearly through the list for the inputed value. I used bool bc you suggested it return either true or false to search and I thouoght it was easiest
		bool search (int data) {  
			Node *current = head; //creates a current pointer and sets it to head

			while (current != NULL) { //loop continues till the current pointer is NULL i.e the end of the list
				if (current->data == data) { //if current's data is euqal to the data you're looking for...
					return true; //returns true, the value was in the list

				}
				current = current->next; //if there isn't a match, current it moved forward

			}
			return false; //if no match is found, return false, value isn't in the list

		}

		//prints out list and search 
		void print () {
			Node *current = head; //current pointer set to head

			while (current != NULL) { //loop, while the current isn't NULL
				cout << current->data << " "; //print the current's data with a space
				current = current->next; //then move current foward. Do this until current is equal to NULL (end of the list)

			}
			cout << endl; //makes space between each print statement

		}
};

int main () {
	linkedList sortedAcsending;

	sortedAcsending.acsending(5);
	sortedAcsending.print();

	sortedAcsending.acsending(4);
	sortedAcsending.print();

	sortedAcsending.acsending(2);
	sortedAcsending.print();

	//before head
	sortedAcsending.acsending(-10);
	sortedAcsending.print();

	//after head
	sortedAcsending.acsending(100);
	sortedAcsending.print();

	//duplicate number
	sortedAcsending.acsending(5);
	sortedAcsending.print();

	int add; //just wanted to see if this would work if i tried it and it does? I think? Anyways...
	cout << "What number do you want to add?: ";
	cin >> add;

	sortedAcsending.acsending(add);
	sortedAcsending.print();

	int find; //var for searching
	cout << "What number do you want to find?: "; //asks user what number they want to search
	cin >> find; //gets the user input

	if (sortedAcsending.search(find)){ //call the search from above and takes the var 'find' from above
		cout << find << "True" << endl; //if it finds it, print true

	} else {
		cout << find << "False" << endl; //if not found, print false

	}

    return 0;
}