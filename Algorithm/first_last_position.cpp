/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/


class Solution {
public:
    int  binarySearch(vector<int>& nums, int target, bool lower){
        int mid,left = 0;
        int right = nums.size() -1;
        int ans = nums.size();
        while(left <= right){
            mid = left + (right - left) / 2; 
            if(nums[mid] > target || (lower && nums[mid] >= target)){
                right = mid - 1;
                ans = mid;
            }else{
                left = mid + 1;
            }
        } 
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int start = binarySearch(nums, target, true);
        int end = binarySearch(nums, target, false)-1;
        if(start <= end && end < nums.size() && nums[start] == target && nums[end]==target){
            return {start,end}; 
        }
        cout << start << " " << end;
        return {-1,-1};
    
    }
};