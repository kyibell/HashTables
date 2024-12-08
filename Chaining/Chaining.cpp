#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "Chaining.h"

using namespace std;

const int CAPACITY = 31;

// Constructor
Table::Table()
{
    datatable = new HashNode *[CAPACITY]; // Declare a new table of HashNode pointers of size CAPACITY
    int used = 0;                         // Set used to 0
    for (int i = 0; i < CAPACITY; i++)
    {
        datatable[i] = NULL; // Set all the slots to NULL
    }
}

// Deconstructor
Table::~Table()
{
    for (int i = 0; i < CAPACITY; i++)
    {                                      // Loop through the table
        HashNode *currNode = datatable[i]; // set currNode to the table at i
        while (currNode != NULL)
        {
            HashNode *prevNode = currNode; // Set the previous node to currNode
            currNode = currNode->next;     // Increment Curr Node
            delete prevNode;               // delete the previous Node
        }
    }
    delete[] datatable; // Delete the data table
}

int Table::ModuloHash(int key) const
{
    return key % CAPACITY; // Standard Modulo Hash
}

int Table::DoubleHash(int key)
{
    return 1 + (key % 7); // + 1 to ensure this doesn't hash to 0
}

int Table::MidSquareHash(int key)
{
    int numDigits = ceil(log10(key));         // find NumDigits with the log 10 of key
    long long position = key * key;           // Square key to get position
    string strPosition = to_string(position); // Convert the position to str to parse
    int strLength = strPosition.length();     // Variable to hold str length

    if (strLength % 2 == 0)
    { // If the string length is even, parse /4
        strPosition = strPosition.substr(strLength / 4, numDigits);
    }
    else
    { // else add 1 to length so it's even
        strPosition = strPosition.substr((strLength + 1) / 4, numDigits);
    }
    int index = stoi(strPosition); // Convert strPosition to int for index

    return index; // Return index
}

int Table::QuadraticProbing(int key)
{
    int index = ModuloHash(key); // Inital Index
    // Come back to this to figure out how to modify for Chaining
}
