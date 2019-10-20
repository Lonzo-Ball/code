class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    vector<int> ret(2);
	    unordered_map<int, int> hashtable;  //pair(num,index)

	    for (int i = 0; i < nums.size(); ++i) {
            int cur = target - nums[i];
            
            auto it = hashtable.find(cur);
            if(it != hashtable.end()) {
                ret[0] = it->second;
                ret[1] = i;
                
                break;
            }
            else {
                hashtable[nums[i]] = i;
            }
	    }

	    return ret;
    }
};
