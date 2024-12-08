#ifndef CHAINING_H
#define CHAINING_H

const int CAPACITY = 31;

class HashNode
{
public:
    int key;
    int data;
    HashNode *next;

    HashNode(int key, int data) // Constructor
    {
        this->key = key;
        this->data = data;
        this->next = nullptr;
    }
};

class Table
{
public:
    Table();  // Constructor
    ~Table(); // Deconstructor

    void insert(HashNode newNode, char method);
    void erase(int key);
    int find(int key);
    int size() const;

    // Hashing Methods
    int DoubleHash(int key);
    int DoubleHashing(int key);
    int MidSquareHash(int key);
    int ModuloHash(int key) const;

    // Probing Hash
    int QuadraticProbing(int key);

    void print();

private:
    HashNode **datatable;
    int used;
};

#endif // CHAINING_H