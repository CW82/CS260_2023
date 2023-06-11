#include "HT.h"

hashTable::hashTable (int initialCapacity) { 
    size = 0; //set the size of the table to 0 to start with
    capacity = initialCapacity; //set the capacity to whatever i siad the initialCap was
    values = new string[capacity]; // allocates array of strings, called 'values', with the capacity from above
}

hashTable::~hashTable () {
    delete[] values; //frees the memory made above using delete
}

//adds based on where the letter is in the alphabet (a = 1, b = 2, c = 3, etc)
int hashTable::hash (string key) {
    int result = 0; //starts off at 0

    for (auto character : key) { //itterates over all the char in the string,
        char lower = tolower (character); // if it's an upper case letter, convert to lower (had to look how to do that lol)

        if (isalpha(lower)) {
            result += (tolower(lower) - 'a'); 

        }
    }
    return result % capacity; //devides by however big the table is using modulo so it fits on the table

}

//add a key to the table
int hashTable::add (string newKey) { 
    int index = hash (newKey); //takes the equation from above and do it to the key

    if (values[index] == " " && newKey != " ") { //if it's empty and the key isn't empty
        size++; //increase the size by one

    } else {
        values[index] = newKey; //otherwise overwrite

    }
    return 0;

}

//find the value associated with the key
string hashTable::find (string key) {
    int index = hash (key); //runs the hash to find the index that the key you're looking for 

    if (values[index] == key) { //if it matches, return the value that was found there
        return values[index];

    }
    return ""; //otherwise return nothing to show there wasn't anything

}

int hashTable::getSize () {
    return size;

}

int hashTable::getCapacity () {
    return capacity;

}
