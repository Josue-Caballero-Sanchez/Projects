#ifndef LinkedListApp_NODE_H
#define LinkedListAPP_NODE_H
#include <iostream>
using namespace std;

//creates a linked list class
template <class T>
class LinkedList;

//Node class
template <class T>
class Node{
    friend class LinkedList<T>;

//public variables in the node class
public:
    Node(){                //default constructor sets prev and next to NULL
        next = NULL;
        prev = NULL;
    }
    Node(T data){         //constructor with data, sets data equal to data passed in. Next and prev are NULL
        data = data;
        next = NULL;
        prev = NULL;
    }

//private variables in the node class
private:
    T data;
    Node<T> *next;
    Node<T> *prev;
};

//linked list class
template <class T>
class LinkedList{

//public variables in linked list class
public:
    LinkedList(){                      //default constructor sets head to NULL
        head = NULL;
    }
    LinkedList(T data){                //constructor with data, sets head to a new node with data passed in
        head = new Node<T>(data);
    }
    ~LinkedList(){                     //destructor for linked list
        Node<T> *node = head;
        Node<T> *tempNode;

        while(node != NULL){
            tempNode = node;
            node = node->next;
            delete tempNode;
        }
    }

    //methods in linked list class
    void AddToFront(T data);
    void AddToEnd(T data);
    bool AddAtIndex(T data, int index);
    void AddBefore(Node<T>*, T data); 
    void AddAfter(Node<T>*, T data);
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);
    T RemoveBefore(Node<T>*);
    T RemoveAfter(Node<T>*);
    bool ElementExists(T data);
    Node<T>* Find(T data);
    int IndexOf(T data);
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);
    void PrintList();
    void Empty();
    int Length();
    Node<T>* getlast();

//private variable in linked list class
private:
    Node<T> *head;
};

//this method adds data to the front of the list
template <class T>
void LinkedList<T>::AddToFront(T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }

    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
} 

