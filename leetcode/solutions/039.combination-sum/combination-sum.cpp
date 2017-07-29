class Solution {
public:
    void dfs(int curSum,int srt, int &target, vector<int> & can, vector<int> &ans, vector<vector<int>> & ret){
        if (curSum > target) return;
        if (curSum ==  target){
            ret.push_back(ans);
            return;
        }
        else {
            for (int i = srt; i < can.size(); ++i)
            {
                //if (ans.empty() && can[i] > target) return;
                ans.push_back(can[i]);
                dfs(curSum+can[i],i,target,can,ans,ret);
                ans.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        vector< vector<int> > ret;
        ans.clear();
        ret.clear();
        dfs(0,0,target, candidates,ans,ret);
        return ret;
    }
};