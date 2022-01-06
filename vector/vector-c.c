//
// Created by gepsonka on 2022. 01. 06..
//
#include <stdlib.h>
#include "vector-c.h"

//create vector for ints
vector createEmptyVector() {
    vector vec;
    //vector* vec=(vector*) malloc(sizeof(vector));
    vec.vec =(int*) calloc(10,sizeof(int));
    return vec;
}


vector createVector(unsigned int count,...){
    vector vec;
    vec.vec =(int*) calloc(count,sizeof(int));
    vec.units=count;

    va_list ap;
    va_start(ap,count);
    for (int i=0;i<count;i++){
        vec.vec[i]= va_arg(ap,int);
    }
    va_end(ap);
    return vec;
}


void freeVector(vector *vec){
    free(vec->vec);
}

// Insert a number to the end of the vector
vector* push(vector *vec, int val) {
    unsigned int cpy[vec->units];
    for (int i=0;i<vec->units;i++){
        cpy[i]=vec->vec[i];
    }

    vec->vec=realloc(vec->vec,(vec->units+1) * sizeof(int));
    for(int i=0;i<vec->units;i++){
        vec->vec[i]=cpy[i];
    }

    vec->units++;
    vec->vec[vec->units-1]=val;

    return vec;
}

vector* insert(vector* vec, int val, unsigned int poz){
    unsigned int cpy[vec->units];
    for (int i=0;i<vec->units;i++){
        cpy[i]=vec->vec[i];
    }

    vec->vec=realloc(vec->vec,(vec->units+1) * sizeof(int));
    for(int i=0;i<vec->units+1;i++){
        if (i<poz){
            vec->vec[i]=cpy[i];
        }
        else if (i>poz){
            vec->vec[i]=cpy[i-1];
        }
        else {
            vec->vec[i]=val;
        }
    }
    vec->units++;
    return vec;

}
