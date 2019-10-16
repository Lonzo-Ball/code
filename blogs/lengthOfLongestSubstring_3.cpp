class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();

        unordered_map<char,int> hashtable;
        hashtable[s[0]] = 0;
        int curLen = 1;
        int maxLen = 1;
        for(int i = 1;i < s.size();++i) {
            auto it = hashtable.find(s[i]);
            if(it == hashtable.end()) {  //当前遍历到的字母在哈希表中不存在
                curLen += 1;
            }
            else {  //存在
                curLen = min(curLen+1,i - it->second);  //"abba"
            }

            hashtable[s[i]] = i;  //重点理解这句代码
            if(curLen > maxLen) {
                    maxLen = curLen;
            }
        }
        
        return maxLen;
    }
};
