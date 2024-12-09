#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>

#include "Chaining.h"

using namespace std;

void printmenu()
{
    cout << "------------HASH TABLE WITH CHAINING------------" << endl;
    cout << "Please select a choice: " << endl;
    cout << "I - Insert a record" << endl;
    cout << "D - Delete a record" << endl;
    cout << "F - Find a record" << endl;
    cout << "S - Get number of records" << endl;
    cout << "P - Print the table." << endl;
    cout << "Q - Quit the Program" << endl;
    cout << endl;
}

int main()
{
    int key;
    int data;
    char method;
    char choice;
    Table datatable;
    int size;

    do
    {
        printmenu();
        cout << "Enter choice: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'I':
            cout << "Enter key for the record: ";
            cin >> key;
            cout << "Enter data for the record: ";
            cin >> data;
            cout << "Enter the method you want to use for collisions:\n 'H' - Modulo Hashing\n 'D' - Double Hashing \n 'Q' - Quadratic Probing \n 'M' - Midsquare Hashing: ";
            cin >> method;
            datatable.insert(key, data, method);
            break;
        case 'D':
            cout << "Enter the key for the record you want to delete: ";
            cin >> key;
            datatable.erase(key);
            break;
        case 'F':
            cout << "Enter the key of node you want to find: ";
            cin >> key;
            datatable.find(key);
            break;
        case 'S':
            cout << "The size is: " << datatable.size() << endl;
            break;
        case 'P':
            datatable.print();
            break;
        case 'Q':
            cout << "Exiting Program .... " << endl;
            return 0;
            break;
        default:
            cerr << "Enter a valid option." << endl;
        }

    } while (choice != 'Q');
}