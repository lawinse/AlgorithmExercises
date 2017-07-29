class Solution {
public:
  void radixSort(vector<int>&a, int N){
        int *b = new int[N];
        int *pos = new int[N];
        int *neg = new int[N];
        memset(pos,0,sizeof(int)*N);
        memset(neg,0,sizeof(int)*N);
        memset(b,0,sizeof(int)*N);
        long long expp = 1;
        int maxx = 0x80000000;
        int minx = 0x7fffffff;
        int Npos = 0,Nneg = 0;
        for (int i=0; i<N; ++i){
            if (a[i] < 0){
                minx = min(a[i],minx);
                neg[Nneg++] = a[i];
            }else{
                maxx = max(a[i],maxx);
                pos[Npos++] = a[i];
            }
        }
        while(maxx/expp){
            int bucket[10] = {0};
            for(int i=0; i<Npos; ++i){
                bucket[(pos[i]/expp)%10]++;
            }
            for (int i=1;i<10;++i)
                bucket[i] += bucket[i-1];
            for (int i=Npos-1; i>=0; --i){
                b[--bucket[(pos[i]/expp)%10]] = pos[i];
            }
            for (int i=0; i<Npos; ++i) pos[i] = b[i];
            expp *= 10;
        }
        expp = 1;
        while(minx/expp){
            int bucket[10] = {0};
            for(int i=0; i<Nneg; ++i){
                bucket[-((neg[i]/expp)%10)]++;
            }
            for (int i=1;i<10;++i)
                bucket[i] += bucket[i-1];
            for (int i=Nneg-1; i>=0; --i){
                b[--bucket[-((neg[i]/expp)%10)]] = neg[i];
            }
            for (int i=0; i<Nneg; ++i) neg[i] = b[i];
            expp *= 10;
        }

        for (int i=Nneg-1;i>=0;--i)a[Nneg-1-i] = neg[i];
        for (int i=0;i<Npos;++i)a[i+Nneg] = pos[i];

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        int maxx = 1, idx = 0;
        radixSort(nums, nums.size());
        vector<pair<int,int> > dp(nums.size(),make_pair(1,-1));
        for (int i=1; i<nums.size(); ++i) {
            int tmpMax = 1, index = -1;
            for (int j=i-1;j>=0;--j) {
                if (nums[i]%nums[j]==0 && dp[j].first + 1 > tmpMax) {
                    tmpMax = dp[j].first + 1;
                    index = j;
                }
            }
            dp[i].first = tmpMax;
            dp[i].second = index;
            if (tmpMax > maxx) {
                maxx = tmpMax;
                idx = i;
            }
        }
        vector<int> ret(maxx,0);
        for (int i=0; i<maxx; ++i,idx = dp[idx].second) {
            ret[maxx-i-1] = nums[idx];
        }
        return ret;
    }
};