class Solution {
public:
    int getNext(int a){
        int sum = 0;
        while(a){
            sum += (a%10)*(a%10);
            a /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n==0) return false;
        if (n==1) return true;
        int cur = getNext(n);
        unordered_set<int> st;
        st.insert(n);
        while(1){
            if (cur == 1) return true;
            if (st.find(cur)!=st.end()) return false;
            st.insert(cur);
            cur = getNext(cur);
        }
    }
};