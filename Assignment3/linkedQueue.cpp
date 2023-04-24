#include <iostream>
#include <cstdio>

using std:: cout;
using std:: endl;
using std:: printf;

struct node {

	int data;
	node *next;

};

class Stack{

	private:
		node *top;

	public:
		void push(int newData);
		int pop();
		int peek();

};

int main(){

	

}