#include "HT.h"

//sets 'size' to 0, sets 'capacity' to the initialSize, and then allocates an array of strings (values) with the capacity stated
hashTable::hashTable (int initialSize) {
	size = 0;
	capacity = initialSize;

	values = new string [capacity];

}

//destructor, frees the allocated memory that was used for values above using 'delete'
hashTable::~hashTable () {
	delete [] values;

}

//hashes, the equation to figure out which key = which value
int hashTable :: hash (string key) {
	int result = 0; //holds the value of the key after its calculated, initally starts at 0

	for (auto character : key) { //for loop that goes to each letter in the 'key' (given word)
		char lower = tolower(character); //converts capital letters to lower case (i had to look up how to do that lol)

		if (isalpha(lower)) { 
			result += (tolower(lower) - 'a'); //it (-) the ASCII value of the letter 'a' - the letter it's iterating over at that point

		}
	}
	return result % capacity; //modulo the result by the size of the table so the key fits on the table

}

//adds a new key to the table
int hashTable :: add (string newkey) {
	int result = 0;

	int index = hash(newkey); //uses the hash function tp figure out where to add on the table

	if (values[index] == "" && newkey != "") { //if values are empty at the index and the 'newkey' isn't an empty string
		size ++; //increase the size by 1

	} else { //otherwise, if there's a collision, return -1
		result = -1;

		values[index] = newkey;

		return result;
	}
	values[index] = newkey;
	return result;

}


//finding a key in the hashtable
string hashTable :: find (string key) { 
	string result = "";

	int index = hash (key); //calculates which index the key had using the 'hash' function

	result = values[index]; //sets the result to the value that was found at the index

	if (result != key) { //if the value that was returned doesn't match the key, return an empty string
		result = "";

	}
	return result;

}

int hashTable :: getSize () { return size;} //return the current size and capacity
int hashTable :: getCapacity () {return capacity;}