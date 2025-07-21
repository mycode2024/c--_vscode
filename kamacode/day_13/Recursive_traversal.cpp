//144. 二叉树的前序遍历
//145. 二叉树的后序遍历
//94. 二叉树的中序遍历
//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
//https://leetcode.cn/problems/binary-tree-postorder-traversal/
//https://leetcode.cn/problems/binary-tree-inorder-traversal/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Recursive_traversal{
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preorder(root,vec);
        return vec;
    }

    void preorder(TreeNode* root,vector<int>& vec) {
        if (root == nullptr) {
            return ;
        } 
        vec.push_back(root->val);//前序
        preorder(root->left,vec);
        vec.push_back(root->val);//中序
        preorder(root->right,vec);
        vec.push_back(root->val);//后序
    }
};