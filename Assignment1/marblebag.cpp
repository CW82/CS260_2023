#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using std:: cout;
using std:: cin;

struct marble {

	int marb, marbinbag, bag;
	char marbcolor, marbsize;

};

int main() {

	marble starter;
	starter.marb = 0;
	starter.marbinbag = 0;
	starter.bag = 0;

	int usrinp;

	printf("What would you like to do?\n");
	printf(" 1: Add Marble\n 2: Delete Marble\n 3: Marbles in Bag Currently\n 4: Desc of Marbles\n");
	scanf("%d", &usrinp);

	if (usrinp == 1){

		cout << "How many marbles would you like to add?: ";

		scanf("%d", &starter.marb);

		cout << "Marbles in Bag: " << starter.marb ++;

	}

	if (usrinp == 2){

		cout << "How many marbles would you like to delete?: ";

		scanf("%d", &starter.marb);

		cout << "Marbles in Bag Now: " << starter.marb - starter.marb;

	}

	return 0;
}