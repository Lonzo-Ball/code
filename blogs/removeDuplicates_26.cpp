class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        
        int n1,n2;
        int cur = nums.size()-1;
        int pre = cur-1;
        
        while(pre >= 0) {
            if(nums[cur] == nums[pre]) {
                --cur;
                --pre;
            }
            else {
                n1 = cur;
                n2 = cur;
                
                --cur;
                --pre;
                
                break;
            }
        }
        
        //走到这里存在的两种特殊情况
        if(0 == cur && nums[0] == nums[1]) {  //[1,1]
            return 1;
        }
        else if(0 == cur && nums[0] != nums[1]) {  //[1,2]
            return 2;
        }
        
        while(cur >= 0) {
            if(pre >= 0 && nums[cur] == nums[pre]) {
                --cur;
                --pre;
            }
            else {
                int n = n2 - n1 + 1;
                
                int start_1 = cur+1;
                int start_2 = n1;
                
                int count = n;
                while(count--) {
                    nums[start_1++] = nums[start_2++];
                }
                
                n1 = cur;
                n2 = cur + n;
                
                --cur;
                --pre;
            }
        }
        
        return n2-n1+1;
    }
};
