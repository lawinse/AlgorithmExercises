class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int p,q;
        vector< vector<int> > ans;
        for (int i = 0 ; i < n-2 && nums[i] <= 0 ;++i)
        {
            int rest = -nums[i];
            p = i+1;
            q = n-1;
            while( p < q)
            {
                int tpsum = nums[p] + nums[q];
                if (tpsum == rest)
                {
                    if ((i > 0 && nums[i] == nums[i-1])||(p-1 > i && nums[p] == nums[p-1])||(q < n-1 && nums[q] == nums[q+1]) )
                    {p++,q-- ;continue;}
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[p]);
                    tmp.push_back(nums[q]);
                    ans.push_back(tmp);
                    p++,q--;
                }
                else if (tpsum > rest) q--;
                else p++;
            }
        }
        return ans;
    }
};