#ifndef DLDEQUE_H
#define DLDEQUE_H

#include <stdexcept>
#include <string>

class DLDeque {
public:

    // constructs a doubly linked deque
    DLDeque();                    

    ~DLDeque();

    // returns the size of the deque
    int size() const;                 

    // returns true if empty
    bool empty() const;               

    // returns the front element
    const std::string front();        

    // returns the back element
    const std::string back();         

    // inserts element at the front
    void insertFront(const std::string x);

    // inserts element at the back
    void insertBack(const std::string x);

    // removes the front element
    void removeFront();

    // removes the back element
    void removeBack();

private:

    // struct for doubly linked list
    struct dnode {
        std::string line;    // holds a character or string

        dnode* prev;
        dnode* next;
    };

    int n = 0;                   // number of nodes

    dnode* head;
    dnode* trailer;
};

#endif /* DLDEQUE_H*/