#include <iostream>
#include <string>

#include "HT.h"

using namespace std;

int main() {
	hashTable table(17);

	table.add(" ");

	table.add("ITALY");
	table.add("Greece");

	table.add("latin");
	table.add("yessb");

	cout << "Value of ' ': " << table.find(" ") << endl;
	cout << "Value of 'ITALY': " << table.find("ITALY") << endl;
	cout << "Value of 'Greece': " << table.find("Greece") << endl;
	cout << "Value of 'latin': " << table.find("latin") << endl;
	cout << "Value of 'yessb': " << table.find("yessb") << endl;

	cout << "Value of 'mario': " << table.find("mario") << endl;

	cout << "Size: " << table.getSize() << endl;
	cout << "Capacity: " << table.getCapacity() << endl;

	return 0;

}