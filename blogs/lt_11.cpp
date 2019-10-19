class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;
        
        int begin = 0,end = height.size()-1;
        int curMax = min(height[begin],height[end]) * (end-begin);
        int retMax = curMax;
        
        while(end - begin >= 1) {
            if(height[begin] <= height[end]) {
                ++begin;
            }
            else {
                --end;
            }
            
            curMax = min(height[begin],height[end]) * (end-begin);
            if(curMax > retMax) {
                retMax = curMax;
            }
        }
        
        return retMax;
    }
};
