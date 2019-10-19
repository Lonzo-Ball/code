class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur != nullptr || !stack.empty()) {
            while(cur != nullptr) {
                stack.push(cur);

                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();

            ret.push_back(cur->val);

            cur = cur->right;
        }

        return ret;
    }
};
