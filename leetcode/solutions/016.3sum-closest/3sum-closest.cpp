class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mindiff = 1<<30;
        int dif;
        for (int i = 0 ; i < n-2; ++i)
        {
            if (target > 0 && nums[i] >= target)
            {
                dif = nums[i] + nums[i+1] + nums[i+2] - target;
                if (abs(dif) < abs(mindiff)) mindiff = dif;
                break;
            }
            int p = i+1;
            int q = n-1;
            while(p<q){
                dif = nums[i] + nums[p] + nums[q] - target;
                if (dif == 0)
                    return target;
                else
                {
                    if(abs(dif) < abs(mindiff)) mindiff = dif;
                    if (dif > 0) q--;
                    else p++;
                }
            }
        }
        return target + mindiff;
    }
};