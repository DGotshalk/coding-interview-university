//linkedlist
//Drew Gotshalk
//2020-08-01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
        int data;
        struct  Node *next;
        
};

struct Node* head = NULL;
struct Node* tail = NULL;
int size = 0;

void Create_linked_list(int data){
        struct Node* newnode = malloc(sizeof(struct Node));
        newnode->data = data; 
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
        ++size;
};

void Insert(int index, int data){
        if (index == 0){
                struct Node* newhead = malloc(sizeof(struct Node));
                newhead->next = head;
                newhead->data = data; 
                head = newhead;
                size++;
                return;
        }
        else if (index == size){
                struct Node* newtail = malloc(sizeof(struct Node));
                newtail->data = data;
                newtail->next = NULL;
                tail->next = newtail;
                tail = newtail;
                ++size;
                return;
        }
        else{
                struct Node* prev = NULL;
                struct Node* iter = head;
                for (int i = 0; i < index; ++i){
                        prev = iter;
                        iter = iter->next;
                }
                struct Node* newnode = malloc(sizeof(struct Node));
                newnode->data = data;
                prev->next = newnode;
                newnode->next = iter;
                size++;
                return;
        }
};

void Delete(int index){
        if (index == 0){ 
                struct Node* newhead;
                newhead = head->next;
                free(head);
                head = newhead;
                --size;
                return;                
        }
        else{
                struct Node* prev = NULL;
                struct Node* iter = head;
                for (int i = 0; i < index ; ++i){
                        prev = iter;
                        iter = iter->next;
                }
                prev->next = NULL;
                tail = prev;
                free(iter);
                --size;
                return;
        }
};

void Display(){
        struct Node* iter= head;
        if (iter == NULL){
                printf("List is empty\n");
                return; 
        }
        printf("%d\n",iter->data);
        for(int i = 0; i < size-1; ++i){
                iter= iter->next;
                printf("%d\n",iter->data);
        }
};

int main(){ 
        Create_linked_list(12);
        return 0;
}
