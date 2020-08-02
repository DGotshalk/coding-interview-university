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
        struct Node *newnode = malloc(sizeof(struct Node));
        newnode->data = data; 
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
};


int main(){ 
        Create_linked_list(12);
        return 0;
}
