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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        cout<<preorder[0];
        TreeNode* curr = NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stack;
        stack.push(root);
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i] < stack.top()->val)
            {
                stack.top()->left = new TreeNode(preorder[i]);
                stack.push(stack.top()->left);
            }
            else
            {
                while(stack.empty() ==false && stack.top()->val < preorder[i])
                {
                    curr = stack.top();
                    stack.pop();
                }
                curr->right = new TreeNode(preorder[i]);
                stack.push(curr->right);
            }
        }
        return root;

    }
};