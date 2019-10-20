class Solution {
public:
    bool _isSymmetric(TreeNode* root1,TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return true;
        else if(root1 == nullptr || root2 == nullptr) return false;

        if(root1->val != root2->val) return false;

        return _isSymmetric(root1->left,root2->right) && _isSymmetric(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return _isSymmetric(root->left,root->right);
    }
};
