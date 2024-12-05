
#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H



const int CAPACITY = 31; // Set a const of capacity = 31


typedef struct Record { // struct for Records 
    public:
    int key;
    int data;
};


class Table {
    public:
    Table(); // Constructor to initialize table.
    void insert(const Record &entry, char method);
    void erase(int key);
    int find(int key) const;
    int size() const;

    // Hashing Methods
    int DoubleHash(int key);
    int DoubleHashing(int key);
    int MidSquareHash(int key);
    int ModuloHash(int key) const;

    //Probing Hash Methods
    int LinearProbing(int key);
    int QuadraticProbing(int key);


    void print(); // print function

    private:
    Record table[CAPACITY];
    int used;

}; 


#endif // LINEARPROBING_H