//
// Created by gepsonka on 2022. 01. 06..
//

#ifndef C_VECTOR_VECTOR_C_H
#define C_VECTOR_VECTOR_C_H

#include <stdarg.h>
#include <stdio.h>


struct vector{
    unsigned int units;
    int* vec;
};

typedef struct vector vector;

vector createEmptyVector();
vector createVector(unsigned int elements,...);
void freeVector(vector *vec);


vector* push(vector* vec, int val);
vector* insert(vector* vec, int val, unsigned int poz);
vector* del(vector* vec, unsigned int poz);


#endif //C_VECTOR_VECTOR_C_H
