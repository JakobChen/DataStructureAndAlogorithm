/*
561. Array Partition I
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 

Constraints:

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104

*/



class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //find the largest and min
        int largest = nums[0];
        for(auto &t : nums){
            largest = largest>t ? largest : t;
        }
        // calculate the carry
        int carry = 0;
        while(int(largest / pow(10,carry)) != 0){
            carry++;
        }
        
        // temporary vector
        vector<int> res(nums.size(),0);
        int dev = 1;
        for(int i=0; i < carry; i++){
            vector<int> counter(19,0);

            // counter
            for(int j=0; j<nums.size(); j++){
                int radix = nums[j] / dev % 10 +9; //(0,18]
                counter[radix]++;
            }

            // sum of the prev values
            
            for(int k = 1; k<counter.size();k++){
                counter[k] += counter[k-1]; 
            }

            // update the value
            
            for(int p = nums.size()-1; p>=0; p--){
                int radix = nums[p] / dev % 10 + 9 ;
                res[--counter[radix]] = nums[p]; 
            }
            nums = res;
            dev *= 10;
        }
        int minVal = 0;
        /*
        int i = 0;
        while(i < nums.size()){
            minVal += nums[i]; 
            i += 2;
        }*/
        for(int i=0; i<nums.size(); i+=2){
            minVal += nums[i];
        }
        return minVal;


    }
};