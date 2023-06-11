#pragma once

#include <string>

using std::string;

class hashTable {
	public:

		hashTable(int initialCapacity = 17); //set the size to 0 and initialcap to 17
		~hashTable(); //deconstructor
		int add(string newKey); //newKey parameter to add to table
		string find(string key); //takes key parameter and searches for it in table
		int getSize(); //returns size and cap of the table
		int getCapacity();

	private:

		int size; //var to keep track of how many things are in the table
		int capacity; //var to know how big the max table is
		string *values; //pointer for the array, holds the vars in the table
		int hash(string key); 

};

