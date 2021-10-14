class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> minK(k,0);
        if(k==0){
            return minK;
        }
        priority_queue<int> que;
        for(int i=0;i<k;i++){
            que.push(arr[i]);
        }
        for(int i=k; i<arr.size();i++){
            //compare the max que to the current value, if max que > current value, then swap them
            if(arr[i] < que.top()){
                que.pop();
                que.push(arr[i]);
            }
        }
        for(int i=0;i<k;i++){
            minK[i] = que.top();
            que.pop();
        }
        return minK;
    }
};