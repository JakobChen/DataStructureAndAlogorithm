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


/*Best version*/
class Solution {
public:
   

    int maxDepth(TreeNode* root) {
        //constrains
        if(root == nullptr) return 0;
        // return value
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*second version*/
class Solution {
public:
   

    int maxDepth(TreeNode* root) {
        //constrains
        if(root == nullptr) return 0;
        //sub problems
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // return value
        return max(leftDepth, rightDepth) + 1;
    }
};


/*first version*/
class Solution {
public:
    int maxValue=0;
    void maxDepthFunc(TreeNode* node, int depth){
     
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            maxValue = maxValue > depth? maxValue:depth;
        }
        maxDepthFunc(node->left, depth+1);
        maxDepthFunc(node->right, depth+1);
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        maxDepthFunc(root,1);
        return maxValue;
    }
};