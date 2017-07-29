class Solution {
public:
    long long get(int i,vector<int> &nums){
        if (i == -1 || i == nums.size() ) return -pow(2,50);
        else return nums[i];
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            // int mid  = round((low+high+0.0)/2);
            int mid = low + high >> 1;
            int tmp = get(mid,nums);
            long long l = get(mid-1,nums);
            long long r = get(mid+1,nums);
            if (tmp > l && tmp > r ){
                return mid;
            }else if (tmp > l && tmp < r){
                low = mid + 1;
            }else high = mid-1;
        }
        return -1;
    }
};