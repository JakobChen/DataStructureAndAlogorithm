
/*
912. Sort an Array
Medium

1389

450

Add to List

Share
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

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void mergeSort(vector<int>&nums, int left, int right){
        // Recursion stop condition
        if(left>=right) return;
        int mid = left + (right -left)/2;
        // left partion for sorting
        mergeSort(nums, left, mid);
        // right partion for sorting
        mergeSort(nums, mid+1,right);
        // merge the sorted left and right arrays
        merge(nums, left, mid, right);
    }
    
    void merge(vector<int>&nums, int left,int mid, int right) {
        int size = right - left +1;
        
        vector<int> mergeArr(size, 0);
        int i = left;
        int j = mid+1;
        int index = 0;
        while(i<=mid && j<=right){
            if(nums[i] < nums[j]){
                mergeArr[index++] = nums[i++];
            }else{
                mergeArr[index++] = nums[j++];
            }
        }
        // asign the rest of the element to the mergeArr from the not fully iterated array
        while(i != mid+1){
                mergeArr[index++] = nums[i++];
        }
        while(j != right+1){
                mergeArr[index++] = nums[j++];
        }
        // asign the merged sorted array to the nums array with the corresponding segment.
        for(int i= left; i<=right;i++){
            nums[i] = mergeArr[i-left];
        }

    }
    
};