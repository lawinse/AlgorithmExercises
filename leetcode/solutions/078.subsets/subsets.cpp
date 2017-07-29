class Solution {
public:
    void mySubset(vector<int> &nums,vector<vector<int>> &ret, vector<int> &tmp,int id){
        if (id == nums.size()) ret.push_back(tmp);
        else {
            tmp.push_back(nums[id]);
            mySubset(nums,ret,tmp,id+1);
            tmp.pop_back();
            mySubset(nums,ret,tmp,id+1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        int n = nums.size();
        if (n == 0){ret.push_back(tmp);return ret;}
        mySubset(nums,ret,tmp,0);
        return ret;
    }
};