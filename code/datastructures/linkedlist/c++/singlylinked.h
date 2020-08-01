//singlylinked
//Drew Gotshalk
//2020-07-28

#ifndef SINGLYLINKED_H
#define SINGLYLINKED_H

template <class T>
class Node {
        public:
                Node(T value, Node<T> * ptr =nullptr): info{value}, next{ptr} {};
                T info;
                Node<T> *next;
};

template <class T>
class Singly_Linked_List {
        private:
                int size; 
                Node<T> *head;
                Node<T> *tail;
        public:
                Singly_Linked_List() { head = tail = nullptr; size = 0;};
                ~Singly_Linked_List();
                int Valid(int index);
                int Size() {return size;};
                bool Empty();
                T Value_at(int index);
                void Push_front(T value);
                T Pop_front();
                void Push_back(T value);
                T Pop_back();
                T Front();
                T Back();
                void Insert(int index,T value);
                void Delete(int index);
                T Value_n_from_end(int n);
                void Reverse();
                bool Remove_value(T value);


};



#endif // !SINGLYLINKED_H 
