class Solution {
public:
    void getMax(vector<int> num, vector<vector<int>>&maxm, int k) {
        int start, i=0;
        for (start = 0; num.size()>0; start = ((i==0)?0:i-1)) {
            if (num.size() <= k) maxm[num.size()] = num;
            for (i=start; i<num.size()-1 && num[i]>=num[i+1]; ++i);
            num.erase(num.begin()+i);
        }
    }
    
    void merge(vector<vector<int>>&m1, vector<vector<int>>&m2, int n1, int n2, vector<int>&tmp) {
        vector<int> x1 = m1[n1];
        vector<int> x2 = m2[n2];
        int i=0,j=0,k=0,ii,jj;
        for (;k<n1+n2;++k) {
            for(ii=i,jj=j; ii<n1 && jj < n2 && x1[ii] == x2[jj];++ii,++jj);
            bool oneLargerTwo = ii<x1.size() && (jj>=x2.size() || x1[ii] >x2[jj] );
            tmp[k] = (i<x1.size() && (j>=x2.size() || x2[j] < x1[i] || (x2[j] == x1[i] && oneLargerTwo))) ? x1[i++] : x2[j++];
        }
    }
    
    bool isSmaller(const vector<int>&a, const vector<int>&b) {
        for (int i=0; i<a.size(); ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret, tmpret(k);
        if (k == 0) return ret;
        vector<vector<int>> max1(k+1), max2(k+1);
        getMax(nums1, max1, k);
        getMax(nums2, max2, k);
        for (int i=0; i<=k; ++i) {
            if (max1[i].size() + max2[k-i].size() < k) continue;
            merge(max1,max2,i,k-i,tmpret);
            if (ret.empty() || isSmaller(ret,tmpret)) {
                ret = tmpret;
            }
        }
        return ret;
    }
};