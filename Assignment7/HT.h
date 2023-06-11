#pragma once

#include <string>

using std::string;

class hashTable {

	public:

		hashTable (int initialCapacity = 17);
		~hashTable ();

		int add (string newKey);
		string remove (string oldKey);
		string find (string key);
		int getSize ();
		int getCapacity ();
	
	private:

		int size;
		int capacity;
		string *values;
		int hash (string key);

};