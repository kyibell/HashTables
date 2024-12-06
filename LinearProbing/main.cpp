#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

#include "LinearProbing.h"

using namespace std;

void printmenu()
{
    cout << "HASH TABLE WITH LINEAR PROBING" << endl;
    cout << endl;
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
    Record record;
    char method;
    char choice;
    Table datatable;
    int size;

    do
    {
        printmenu();
        cout << "Enter Choice: ";
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'I':
            cout << "Enter the key for the record: ";
            cin >> record.key;
            cout << "Enter the data for the key: ";
            cin >> record.data;
            cout << "Enter the method you want to use for collisions:\n'L' - Linear Probing\n 'D' - Double Hashing \n 'Q' - Quadratic Probing \n 'M' - Midsquare Hashing: ";
            cin >> method;
            datatable.insert(record, method);
            break;
        case 'D':
            cout << "Enter the key you want to delete: ";
            cin >> record.key;
            datatable.erase(record.key);
            break;
        case 'F':
            cout << "Enter the key you want to find: ";
            cin >> record.key;
            datatable.find(record.key);
            break;
        case 'S':
            size = datatable.size();
           cout << "Size of table is: " << size << endl;
            break;
        case 'P':
            datatable.print();
            break;
        case 'Q':
            cout << "Thank you for using this program" << endl;
            return 0;
            break;
        default:
            cerr << "Please enter a valid option." << endl;
        }

    } while (choice != 'Q');
    return 0;
}