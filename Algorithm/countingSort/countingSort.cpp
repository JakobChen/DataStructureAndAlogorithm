/*

912. Sort an Array
Given an array of integers nums, sort the array in ascending order.


Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

*/

/*
Comments: 

S1: find the range (min, max) of the given arrays
S2: Counter the elements in ther counter arrays. 
Here needs to pay attention to map the range into (0, max-min+1), max - min + 1 is the size of the counter array.
S3: Index of the element position i is equal to counter[element-min]. 
Consider the repeat value case in the given array, counter[element-min] after asigning to the result array needs to increase by 1.
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int min = nums[0];
        int max = nums[0];
        // find the low and high boundary
        for(auto& t : nums){
            if(t > max) max = t;
            else if(t < min) min = t;
        }
        // create counter array
        int size = max - min +1;
        vector<int> counter(size,0);
        for(int i=0; i<nums.size(); i++){
            counter[nums[i]-min]++; // map the value in range [0, max-min+1)
        }
        int prev = 0;
        for(int i=0; i<counter.size(); i++){
            int temp = counter[i];
            counter[i] = prev;
            prev  += temp;
        }
        vector<int> res(nums.size(),0);
        for(int i=0; i<nums.size();i++){
            int index = nums[i] - min;
            res[counter[index]] = nums[i];
            counter[index]++; // increase the position with repeat values
        }
        return res;
    }
};