/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        queue<TreeNode*> nodes;
        queue<int> data;
        nodes.push(root);
        data.push(root->val);
        while(!nodes.empty()){
            TreeNode* tempNode = nodes.front();
            int sum = data.front();
            nodes.pop();
            data.pop();
            //no sub tree, check wheathe the targetSum is equal to the sum of the path.
            if(!tempNode->left && !tempNode->right && targetSum==sum){
                return true;
            }
            //push left sub tree into queque
            if(tempNode->left){
                nodes.push(tempNode->left);
                data.push(sum + tempNode->left->val);
            }
            if(tempNode->right){
                nodes.push(tempNode->right);
                data.push(sum + tempNode->right->val);
            }

        }
        return false;

    }
};