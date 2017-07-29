class NumArray {
public:
    int *bit;
    vector<int> ns;
    int n;
    NumArray(vector<int> &nums) {
        n = nums.size();
        ns = nums;
        bit = new int [n+1];
        memset(bit,0,sizeof(int)*(n+1));
        for (int i=1; i<=n ;++i) set(i,nums[i-1]);
    }
    
    inline int lowbit(int x) {return (-x)&x;}
    
    void set(int i, int num){
        for (; i<=n; i+=lowbit(i)) bit[i] += num;
    }
    
    int get (int i){
        int ret = 0;
        for (; i>0; i-=lowbit(i)) ret += bit[i];
        return ret;
    }
    
    void update(int i, int val) {
        int tmp = val-ns[i];
        ns[i] = val;
        set(i+1,tmp);
        
        
    }

    int sumRange(int i, int j) {
        return get(j+1)-get(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);