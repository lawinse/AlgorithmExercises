class Solution {
public:
void mySubset(vector<int> &nums,vector<vector<int>> &ret, vector<int> &tmp,int id,int remaining,bool select){
        if (remaining == 0) ret.push_back(tmp);
        else if (select || id == 0 || nums[id] != nums[id-1]){
            tmp.push_back(nums[id]);
            mySubset(nums,ret,tmp,id+1,remaining-1,1);
            tmp.pop_back();
            mySubset(nums,ret,tmp,id+1,remaining-1,0);
            
        }else mySubset(nums,ret,tmp,id+1,remaining-1,0);
            
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        int n = nums.size();
        if (n == 0){ret.push_back(tmp);return ret;}
        mySubset(nums,ret,tmp,0,n,0);
        return ret;
    }
};