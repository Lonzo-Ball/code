class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= 2) return s;
        
        int N = numRows <= s.size() ? numRows : s.size();  //"ABC" numRows = 100
        vector<string> rows(N);
        int row = 0;
        int i = 0;
        while(i < s.size()) {
            if(row != N ){
                rows[row++] += s[i++];
            }
            else {  //说明走到了最后一行
                int count = N-2;
                int n = 2;
                while(i < s.size() && count--) {
                    rows[row-n] += s[i++];
                    ++n;
                }
                
                row = 0;
            }
        }
        
        string ret;
        for(int i = 0;i < N;++i) {
            ret += rows[i];
        }
        
        return ret;
    }
};


