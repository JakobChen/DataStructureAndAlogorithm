#include <iostream>
#include <cstdio>
#include <assert.h>   

float mean(int arr[], int size){
    if(size == 0) return 0;
    float sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    return sum/size;
}

int main (int argc, char *argv[]){
    // test cases:
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    assert(mean(arr, size) == (float)3);
    return 0;
}