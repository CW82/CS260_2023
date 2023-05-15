#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;
using std::printf;

struct Node{ 

    int data; //struct for the LL. This is what the 'node' contains, integer data
    Node *next; //pointer to the 'next' node

}nn; //front, back, and newnode pointers

Node *front = nullptr;
Node *back = nullptr;

class Queue{

public:
	void enQ(int data){ //enqueue function, enQ takes integer data and adds it to the back of the LL/queue

	Node *nn = new Node; //new node pointer, creates a new node 'nn' 
	nn->data = data; //
	nn->next = NULL;

	if (front->next=nullptr){ //checks to see if the queue is empty, if the fronts 'next' pointer is nullptr then the list is empty and then set the front and back to nn

		front, back = nn; 

	}
	else{

		back->next=nn; //sets the reference for the 'next' data field of the back pointer to the new node
		back = nn; //now the new node added will be the back

	}
	}

	void deQ(){

	if (front == NULL){ //if the front is NULL, then the queue is empty

		printf("Your Queue is empty :(");

	}

	Node *hold = front; //point the nn at the front
	front = front->next; //set the front to the next node/the one that was second 
	delete hold; //delete the old placeholder

	if (front == nullptr){

		back = nullptr; //check to make sure queue isn't empty

	}

}
};

int main(){
	front = back = NULL;

	Queue plzwork;
	plzwork.enQ(10); //adding data to the queue
	plzwork.enQ(20);
	plzwork.enQ(30);
	plzwork.deQ(); //hopefuly deleting one element from the queue

    if (front != nullptr) {
        cout << "Queue: " << front->data << endl;
    } else {
        cout << "Queue is empty." << endl;
    }

	//couldn't quite figure out the cout stuff to get it to print? 
	//cout << "Queue: " << <<endl;, I tried to make it print out, but I'm not sure how?? It ran without errors though so I'm assuming it worked?? IK, bad

	return 0;
}

