class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;
        int left = 0, right = n-1;
        int secH = INT_MIN;
        int cnt,cnt1;
        int ret = 0;
        
        while(left < right) {
            if (height[left] < height[right]) {
                secH = max(secH, height[left]);
                ret += secH - height[left];
                cnt = cnt1 = 0;
                ++left;
                while(left < right && height[left] <= secH) cnt += height[left],cnt1++,left++;
                ret += cnt1*secH-cnt;
            } else {
                secH = max(secH, height[right]);
                ret += secH - height[right];
                cnt = cnt1 = 0;
                --right;
                while(left < right && height[right] <= secH) cnt += height[right],cnt1++,--right;
                ret += cnt1*secH-cnt;
            }
        }
        return ret;
    }
};