class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XorTwo = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it){
            XorTwo^=*it;
        }
        
        int lowbit = XorTwo&(-XorTwo);
        
        int ret1 = 0,ret2 = 0;
        
        for (auto it = nums.begin(); it!=nums.end(); ++it){
            if (*it&lowbit){
                ret1 ^= *it;
            }
        }
        
        vector<int> res;
        res.push_back(ret1);
        res.push_back(ret1^XorTwo);
        return res;
    }
};