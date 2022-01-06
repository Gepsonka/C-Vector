#include <stdio.h>
#include "./vector/vector-c.h"


int main(){
    vector v= createVector(4,1,5,4,10);
    insert(&v,100,4);

    for (int i=0;i<v.units;i++){
        printf("%d ",v.vec[i]);
    }
    printf("\n%d\n",v.units);
    freeVector(&v);
}

