class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;

        int count = 1;  //标记当前队列中的元素个数

        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            ret.resize(ret.size()+1);

            int n = count;
            count = 0;
            while(n--) {
                TreeNode* front = queue.front();
                queue.pop();

                ret[ret.size()-1].push_back(front->val);

                if(front->left != nullptr) {
                    queue.push(front->left);
                    ++count;
                }
                if(front->right != nullptr) {
                    queue.push(front->right);
                    ++count;
                }
            }
        }

        return ret;
    }
};
