class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int nlen = nums.size();
        int i = 0,j = nlen-1;
        int mid;
        bool find = 0;
        while (i <= j){
            mid = (i+j) >> 1;
            if (nums[mid] == target && (mid == 0 || nums[mid-1] != target)){find = 1; break;}
            else if (target > nums[mid]) i = mid+1;
            else j = mid-1;
        }
        if (find == 0){ ret.push_back(-1),ret.push_back(-1);return ret;}
        else{
            ret.push_back(mid);
            for (j =mid;nums[j] == target && j < nlen;++j);
            ret.push_back(j-1);
            return ret;
        }
    }
};