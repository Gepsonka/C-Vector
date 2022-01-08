#include <stdio.h>
#include "./vector/vector-c.h"


int main(){
    vector v= createVector(7, 1, 5, 4, 103, 45, 50, 60);
    del(&v,5);

    for (int i=0;i<v.units;i++){
        printf("%d ",v.vec[i]);
    }
    printf("\nunits: %d\n",v.units);
    freeVector(&v);
}

// |5|2|8|3|0|6|7|