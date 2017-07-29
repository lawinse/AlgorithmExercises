class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>a;
        a = nums;
        sort(a.begin(),a.end());
        int i = 0, j = n-1;
        int idx,idy;
        vector<int> ret;
        ret.clear();
        int sum;
        int low,high,mid;
        int rest;
        while(i < j){
            sum = a[i] + a[j];
            if (sum == target){idx = a[i],idy = a[j];break;}
            else if (sum > target){
                low = i, high = j;rest = target-a[i];
                while(low < high){
                    mid = (low+high) >> 1;
                    if (mid <= i) {j=i;break;}
                    if (a[mid]<=rest&&(mid == n-1|| a[mid+1] > rest)) {j = mid;break;}
                    else if (a[mid] > rest)high = mid;
                    else low = mid+1;
                }
                //--j;
            }
            else {
                low = i, high = j;rest = target-a[j];
                while(low < high){
                    mid = (low+high) >> 1;
                    if (mid >= j) {i=j;break;}
                    if (a[mid]>=rest&&(mid == 0|| a[mid-1] < rest)) {i = mid;break;}
                    else if (a[mid] < rest)low = mid+1;
                    else high = mid;
                }
                //++i;
                
                
            }
        }
        for (int i = 0; i < n; ++i) {if (nums[i] == idx || nums[i] == idy) ret.push_back(i+1);}
        if (ret[0] >ret[1]) swap(ret[1],ret[0]);
        return ret;
    }
};