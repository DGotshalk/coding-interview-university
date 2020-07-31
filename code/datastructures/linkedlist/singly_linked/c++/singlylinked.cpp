//singlylinked
//Drew Gotshalk
//2020-07-28
#include <iostream>
#include <string>
#include "singlylinked.h"


template<class T>
int Singly_Linked_List<T>::Valid(int index){
        if (Empty() == true){
                //std::cout << "Empty List" << std::endl;
                return -1;
        }
        else if (index > Size() || index < 0){
                //std::cout << "Invalid Index" << std::endl;
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
                return head->info;
        }
        else if (index == size){
                return tail->info;
        }
        else{
                Node<T>* tmp = head;
                for (int i = 0; i < index; ++i)  
                        tmp = tmp->next;
                return tmp->info;
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
        T val = head->info;
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
                T val = tail->info;
                delete tmp;
                size--;
                return val; 
        }
        else {
                Node<T>* tmp = head;
                for(;tmp->next != tail; tmp = tmp->next){} 
                T val = tail->info;
                delete tmp->next;
                tail = tmp;
                size--;
                return val;
        }        
};

template <class T>
T Singly_Linked_List<T>::Front(){
        return head->info;
}

template <class T>
T Singly_Linked_List<T>::Back(){
        return tail->info;
}

template <class T>
void Singly_Linked_List<T>::Insert(int index, T value){
        if (Empty()){
                head = tail = new Node<T>(value);
                size++;
                return;
        }
        else if (index == 0){
                Push_front(value);
                return;
        }
        else if (index == size-1){
                Push_back(value);
                return;
        }
        else{
                Node<T>* iter = head;
                Node<T>*tmp;
                for (int i=0; i < index; ++i){
                        tmp = iter;
                        iter = iter->next;
                }
                tmp->next = new Node<T>(value, iter);
                size++;
                return;
        }
}

//cases:
//empty list? (would check before deletion maybe
//1 item in list
//from head
//from tail
template <class T>
void Singly_Linked_List<T>::Delete(int index){ 
        if (index == 0){
                Pop_front();
        }
        else if (index == size -1){
                Pop_back();
        }
        else {
        
                Node<T>* iter = head;
                Node<T>* tmp;
                for (int i=0; i < index; ++i){
                        tmp = iter;
                        iter = iter->next;
                } 
                tmp->next = iter->next;
                delete iter;
                size--;
                return;
        }
}

template <class T>
T Singly_Linked_List<T>::Value_n_from_end(int n){
        int index = size-n-1;
        Node<T>* iter = head;
        for (int i = 0; i < index; i++){
                iter = iter->next;
        }
        return iter->info;
}

template <class T>
void Singly_Linked_List<T>::Reverse(){
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        tail = head;
        while (current != nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
       }
        head = prev;
}

template <class T>
bool Singly_Linked_List<T>::Remove_value(T value){
        Node<T>* tmp = head;
        Node<T>* prev = nullptr;
        if (tmp->info == value){
                head = tmp->next;
                delete tmp;
                return true;
        }
        prev = tmp;
        tmp = tmp->next;
        while (tmp->next != nullptr){
                if (tmp->info == value){
                        if (tmp == tail){
                                tail = prev;       
                                prev->next = tmp->next;
                                delete tmp;
                                return true;
                        }
                        prev->next = tmp->next;
                        delete tmp;
                        return true;
                }
                else{
                        prev = tmp;
                        tmp = tmp->next;
                }
        }
        return false;
}
