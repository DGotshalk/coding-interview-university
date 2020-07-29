//singlylinked
//Drew Gotshalk
//2020-07-28
#include <iostream>
#include <string>
#include "singlylinked.h"


template<class T>
int Singly_Linked_List<T>::Valid(int index){
        if (Empty() == true){
                std::cout << "Empty List" << std::endl;
                return -1;
        }
        else if (index > Size() || index < 0){
                std::cout << "Invalid Index" << std::endl;
                return 1;
        }
        return 0;
};

template<class T>
bool Singly_Linked_List<T>::Empty(){
        if (head == tail == nullptr)
                return true;
        else
                return false;
};

template<class T>
T Singly_Linked_List<T>::Value_at(int index){
        if (index == 0){
                return head.info;
        }
        else if (index == size){
                return tail.info;
        }
        else{
                Node<T>* tmp = head;
                for (int i = 0; i < index; ++i)  
                        tmp = tmp->next;
                return tmp.info;
        }
};

template<class T>
void Singly_Linked_List<T>::Push_front(T value){
        head = new Node<T>(value, head);
        if (tail == nullptr)
                tail = head;
        size++;
};

template<class T>
T Singly_Linked_List<T>::Pop_front(){
        T val = head.info;
        Node<T>* tmp = head;
        if (head->next == nullptr)
                head = tail =  nullptr; 
        else
                head = head->next;
        delete tmp;
        size--;
        return val;
};

template<class T>
void Singly_Linked_List<T>::Push_back(T value){
        tail->next = new Node<T>(value);
        tail = tail->next;
        if (head == nullptr)
                head = tail;
        size++;
};

template<class T>
T Singly_Linked_List<T>::Pop_back(){
        if (tail == head){
                Node<T>* tmp = tail;
                T val = tail.info;
                delete tmp;
                size--;
                return val; 
        }
        else {
                Node<T>* tmp = head;
                for(;tmp->next != tail; tmp = tmp->next){} 
                T val = tail.info;
                delete tmp->next;
                tail = tmp;
                size--;
                return val;
        }        
};

