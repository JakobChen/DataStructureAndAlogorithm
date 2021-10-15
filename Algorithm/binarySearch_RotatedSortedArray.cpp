/*
33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104


*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        if(n == 1) return nums[0] == target?0:-1;
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left <= right){
            mid = left + (right -left) /2;
            // nums[mid] < nums[0] [mid, right] sorted
            // nums[mid] > nums[0] [left mid] sorted;
            if(nums[mid] == target) return mid;
            // important to ensure the nums[mid] == nums[0] case, this shoud be coved in the left part. 
            // Otherwise, nums[0] > nums[n-1] ->> nums[mid] > nums[n-1], then right--, the case nums[0] == nums[mid] will never be reached.
            if(nums[mid] >= nums[0]){
                if(target >= nums[0] && target < nums[mid] ){
                    right = mid -1;
                }else{s
                    left = mid +1;
                }
            }
            else{
                if(target > nums[mid] && target <=nums[n-1] ){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }  
        }
        return -1;
    
    }
};