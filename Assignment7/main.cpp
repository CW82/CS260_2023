#include <iostream>
#include <string>

#include "hashtable.cpp"
#include "HT.h"

using namespace std;

int main() {
    hashTable table(17);

	//test for inserting nothing
    table.add(" ");
	
	//testing for inserting capital letters (making them lowercase and then calculating)
    table.add("ITALY");
    table.add("Greece");

	//test for collision
    table.add("latin");
    table.add("yessb");

    cout << "Value of ' ': " << table.find(" ") << endl; //empty table
    cout << "Value of 'ITALY': " << table.find("ITALY") << endl; //insterted
    cout << "Value of 'Greece': " << table.find("Greece") << endl; //inserted
    cout << "Value of 'latin': " << table.find("latin") << endl; //insterted, then overwritten by 'yessb'
    cout << "Value of 'yessb': " << table.find("yessb") << endl;
    cout << "Value of 'mario': " << table.find("mario") << endl; //tries to find something that's not on the table

    cout << "Size: " << table.getSize() << endl;
    cout << "Capacity: " << table.getCapacity() << endl;

    return 0;
}

