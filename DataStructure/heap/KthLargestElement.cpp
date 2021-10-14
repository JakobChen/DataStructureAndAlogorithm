class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> que;
        for(auto& t: nums){
            que.push(t);
        }
        for(int i=0;i<k-1;i++){
            que.pop();
        }
        return que.top();
    }
};