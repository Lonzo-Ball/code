class Solution {
public:
    bool _isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;

        if(p->val != q->val) return false;

        return _isSameTree(p->left,q->left) && _isSameTree(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;

        if(p->val == q->val) {
            return _isSameTree(p->left,q->left) && _isSameTree(p->right,q->right);

        }
        else {
            return false;
        }
    }
};
