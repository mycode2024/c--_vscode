//144. 二叉树的前序遍历
//145. 二叉树的后序遍历
//94. 二叉树的中序遍历
//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
//https://leetcode.cn/problems/binary-tree-postorder-traversal/
//https://leetcode.cn/problems/binary-tree-inorder-traversal/


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//迭代遍历
class Iterate_through{
public:

    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            if (temp != nullptr) {
                 vec.push_back(temp->val);
            } else {
                continue;
            }
            st.push(temp->right);
            st.push(temp->left);
        }
        return vec;
    }

    //后序遍历
    vector<int> endorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            if (temp != nullptr) {
                 vec.push_back(temp->val);
            } else {
                continue;
            }
           
            st.push(temp->left);
            st.push(temp->right);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    } 

    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {//循环条件的判断注意
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                vec.push_back(cur->val);
                cur = cur->right;
            }
        }
        return vec;
    } 
};