//this method adds data to the end of the list
template <class T>
void LinkedList<T>::AddToEnd(T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    if(head == NULL){
        head = newNode;
    }

    else{
        Node<T> *tempNode = head;
        while(tempNode->next != NULL){
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
        newNode->prev = tempNode;
    }
}

//this method adds data at a specified index, if it was successful it returns true and if not it returns false
template <class T>
bool LinkedList<T>::AddAtIndex(T data, int index){
    bool result = true;
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    Node<T> *temp = new Node<T>();
    temp = head;
    int count = 0;

    if(index == 0){
        AddToFront(data);
        return true;
    }
    while(count < index-1){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        return false;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
    
    return result;
    
}

//this method adds data before a specified node
template <class T>
void LinkedList<T>::AddBefore(Node<T> *oldnode, T data){
     Node<T> *newNode = new Node<T>();
     newNode->data = data;

     Node<T> *prevNode = new Node<T>();
     prevNode = oldnode->prev;

     if(oldnode->prev == NULL){
        AddToFront(data);
     }
    if(prevNode == NULL){
        return;
     }

     newNode->next = prevNode->next;
     prevNode->next = newNode;
     newNode->prev = prevNode;
     if(newNode->next != NULL){
        newNode->next->prev = newNode;
     }
}

//this method adds data after a specified node
template <class T>
void LinkedList<T>::AddAfter(Node<T> *oldnode,T data){
    Node<T> *newNode = new Node<T>();
    newNode->data = data;

    Node<T> *prevNode = new Node<T>();
    prevNode = oldnode;

    if(oldnode->next == NULL){
        AddToEnd(data);
        return;
    }

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
}

//this method removes the first element in the list and returns the data in that element
template <class T>
T LinkedList<T>::RemoveFromFront(){
     Node<T> *temp = new Node<T>();
     int data;

     if(head == NULL){
        return -1;
     }
     else{
     temp = head;
     data = head->data;
     head = head->next;
     delete temp;
     return data;
     }
}

//this method removes the last element in the list and returns the data in that element
template <class T>
T LinkedList<T>::RemoveFromEnd(){
    Node<T> *temp = new Node<T>();
    int data;
    temp = head;

    if(head == NULL){
        return -1;
    }
    else if(head->next == NULL){
        data = head->data;
        delete temp;
        head = NULL;
    }
    else{
        Node<T> *temp2 = head->next;
        
        while(temp2->next != NULL){
            temp2 = temp2->next;
            temp = temp->next;
        }
        data = temp2->data;
        temp->next = NULL;
        delete temp2;
    }
    return data;    
}

//this method removes the first instance of some specified data in that list
template <class T>
void LinkedList<T>::RemoveTheFirst(T data){
    if(head == NULL){
        return;
    }

    Node<T> *temp = new Node<T>();
    if(head->data == data){
        temp = head;
        head = temp->next;
        delete temp;
        return;
    }
    Node<T> *temp2 = new Node<T>();
    temp = head;
    temp2 = head->next;

    while(temp2 != NULL){
        if(temp2->data == data){
            temp->next = temp2->next;
            delete temp2;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
}

//this method removes every instance of some specified data in the list
template <class T>
void LinkedList<T>::RemoveAllOf(T data){
    if(head == NULL){
        return;
    }
    Node<T> *temp = new Node<T>();
    Node<T> *del = new Node<T>();
    temp = head;

    while(temp != NULL && temp->data == data){
        head = temp->next;
        delete temp;
        temp = head;
    }

    while(temp != NULL){
        while(temp != NULL && temp->data != data){
            del = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }
        del->next = temp->next;
        delete temp;
        temp = del->next;
    }
}

//this method removes an element before some specified element and returns the data in the removed element
template <class T>
T LinkedList<T>::RemoveBefore(Node<T> *pointer){
    if(pointer->prev == NULL){
        return -1;
    }

    if(head == NULL){
        return -1;
    }

    Node<T> *temp = new Node<T>();
    temp = pointer->prev;

    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    return temp->data;
}

//this method removes an element after some specified element and returns the data in the removed element
template <class T>
T LinkedList<T>::RemoveAfter(Node<T> *pointer){
    if(head == NULL){
        return -1;
    }
    if(pointer->next == NULL){
        return -1;
    }

    Node<T> *temp = new Node<T>();
    temp = pointer->next;

    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }

    return temp->data;



}

//this method searches the list to see if some specified data exists in the list and returns true if it does,
//else it returns false
template <class T>
bool LinkedList<T>::ElementExists(T data){
    if(head == NULL){
        return false;
    }
    
    Node<T> *temp = new Node<T>();
    temp = head;

    while(temp != NULL){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//this method finds some specified data in the list and returns a pointer to that data if it exists, 
//else it returns NULL
template <class T>
Node<T>* LinkedList<T>::Find(T data){
    Node<T> *temp = new Node<T>();
    temp = head;

    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//this method finds some specified data in the list and returns the index of that data if it exists, 
//if the data doesent exists it returns -1
template <class T>
int LinkedList<T>::IndexOf(T data){
    if(head == NULL){
        return -1;
    }

    Node<T> *temp = new Node<T>();
    temp = head;
    int count = 0;

    while(temp != NULL){
        if(temp->data == data){
            return count;
        }
        temp = temp->next;
        count ++;
    }
    return -1;
}

//this method retrieves the first element in the list and returns the data in that element
template <class T>
T LinkedList<T>::RetrieveFront(){
    if(head == NULL){
        return -1;
    }

    else{
        return head->data;
    }
}

//this method retrieves the last element in the list and returns the data in that element
template <class T>
T LinkedList<T>::RetrieveEnd(){
    if(head == NULL){
        return -1;
    }

    Node<T> *temp = new Node<T>();
    temp = head;
    int data = -1;

    while(temp != NULL){
        data = temp->data;
        temp = temp->next;
    }
    return data;
}

//this method finds the element containing some specified data and returns the index of that element,
//if the index doesent exist it returns -1
template <class T>
T LinkedList<T>::Retrieve(int index){
    Node<T> *temp = new Node<T>();
    temp = head;
    int count = 0;
    while(temp != NULL){
        if(count == index){
            return temp->data;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

//this method prints the list with the first element on the left and the last element on the right,
//with a space in between each element
template <class T>
void LinkedList<T>::PrintList(){
    Node<T> *temp = head;
    if(temp == NULL){
        return;
    }

    if(temp->next == NULL){
        cout<< temp->data << endl;
        return;
    }
    else{
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << "\n";
}

//this method emptys out the whole list leaving the head pointing to NULL
template <class T>
void LinkedList<T>::Empty(){
    Node<T> *node = head;
    Node<T> *tempNode;

    while(node != NULL){
        tempNode = node;
        delete tempNode;
        node = node->next;
    }
    head = NULL;    
}

//this mehtod finds the lenght of the list and returns it as an int
template <class T>
int LinkedList<T>::Length(){
    if(head == NULL){
        return 0;
    }

    Node<T> *temp = head;
    int count = 0;

    while(temp != NULL){
        count += 1;
        temp = temp->next;
    }
    return count;
}

//this is a method that is not part of the rubric but I used to test the list
//it gets the last element in the list and returns a pointer to that element
template <class T>
Node<T>* LinkedList<T>::getlast(){
    if(head == NULL){
        return NULL;
    }

    Node<T> *temp = new Node<T>();
    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

#endif