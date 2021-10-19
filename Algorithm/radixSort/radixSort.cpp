
/*
164. Maximum Gap
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109


*/


/*
Comments:
S1: find the largest value as the upper value

S2: define the carry 

S3: 
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        // find the max value
        int largest = nums[0];
        for(auto& t: nums){
            largest = largest > t? largest : t;
        }
        // calculate the number of the carries
        int carry = 0;
        
        while( int(largest / pow(10,carry)) != 0){
            carry++;
        }
        /* same functionality as above, find the total digits number
        int temp = largest;
         while (temp != 0) {
            carry++;
            temp /= 10;
        }*/

        vector<int> res(nums.size(),0);

        int dev = 1;
        for(int i=0; i<carry; i++){
            vector<int> counter(10,0);

            for(int j=0; j<nums.size();j++){
                int digit = (nums[j] / dev) % 10;
                counter[digit]++;
            }

            for(int k=1; k<counter.size(); k++){
                counter[k] += counter[k-1];
            }
            for(int k=nums.size()-1; k>=0; k--){
                int digit = (nums[k] / dev) % 10;
                res[--counter[digit]] = nums[k];          
            }
            nums = res;
            dev *= 10;
        }
        
        int ret = 0;
        for(int i=1; i<nums.size(); i++){
            int dist = nums[i] - nums[i-1];
            ret = ret > dist ? ret : dist;
        }
        
        /*
        int ret = 0;
        for (int i = 1; i < nums.size(); i++) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }*/
        return ret;

    }
};