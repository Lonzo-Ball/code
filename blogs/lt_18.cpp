class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4) return ret;
        
        sort(nums.begin(),nums.end());  //排序
        
        int key_1 = 0;
        while(key_1 < nums.size()-3) {
            if(key_1 >0 && nums[key_1] == nums[key_1-1]) {
                ++key_1;
                continue;
            }
            
            int key_2 = key_1 + 1;
            while(key_2 < nums.size()-2) {
                if(key_2 > key_1+1 && nums[key_2] == nums[key_2-1]) {
                    ++key_2;
                    continue;
                }
                
                int begin = key_2 + 1;
                int end = nums.size()-1;
                while(begin < end) {
                    if(begin > key_2+1 && nums[begin] == nums[begin-1]) {
                        ++begin;
                        continue;
                    }
                    
                    int sum = nums[key_1] + nums[key_2] + nums[begin] + nums[end];
                    if(sum == target) {
                        
                        ret.resize(ret.size()+1);
                        ret[ret.size()-1].push_back(nums[key_1]);
                        ret[ret.size()-1].push_back(nums[key_2]);
                        ret[ret.size()-1].push_back(nums[begin]);
                        ret[ret.size()-1].push_back(nums[end]);
                    
                        ++begin;
                        --end;
                    }
                    else if(sum < target) {
                        ++begin;
                    }
                    else {  //sum > target
                        --end;
                    }
                }
                
                ++key_2;
            }
            
            ++key_1;
        }
        
        return ret;
    }
};
