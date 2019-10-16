class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) return ret;
        
        //排序
        sort(nums.begin(),nums.end());
        
        int key = 0;
        set<int> hashset_1;  //用于去重（外层）
        while(key < nums.size()-2){
            auto it_1 = hashset_1.find(nums[key]);
            if(it_1 == hashset_1.end()) {
                //双指针
                int begin = key + 1;
                int end = nums.size() - 1;
                
                set<int> hashset_2;  //用于去重（内层）  [-2,0,0,2,2] -> [-2,0,2],[-2,0,2]
                while(begin < end) {
                    if(nums[begin]+nums[end] == -nums[key]) {
                        hashset_1.insert(nums[key]);
                        
                        auto it_2 = hashset_2.find(nums[begin]);
                        if(it_2 == hashset_2.end()) {
                            hashset_2.insert(nums[begin]);
                            
                            ret.resize(ret.size()+1);
                            ret[ret.size()-1].push_back(nums[key]);
                            ret[ret.size()-1].push_back(nums[begin]);
                            ret[ret.size()-1].push_back(nums[end]);   
                        }
                        
                        ++begin;
                        --end;
                    }
                    else if(nums[begin]+nums[end] < -nums[key]) {
                        ++begin;
                    }
                    else {  //nums[begin]+nums[end] > -nums[key]
                        --end;
                    }
                }
            }
            
            ++key;
        }
        
        return ret;
    }
};
