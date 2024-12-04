#ifndef CSTACK_H
#define CSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class CStack{
    private:
        T data;      // data
        CStack* next;  // next pointer which points to the next element

    public:
        CStack(CStack* ptr, T d);  // d: data
        ~CStack();
        bool isEmpty(CStack* ptr);
        T top(CStack *ptr);
        int size(CStack *ptr);
        void push(CStack*& ptr, T d);
        void pop(CStack*& ptr);
        void empty(CStack*& ptr);
};

// Default constructor
template <typename T>
CStack<T>::CStack(CStack* ptr, T d){
    this->next = ptr;
    this->data = d;
}

// Destructor
template <typename T>
CStack <T> ::~CStack(){
    while (next != nullptr) {
            CStack* temp = next;
            next = next->next;
            delete temp;
        }
        next = nullptr;
}

// A function which checks if the stack is empty
template <typename T>
bool CStack <T> ::isEmpty(CStack* ptr){
    // if ptr->next is equal to nullptr, 
    // that means the stack is not empty
    // so return true, otherwise false
    return ptr == nullptr;
}

// Function to add an element to the top
template <typename T>
T CStack<T>::top(CStack* ptr){
    // will give en error if used when ptr == nullptr
    if(ptr->next != nullptr){
        CStack* p;  // dummy pointer
        for (p = ptr; p->next != nullptr; p = p->next){
            // do nothing
            // now p is the last element
        }
        return p->data;
    }

    else{
        // if ptr->next is nullptr
        return ptr->data;
    }
}

// Function which outputs the size of the stack
template <typename T>
int CStack<T>::size(CStack *ptr){
    int count = 0;  // for counting the size
    if (ptr == nullptr){
        return count;
    }
    CStack* p;  // dummy pointer
    for (p = ptr; p != nullptr; p = p->next){
         count++; // loop increases the count
         // up until p->next points to nullptr
    }
    return count;
}

// Function to push (add) an element to the top of the stack
// Parameters:
//      ptr : a CStack pointer
//      d   : data
template <typename T>
void CStack<T>::push(CStack*& ptr, T d){
    if (ptr == nullptr){
        ptr = new CStack(nullptr, d);
    }
    else{
    CStack* p;  // dummy pointer
    for (p = ptr; p->next != nullptr; p = p->next){
        // do nothing
        // now p is at the very end
    }
    p->next = new CStack(nullptr, d);
    // cout << p->next->data << endl;
    }
}

// A function which pops (remove) the element from the top of the stack
template <typename T>
void CStack<T>::pop(CStack*& ptr){
    // if stack is empty
    if (ptr == nullptr){
        cout << "Empty stack" << endl;
        return;
    }

    // If stack has only one element
    if (ptr->next == nullptr){
        delete ptr;
        ptr = nullptr;
        return;
    }

    CStack *p;
    for (p = ptr; p->next->next != nullptr; p = p->next){
    }
    delete p->next;
    p->next = nullptr;
}

// A function which cmepties the whole stack
template <typename T>
void CStack<T>::empty(CStack*& ptr){
    while (ptr != nullptr){
        pop(ptr);
    }
}



#endif