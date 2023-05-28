#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
	int data;
	Node *next;

};

class linkedList {

	public:
		Node *head;

		linkedList () {
			head = NULL;

		}

		void acsending (int data) {
			Node *newNode = new Node;
			newNode->data = data;
			newNode->next = NULL;

			if (head == NULL) {
				head = newNode;

			} else {
				if (data < head->data) {
				newNode->next = head;
				head = newNode;
				return;

			}			
				Node *current = head;

				for (int i = 0; current->next != NULL && data > current->next->data; i++) {
					current = current->next;

				}
				newNode->next = current->next;
				current->next = newNode;

			}
		}
	
		bool search (int data) {
			Node *current = head;

			while (current != NULL) {
				if (current->data == data) {
					return true;

				}
				current = current->next;

			}
			return false;

		}

		void print () {
			Node *current = head;

			while (current != NULL) {
				cout << current->data << " ";
				current = current->next;

			}
			cout << endl;

		}
};

int main () {
	linkedList sortedAcsending;

	sortedAcsending.acsending(5);
	sortedAcsending.print();

	sortedAcsending.acsending(8);
	sortedAcsending.print();

	sortedAcsending.acsending(2);
	sortedAcsending.print();

	sortedAcsending.acsending(-10);
	sortedAcsending.print();

	sortedAcsending.acsending(100);
	sortedAcsending.print();

	sortedAcsending.acsending(5);
	sortedAcsending.print();
	
	int find;
	cout << "What number do you want to find: ";
	cin >> find;

	if (sortedAcsending.search(find)){
		cout << find << "True" << endl;
	} else {
		cout << find << "False" << endl;
	}

    return 0;
}