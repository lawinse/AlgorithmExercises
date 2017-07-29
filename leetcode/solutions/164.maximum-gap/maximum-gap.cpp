class Solution {
public:
    void radixSort(vector<int> &a,const int n){
        int *b = new int [n];
    	int pos = 1;
    	int m = 0x80000000;
    	for (int i = 0; i<n ;++i){
    		m = max(m,a[i]);
    	}
    	int bucket[10];
    
    
    	while(m/pos){
    		memset(bucket,0,sizeof(bucket));
    		for (int i=0; i<n; ++i){
    			bucket[(a[i]/pos)%10]++;
    		}
    		for (int i=1;i<10; ++i){
    			bucket[i] += bucket[i-1];
    		}
    		for (int i = n-1; i>=0; --i){
    			b[--bucket[(a[i]/pos)%10]] = a[i];
    		}
    		for (int i=0; i<n;++i){
    			a[i] = b[i];
    		}
    		pos *=10;
    	}
    }


    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;
        sort(nums.begin(),nums.end());
        int ret = -1;
        for (int i=1; i<n; ++i){
            ret = max(ret,nums[i]-nums[i-1]);
        }
        return ret;
    }
};