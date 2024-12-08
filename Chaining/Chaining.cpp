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