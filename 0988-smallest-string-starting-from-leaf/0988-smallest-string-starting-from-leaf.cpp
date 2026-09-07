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

    string res;

    void f(TreeNode* root, string str){
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr) {
            str += root->val+'a';
            string t = str;
            reverse(t.begin(), t.end());
            if(res.empty() || res > t) res = t;
            cout << str<<"\n";
            return;
        }

        str += (root->val)+'a';

        f(root->left, str);
        // str.pop_back();

        f(root->right, str);
        // str.pop_back();

        return;

    }

    string smallestFromLeaf(TreeNode* root) {
        string str = "";
        f(root, str);
        return res;
    }
};