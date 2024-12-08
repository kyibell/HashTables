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

int Table::size() const
{
    return used;
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
    return 0;
}

void Table::insert(int key, int data, char method)
{
    method = toupper(method); // Handle case sensitive cases
    assert(key > 0);          // Handle no negative keys
    int index = 0;            // Inital Index

    switch (method)
    {
    case 'Q': // Quadratic Probing
        index = QuadraticProbing(key);
        break;
    case 'M': // Midsquare Hashing
        index = MidSquareHash(key);
        break;
    case 'D': // Double Hash
        index = DoubleHash(key);
        break;
    case 'H': // Modulo Hash
        index = ModuloHash(key);
        break;
    default:
        cerr << "Enter a valid opiton." << endl;
    }

    HashNode *newNode = new HashNode(key, data); // Declare a new HashNode with key and data

    if (datatable[index] == NULL) // If empty, add to table
    {
        datatable[index] = newNode;
    }
    else if (datatable[index] != NULL)
    { // If not empty, add to list
        HashNode *temp = datatable[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        used++;
        //   delete temp;
    }
}

void Table::erase(int key)
{
    int index = ModuloHash(key);

    HashNode *temp = datatable[index];
    HashNode *prev = NULL; // Set a previous node in case there's multiple nodes at an index

    if (temp == NULL || temp->key != key)
    {
        cout << "Element not found to delete, please try again." << endl;
        return;
    }

    while (temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;

        if (prev != NULL)
        { // Check if there's a node before the Node we want to delete
            prev->next = temp->next;
        }
    }
    cout << "Node with key: " << temp->key << "and with data: " << temp->data << "has been deleted." << endl;
    delete temp;
}

HashNode *Table::find(int key)
{
    int index = ModuloHash(key);
    HashNode *temp = datatable[index];

    while (temp != NULL && temp->key != key)
    {
        temp = temp->next;
    }

    return temp;
}

void Table::print()
{
    cout << "Index\tKey\tData" << endl;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (datatable[i] == NULL)
        {
            cout << i << "\t--\t --" << endl;
        }
        else
        {
            cout << i << "\t";
            HashNode *temp = datatable[i];
            while (temp != NULL)
            {
                cout << "[" << temp->key << ", " << temp->data << "] --> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}