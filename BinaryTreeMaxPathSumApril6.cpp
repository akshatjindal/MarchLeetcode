/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * };
 */
struct TreeNode{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 
#include <bits/stdc++.h>
#include <algorithm> 
using namespace std; 


class Solution {
private: 
    int globalMax = INT_MIN; 
public:
    int dfs(TreeNode * node){
        if(node == nullptr){
            return 0; 
        }
        int leftVal = dfs(node->left); 
        int rightVal = dfs(node->right); 
        globalMax = std::max(globalMax, node->val + rightVal + leftVal); 
        return std::max(0, node->val + std::max(leftVal,rightVal));
    }//return dfs
    int maxPathSum(TreeNode* root) {
        dfs(root); 
        return globalMax; 
    }//return maxPathSum
};