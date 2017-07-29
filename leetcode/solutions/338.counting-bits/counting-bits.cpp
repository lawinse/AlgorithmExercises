class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ret(num+1,0);
        if (num == 0) return ret;
        int thislen = 1;
        while(num>0){
            for (int i=0; i<thislen&&(num--);++i)
                ret[i+thislen] = 1+ret[i];
            thislen*=2;
        }
        return ret;
    }
};