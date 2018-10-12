/* 67. Binary Tree Inorder Traversal

描述

给出一棵二叉树,返回其中序遍历
您在真实的面试中是否遇到过这个题？
样例

给出二叉树 {1,#,2,3},

   1
	\
	 2
	/
   3

返回 [1,3,2].
挑战

你能使用非递归算法来实现么?
*/


#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Definition of TreeNode:*/
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	 * @param root: A Tree
	 * @return: Inorder in ArrayList which contains node values.
	 */
	vector<int> inorderTraversal(TreeNode * root) {
		vector<int> result;
		if (root == NULL)
			return result;

		vector<int> left = inorderTraversal(root->left);
		result.insert(result.end(), left.begin(), left.end());

		result.push_back(root->val);

		vector<int> right = inorderTraversal(root->right);
		result.insert(result.end(), right.begin(), right.end());

		return result;
	}
};

/* pre-order 
class Solution {
public:
   
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> result;
        if (!root)
        return result;
        
        result.push_back(root -> val);
        
        vector<int> left = preorderTraversal (root -> left);
        vector<int> right = preorderTraversal (root -> right);
        
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
    }
};
*/

/*post-order
class Solution {
public:
   
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> result;
        if (!root)
        return result;
        
        vector<int> left = postorderTraversal( root -> left);
        vector<int> right = postorderTraversal( root -> right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root -> val);
        return result;
    }
};
*/
	
int main()
{
    std::cout << "Don't be afraid of Binary Tree.\n"; 
}
