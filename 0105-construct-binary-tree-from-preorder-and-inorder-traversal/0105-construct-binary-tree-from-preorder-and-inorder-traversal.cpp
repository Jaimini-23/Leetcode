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
    TreeNode* buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int, int> &mp) {
        if(ps > pe || is > ie) return NULL;
        TreeNode* newNode = new TreeNode(preorder[ps]);
        int inRoot = mp[newNode->val];
        int numsLeft = inRoot - is;

        newNode->left = buildTree(preorder, ps + 1, ps + numsLeft, inorder, is, inRoot - 1, mp);
        newNode->right = buildTree(preorder, ps + numsLeft + 1, pe, inorder, inRoot + 1, ie, mp);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size() || inorder.empty()) return NULL;
        map<int,int> mp;
        for(int i=0; i < inorder.size(); i++) mp[inorder[i]] = i;
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);

        return root;
    }
};