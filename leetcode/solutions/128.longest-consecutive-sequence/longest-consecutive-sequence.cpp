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
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) return N;
        sort(nums.begin(),nums.end());
        int maxret = 1;
        int pre, curret = 1;
        pre = nums[0]-2;
        for (int i=0;i<N; ++i){
            if (nums[i] == pre) continue;
            else if (nums[i] == pre + 1){
                curret ++ ;
            }else {
                maxret = max(maxret,curret);
                curret = 1;
            }
            pre = nums[i];
        }
        maxret = max(maxret,curret);
        return maxret;
    }
};