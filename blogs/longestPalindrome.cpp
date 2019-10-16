class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for(int i = s.size()-1;i >= 0;--i) {
            for(int j = i;j < s.size();++j) {
                if(i == j) {
                    dp[i][j] = true;
                }
                else if(i == j-1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }
                else {
                    if(s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = true;
                    }
                }
            } 
        }
        
        int len = 0;
        int start = 0;
        for(int i = 0;i < dp.size();++i) {
            for (int j = i;j < dp[0].size();++j) {  //j = i
                if(dp[i][j] && (j-i+1) > len) {
                    len = j-i+1;
                    start = i;
                }
            }
        }
        
        return s.substr(start,len);
    }
};
