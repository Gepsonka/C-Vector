//
// Created by gepsonka on 2022. 01. 07..
//

#ifndef C_VECTOR_LINKED_LIST_H
#define C_VECTOR_LINKED_LIST_H


struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* createEmptyNode();
Node* createNode(unsigned int elements, ...);

Node* insert(Node* n, unsigned int poz, int val);
Node* push(Node* n);
Node* del(int poz);


#endif //C_VECTOR_LINKED_LIST_H
