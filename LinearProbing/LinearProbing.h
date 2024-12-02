
#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H



const int CAPACITY = 31; // Set a const of capacity = 31


struct Record { // Structs for Records 
    int key;
    int data;
};


class Table {
    public:
    Table(); // Constructor to initialize table.
    void insert(const Record &entry);
    void erase(int key);
    void find(int key, bool found, Record &result) const;
    int size() const;

    // Hashing Methods
    void DoubleHash(int key);
    void MidSquareHash(int key);
    void ModuloHash(int key);

    //Probing Hash Methods
    void LinearProbing(int key);
    void QuadraticProbing(int key);


    void print(); // print function

    private:
    Record table[CAPACITY];
    int used;

}; 


#endif // LINEARPROBING_H