//ANKI APRIL 11
#include <bits/stdc++.h>
#include <algorithm> 


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

using namespace std; 

class Solution {
    private: 
    int global_max = INT_MIN; 
public:
    int dfs(TreeNode* node){
        //base case:
        if(node == nullptr){
            return 0; 
        }

        int leftVal = dfs(node->left); 
        int rightVal = dfs(node->right); 
        global_max = max(global_max, node->val + leftVal + rightVal); 
        return max(0, node->val + max(leftVal, rightVal));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root); 
        return global_max; 
    }
};