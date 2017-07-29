class Solution {
public:
    int *lmost, *rmost;
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        if (n == 1) return height[0];
        if (n == 2) return max(2*min(height[0],height[1]),max(height[0],height[1]));
        
        int Max = -1;
        lmost = new int[n];
        rmost = new int[n];
        memset(lmost,0,sizeof(int)*n);
        memset(rmost,0,sizeof(int)*n);
        for (int i=0; i<n; ++i){
            int j;
            if (i!=0 && height[i-1] >= height[i]){
                j = lmost[i-1];
            }
            else j = i-1;
            for (;j >= -1; --j){
                if (j==-1||height[j]<height[i]){
                    lmost[i] = j;
                    break;
                }
            }
        }
        for (int i=n-1; i>=0; --i){
            int j;
            if(i!=n-1 && height[i+1]>=height[i]){
                j = rmost[i+1];
            }else j = i+1;
            for (;j<=n;++j){
                if (j==n||height[j]<height[i]){
                    rmost[i] = j;
                    break;
                }
            }
        }
        for (int i=0; i<n;++i){
            Max = max(Max,height[i]*(rmost[i]-lmost[i]-1));
        }
        delete [] lmost;
        delete [] rmost;
        return Max;
        
    }
};