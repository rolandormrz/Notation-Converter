#include "DLDeque.hpp"

DLDeque::DLDeque() {

    // create sentinel nodes
   head = new dnode;
   trailer = new dnode;
   
   // connect head and trailer to default node
   head->next = trailer;
   trailer->prev = head; 
}        

DLDeque::~DLDeque() {

    dnode* current = head;              // points to current node starting at head node
    dnode* temp;                        // used to hold current->next before deleting current

    // loops through and deletes all nodes except for trailer
    while (current != trailer) {

       temp = current->next;
       delete current;
       current = temp;
    }
    
    delete trailer;
}

int DLDeque::size() const {

    return n;
}      

bool DLDeque::empty() const {

    return n == 0;
}

const std::string DLDeque::front() {

    if (empty()) throw std::invalid_argument("deque is empty");    
        
    dnode* temp = head->next;
    return temp->line;
}  

const std::string DLDeque::back() {

    if (empty()) throw std::invalid_argument("deque is empty");    
        
    dnode* temp = trailer->prev;
    return temp->line;
}     

void DLDeque::insertFront(const std::string x) {
    
    dnode* newNode = new dnode;
    dnode* temp;

    newNode->line = x;

    temp = head->next;              // make temp point to the node head is pointing to
    head->next = newNode;           // head points to newNode
    newNode->prev = head;           // newNode prev points to head
    
    if (empty()) {

        newNode->next = trailer;    // newNode next points to trailer
        trailer->prev = newNode;    // trailer points to newNode

    }
    else {
        newNode->next = temp;       // newNode points to where the head was originally pointing to
    }

    n++;                            // increment the number of nodes
}

void DLDeque::insertBack(const std::string x) {

    dnode* newNode = new dnode;
    dnode* temp;

    newNode->line = x;

    temp = trailer->prev;           // temp points to the node trailer is pointing to
    newNode->next = trailer;        // newNode next points to trailer
    trailer->prev = newNode;        // trailer points to newNode
    
    if (empty()) {

        newNode->prev = head;       // newNode prev points to head
        head->next = newNode;       // head points to newNode

    }
    else {
        newNode->prev = temp;       // newNode prev points the node the trailer was originally pointing to
    }

    n++;                            // increment the number of nodes
}

void DLDeque::removeFront() {

    if (empty()) throw std::invalid_argument("deque is empty, nothing to remove");    
        
    dnode* node_to_delete;          // the node we want to remove (positioned after the ehad)
    dnode* node_after;              // the node after the node we want to remove

    node_to_delete = head->next;    // node_to_delete points to the value after the head
    node_after = head->next->next;  // node_after points to the value after node_to_delete
    
    // bypass the node to be deleted
    head->next = node_after;
    node_after->prev = head;

    n--;

    delete node_to_delete;
}

void DLDeque::removeBack() {

    if (empty()) throw std::invalid_argument("deque is empty, nothing to remove"); 

    dnode* node_to_delete;              // the node we want to remove (positioned after the ehad)
    dnode* node_before;                 // the node before the node we want to remove

    node_to_delete = trailer->prev;     // node_to_delete points to the value before the trailer
    node_before = trailer->next->next;  // node_after points to the value before node_to_delete

    // bypass the node to be deleted
    trailer->prev = node_before;
    node_before->next = trailer;

    n--;

    delete node_to_delete;
}
