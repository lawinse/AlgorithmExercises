class Solution {
typedef long long LL;
public:
    int merge(vector<LL>& sums, int left, int right, int &lower, int &upper) {
        if (left > right) return 0;
        if (left == right) return (bool)(sums[left]>=lower && sums[left] <= upper);
        
        int mid = left + (right-left)/2;
        int ret = merge(sums, left, mid, lower, upper) + merge(sums, mid+1, right, lower, upper);
        int i,j,k;
        for(i = left, j = k = mid+1; i<=mid; ++i) {
            while(j<=right && sums[j]-sums[i] < lower) j++;
            while(k<=right && sums[k]-sums[i] <= upper) k++;
            ret += k-j;
        } 
        
        LL *tmp = new LL[right-left + 1];
        for (k = i=left,j=mid+1; k<=right; ++k) {
            tmp[k-left] = (i<=mid) && (j > right || sums[i] < sums[j]) ? sums[i++] : sums[j++];
        }
        for (int i=left; i<=right; ++i) {
            sums[i] = tmp[i-left];
        }
        delete [] tmp;
        return ret;
        
    }
    

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return 0;
        if (lower > upper) return 0;
        
        vector<LL> sums(nums.size()+1,0);
        sums[0] = 0;
        for (int i=1; i<=nums.size(); ++i) sums[i] = sums[i-1] + nums[i-1];
        return merge(sums,1,nums.size(), lower, upper);
    }
};