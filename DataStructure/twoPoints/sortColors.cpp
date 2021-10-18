
/*
75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/




class Solution {
public:
    void swap(int& a , int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        //All in [0,p1) == 0
        //[p1, i) == 1;
        //[p2,len-1] == 2;
        if(nums.size() < 2) return;
        int i = 0;
        int p1 = 0;
        int p2 = nums.size()-1;
        while(i<=p2){
            if(nums[i] == 0){
                swap(nums[p1], nums[i]);
                p1++;
                i++;
            }else if(nums[i] ==1){
                i++;
            }else{
                // nums[i] == 2
                swap(nums[i],nums[p2]);
                p2--;
            }
        }
    }
};