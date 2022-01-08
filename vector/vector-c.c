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
    int cpy[vec->units];
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

// Inserting number to the given Position
vector* insert(vector* vec, int val, unsigned int poz){
    // Copy the current vector;
    int cpy[vec->units];
    for (int i=0;i<vec->units;i++){
        cpy[i]=vec->vec[i];
    }

    // Reallocate the memory with +1 int
    vec->vec=realloc(vec->vec,(vec->units+1) * sizeof(int));
    for(int i=0;i<vec->units+1;i++){
        // If we did not reach the given position yet
        // We just copy back in the usual way
        if (i<poz){
            vec->vec[i]=cpy[i];
        }
        //If the i is bigger then the position, then
        // insert the i'th place of the vector from the i-1'th place of the
        // cpy array.
        // This is necessary because one place is left out without inserting from cpy.
        else if (i>poz){
            vec->vec[i]=cpy[i-1];
        }
        // If the desired position is reached, the given number is inserted.
        else {
            vec->vec[i]=val;
        }
    }
    // At successful insert the number of elements in increased
    vec->units++;
    return vec;

}

// Deleting int from vector.
vector *del(vector *vec,unsigned int poz) {
    // Divide it into 2 sub arrays
    int cpy1[poz];
    unsigned int cpy1_size = poz;
    for (int i = 0 ; i < poz ; i++){
        cpy1[i]=vec->vec[i];
    }

    int cpy2[vec->units-poz-1];
    unsigned int cpy2_size = vec->units-poz-1;
    for (int i = 0; i < vec->units-poz-1;++i){
        cpy2[i]=vec->vec[i+poz+1];

    }

    vec->vec= realloc(vec->vec,(vec->units-1) * sizeof(int));
    for (int i = 0; i < cpy1_size; i++){
        vec->vec[i]=cpy1[i];

    }

    for (int i = cpy1_size; i < cpy2_size+cpy1_size; i++){
        vec->vec[i]=cpy2[i-cpy1_size];
    }

    vec->units--;
    return vec;
    // FIXME: does not work yet
}
