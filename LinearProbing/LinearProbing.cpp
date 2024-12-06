#include "LinearProbing.h"
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

void Table::insert(const Record &entry, char method)
{
    method = toupper(method); // Handle case sensitive cases
    assert(entry.key > 0);    // Assert that the key is positive

    int index = ModuloHash(entry.key); // Starting with a normal hash

    switch (method)
    {         // Switch case for hashing methods
    case 'L': // Linear Probing
        index = LinearProbing(entry.key);
        break;
    case 'D': // Double Hashing
        index = DoubleHashing(entry.key);
        break;
    case 'M': // Midsquare Hashing
        index = MidSquareHash(entry.key);
        break;
    case 'Q': // Quadratic Probing
        index = QuadraticProbing(entry.key);
        break;
    default:
        cerr << "Please enter a valid option" << endl;
    }
    table[index] = entry; // Table at the index is equal to the entry
    used++;               // Increment used slots
}

void Table::erase(int key)
{
    int index = find(key); // Find the index

    if (index == -1)
    {
        cout << "Index was not found. Please try again." << endl;
        return;
    }
    else
    {
        cout << "Record with key: " << table[index].key << "and with data: " << table[index].data << "has been deleted." << endl;
        table[index].key = -1;    // change to -1
        table[index].data = -999; // Flag to show deleted
        used--;                   // Dedcrement used
    }
}

int Table::find(int key) const
{
    int index = ModuloHash(key); // Start with init hash

    for (int i = 0; i < CAPACITY; i++)
    {
        index += i;
        if (table[index].key == key)
        {
            return index;
        }
    }
    cout << "Error: Index was not found." << endl;
    return -1; // If not found return -1
}

int Table::size() const
{
    return used; // Reutrn used
}

int Table::ModuloHash(int key) const
{
    return key % CAPACITY; // simple modulo hash to get index
}

int Table::DoubleHash(int key)
{
    return 1 + (key % 7); // +1 to ensure this won't hash to 0
}

int Table::DoubleHashing(int key)
{
    int index = ModuloHash(key); // Calculate First Hash (index)

    if (table[index].key != -1) // Check if it's taken
    {
        index = DoubleHash(key); // if taken, use the second hash
    }
    return index;
}

int Table::MidSquareHash(int key)
{
    int numDigits = ceil((std::log10(key)));  // calculate the number of digits with log10(key)
    long long position = key * key;           // Square the key to get the positon
    string strPosition = to_string(position); // Convert to string to parse later
    int length = strPosition.length();        // Length for parsing

    if (length % 2 == 0)
    { // If even, parse divided by 4 and numDigits
        strPosition = strPosition.substr(length / 4, numDigits);
    }
    else
    { // else if odd, add 1 to length
        strPosition = strPosition.substr((length + 1), numDigits);
    }

    int index = stoi(strPosition);

    return index;
}

int Table::LinearProbing(int key)
{
    int index = ModuloHash(key); // Index Variable
    for (int i = 0; i < CAPACITY; i++)
    {
        index = (key + i) % CAPACITY; //  Adds i to the index if the spot is taken
        if (table[index].key == -1)
        { // If empty, return index
            return index;
        }
    }
    return -1; // Return -1 if full
}

int Table::QuadraticProbing(int key)
{
    int hash1 = ModuloHash(key); // Calculate initial hash

    for (int i = 0; i < CAPACITY; i++)
    {
        int index = (hash1 + i * i) % CAPACITY;
        if (table[index].key == -1)
        { // If empty, return index
            return index;
        }
    }
    return -1; // Return -1 if full
}

void Table::print()
{
    cout << "Index  Key  Data" << endl;
    for (int i = 0; i < CAPACITY; i++)
    {
        cout << setw(5) << i << setw(5) << table[i].key;
        if (table[i].key != -1)
        { // Only prints if the place is taken
            cout << setw(8) << table[i].data;
        }
        cout << endl;
    }
    cout << endl;
}
