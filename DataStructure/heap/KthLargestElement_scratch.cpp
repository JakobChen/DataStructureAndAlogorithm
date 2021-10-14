class Solution {
public:
    void maxHeapify(vector<int>&nums,int i, int heapSize){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i +2;
        if(left < heapSize && nums[largest]<nums[left]) largest = left;
        if(right < heapSize && nums[largest]<nums[right]) largest = right;
        if(largest!=i){
            int temp = nums[largest];
            nums[largest] = nums[i];
            nums[i] = temp;
            maxHeapify(nums, largest,heapSize);
        }
    }
    void buildMaxHeap(vector<int>& nums, int heapSize){
        for(int i=heapSize/2;i>=0;i--)
        {
            maxHeapify(nums, i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {  
        // initialize the heap
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for(int i = nums.size()-1; i>=nums.size()-k+1;--i){
            swap(nums[0],nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};
