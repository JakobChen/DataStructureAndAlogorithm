
/*
702. Search in a Sorted Array of Unknown Size
This is an interactive problem.

You have a sorted array of unique elements and an unknown size. You do not have an access to the array but you can use the ArrayReader interface to access it. You can call ArrayReader.get(i) that:

returns the value at the ith index (0-indexed) of the secret array (i.e., secret[i]), or
returns 231 - 1 if the i is out of the boundary of the array.
You are also given an integer target.

Return the index k of the hidden array where secret[k] == target or return -1 otherwise.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: secret = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in secret and its index is 4.
Example 2:

Input: secret = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in secret so return -1.
 

Constraints:

1 <= secret.length <= 104
-104 <= secret[i], target <= 104
secret is sorted in a strictly increasing order.

*/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

/*
S1: dynamicaly increasing the range to cover the target
S2: bianry serach find the the index of the target in the array 
*/


class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // search boudery
        int left = 0;
        int right = 1;
        while(reader.get(right) < target){
            left = right;
            right = right * 2;
        }
        // binary serach
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(reader.get(mid) < target){
                left = mid + 1;
            }else if(reader.get(mid) > target)){
                right = mid - 1;
            }else{ // find the target
                return mid;
            }
        }
        return -1;
    }
};