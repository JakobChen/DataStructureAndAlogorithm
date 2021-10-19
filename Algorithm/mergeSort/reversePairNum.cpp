/*
剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

*/




class Solution {
public:
    int sum =0;
    int reversePairs(vector<int>& nums) {
        return partition(nums, 0, nums.size()-1);
;
    }
    int partition(vector<int>& nums, int left, int right){
        if(left >= right) return 0;
        int mid = left + (right -left) / 2;
        int res = partition(nums, left, mid) + partition(nums, mid+1, right);
        
        res += coutNum(nums, left, mid, right);
        return res;
    }
    int coutNum(vector<int> & nums, int left, int mid, int right){
        int size = right - left +1;
        vector<int> mergeArr(size,0);
        int i = left;
        int j = mid+1;
        int index = 0;
        int count = 0;
        while(i <=mid && j <=right){
            if(nums[i] <= nums[j]){
                mergeArr[index++] = nums[i++];
            }else{
                mergeArr[index++] = nums[j++];
                count += mid - i +1;
            }
        }
        while(i <= mid){
            mergeArr[index++] = nums[i++];
        }
        while(j <= right){
            mergeArr[index++] = nums[j++];
        }
        for(int i=left; i<=right; i++){
            nums[i] = mergeArr[i-left];
        }
        return count;
    }
};
