#ifndef linkedlist
#define linkedlist

#define SIZE = 10

#include <string>
#include <iostream>
#include "iterator.hpp"

template<class T>
class LinkedList {

    private:

    struct element{
        const T value;
        struct element* next;
        
        element(const T value, element* next) : value(value), next(next) {}
    };

    element* head;
    element* tail;

//    #ifndef LISTITERATOR_HPP
//    #define LISTITERATOR_HPP

    class ListIterator : public Iterator<T>{
        private:
            element* start;

        public:
            ListIterator(const LinkedList<T> &list) : start{list.head} {}
            bool hasNext() override;
            const T next() override;
       
    };


//    #endif

    public:

    LinkedList();
    LinkedList(const LinkedList &org);
    ~LinkedList();

    Iterator<T>* iterator();

    int append(const T text);

    int insert(const T text, int p);

    int remove(int p);

    T get(int p);

    int index_of(const T text);

    const T first();

    const T last();

    void visit_all(void (*work)(T t));

};

#endif

template<class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &org) : LinkedList() {
    
    struct element* start = org.head;

    while(start != nullptr){
        append(start->value);
        start = start->next;
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    std::cout << "Objekt gelöscht"
        << std::endl;
}

template<class T>
int LinkedList<T>::append(const T text){
    if(head == nullptr){
        head = new element(text, tail);
        tail = head;
        return 1;
    }else{
       tail = tail->next = new element(text, nullptr);
       return 1;
    }

    return 0;
}

template<class T>
int LinkedList<T>::insert(const T text, int p){
    if(head == nullptr) append(text);
    struct element* start = head;

    for(int i = 0; i != p; i++){
        if(start->next == nullptr)
            start->next->value = text;

        if(start != nullptr){
            i++;
            start = start->next;
        }
    }

    return 0;
}

template<class T>
int LinkedList<T>::remove(int p){
    if(head == nullptr) return 0;

    struct element* start = head;
    int count = 0;

    for(int i = 0; i < p; i++){
        if(start->next == nullptr){
            start = nullptr;
            delete start;
            return 1;
        }else{
            start = start->next;
        }   
    }

    struct element* tmp = start;
    while(tmp != nullptr){
        tmp=tmp->next;
        
    }
    
    start = nullptr;

    return count;
}

template<class T>
T LinkedList<T>::get(int p){
    if(p == 0) return head-> value;

    struct element* start = head;

    for(int i = 0; i != p; i++){
        start = start->next;
    }

    if(start == nullptr) return nullptr;

    return start->value;
}

template<class T>
int LinkedList<T>::index_of(const T text){
    struct element* start = head;
    int i = 0;

    while(start != nullptr){
        //if(strcmp(start->value, text) == 0){
        if(0 ==0){
            return i;
        }else{
            i++;
            start = start->next;
        }
    }

    return -1;
}

template<class T>
const T LinkedList<T>::first(){
    return head->value;
}

template<class T>
const T LinkedList<T>::last(){
    return tail->value;
}

template<class T>
Iterator<T> *LinkedList<T>::iterator(){
   return new ListIterator(*this);
}

template<class T>
void LinkedList<T>::visit_all(void (*work)(T t)){
    Iterator<T> *it = iterator();

    while(it->hasNext()){
        work(it->next());
    }

}

template<class T>
bool LinkedList<T>::ListIterator::hasNext(){
    return start != nullptr ? true : false;
}

template<class T>
const T LinkedList<T>::ListIterator::next(){
    const T tmp = start->value;
    start = start->next;

    return tmp;
 }
