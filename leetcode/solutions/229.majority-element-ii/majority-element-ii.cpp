class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        if (nums.size() == 0) return ret;
        int N = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int m1, m2;
        
        for (auto it = nums.begin(); it != nums.end(); ++it){
            if ( m1 == *it){
                ++cnt1;
            }else if (m2 == *it){
                ++cnt2;
            }else if (cnt1 == 0){
                m1 = *it;
                cnt1 = 1;
            }else if (cnt2 == 0){
                m2 = *it;
                cnt2 = 1;
            }else{--cnt1,--cnt2;}
        }
        cnt1 = 0; cnt2 = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it){
            if (m1 == *it) ++cnt1;
            if (m2 == *it) ++cnt2;
        }
        if (cnt1 > N/3) ret.push_back(m1);
        if (m2!=m1&&cnt2 > N/3) ret.push_back(m2);
        return ret;
    }
};