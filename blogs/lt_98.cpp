class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> tmp;
        TreeNode* cur = root;
        stack<TreeNode*> stack;
        while(cur != nullptr || !stack.empty()) {
            while(cur != nullptr) {
                stack.push(cur);

                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();

            tmp.push_back(cur->val);

            cur = cur->right;
        }

        for(int i = 1;i < tmp.size();++i) {
            if(tmp[i-1] >= tmp[i]) {
                return false;
            }
        }

        return true;
    }
};
