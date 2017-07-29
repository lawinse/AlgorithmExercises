class Solution {
public:
    bool isOK(long long MAX, vector<int>&nums, int CUTS){
        long long acc = 0;
        for (num:nums) {
            if (num > MAX) return false;
            else if (acc + num <= MAX) acc += num;
            else {
                --CUTS;
                acc = num;
                if (CUTS < 0) return false;
            }
        }
        return true;
    }


    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (num:nums) {
            left = max(left,(long long)num);
            right += num;
        }
        while(left < right) {
            long long mid = (left + right)/2;
            if (isOK(mid,nums,m-1)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};