

/*

面试题 10.01. Sorted Merge LCCI
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.

Initially the number of elements in A and B are m and n respectively.

Example:

Input:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
Note:

A.length == n + m
*/

/*
Comments: 
1. initialize the vector with size number         vector<int> mergeArr(m+n, 0);
2. asign vector vec2 to vector vec1        vec1 = vec2
*/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> mergeArr(m+n, 0);
        int indexA = 0;
        int indexB = 0;
        int index = 0;
        while(indexA<m && indexB<n){
            if(A[indexA] < B[indexB]){
                mergeArr[index++] = A[indexA];
                indexA++;
            }else{
                mergeArr[index++] = B[indexB];
                indexB++;
            }
        }
        // 
        if(indexA != m){
            for(int i= indexA; i<m; i++){
                mergeArr[index++] = A[i];
            }
        }
        if(indexB != n){
            for(int i= indexB; i<n; i++){
                mergeArr[index++] = B[i];
            }
        }

        A = mergeArr;
    }
};