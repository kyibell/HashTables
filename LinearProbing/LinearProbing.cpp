#include "LinearProbing.h";
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <iomanip>
using namespace std;

Table::Table()
{ // Default Constructor
    used = 0;
    for (int i = 0; i < CAPACITY; i++)
    {
        table[i].key = -1; // initialize everything to a flag to check if empty
    }
}

void Table::insert(const Record &entry)
{
}

void Table::erase(int key) {

}

int Table::ModuloHash(int key) const
{
    return key % CAPACITY; // simple modulo hash to get index
}

int Table::DoubleHash(int key)
{
    return 1 + (key % 7); // +1 to ensure this won't hash to 0
}

int Table::DoubleHashing(int key) {
    int index = ModuloHash(key); // Calculate First Hash (index)

    if (table[index].key != -1) // Check if it's taken
    {
        index = DoubleHash(key); // if taken, use the second hash
    }
    return index;
}

int Table::MidSquareHash(int key) {
    int numDigits = ceil((std::log10(key))); // calculate the number of digits with log10(key)
    long long position = key * key; // Square the key to get the positon
    string strPosition = to_string(position); // Convert to string to parse later
    int length = strPosition.length(); // Length for parsing

    if (length % 2 == 0) { // If even, parse divided by 4 and numDigits
        strPosition = strPosition.substr(length / 4, numDigits);
    }
    else { // else if odd, add 1 to length
        strPosition = strPosition.substr((length + 1), numDigits);
    }
    
    int index = stoi(strPosition);
    
    return index;
}

int Table::LinearProbing(int key) {
    int index = 0; // Index Variable
    for (int i = 0; i < CAPACITY; i++) {
        index = (key + i) % CAPACITY;
        if (table[index].key == -1) { // If empty, return index
            return index;
        }
    }
    return -1; // Return -1 if full
}

int Table::QuadraticProbing(int key) {
    int hash1 = ModuloHash(key); // Calculate initial hash

    for (int i = 0; i < CAPACITY; i++) {
        int index = (hash1 + i * i) % CAPACITY;
        if (table[index].key == -1) { // If empty, return index
            return index;
        }
    }
    return -1; // Return -1 if full
}

void Table::print() {
    cout << "Index  Key  Data" << endl;
    for (int i = 0; i < CAPACITY; i++) {
        cout << setw(5) << i << setw(5) << table[i].key;
        if (table[i].key != -1) { // Only prints if the place is taken
            cout << setw(8) << table[i].data;
            cout << endl;
        }
    }
    cout << endl;
}

