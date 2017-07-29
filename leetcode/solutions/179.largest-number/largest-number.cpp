class Solution {
public:
    static bool cmp(string &sa, string &sb){
        return sa+sb > sb+sa;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> snums(nums.size(),"");
        for (int i=0; i<nums.size(); ++i) snums[i] = to_string(nums[i]);
        sort(snums.begin(),snums.end(),cmp);
        string ret = "";
        int i;
        for (i = 0; i<snums.size() && snums[i] == "0"; ++i);
        for (; i<snums.size(); ++i) ret += snums[i];
        if (ret == "") ret = "0";
        return ret;
    }
};