class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx = 0;
        int i = 0;
        int j = height.size()-1;
        while(i != j)
        {
            if (height[i] > height[j])
            {
                maxx = max(maxx,(j-i)*height[j--]);
            }
            else
            {
                maxx = max(maxx,(j-i) *height[i++]);
            }
        }
        return maxx;
    }
};