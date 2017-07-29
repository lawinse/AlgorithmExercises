class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int tmp;
        // vector<int>::iterator it;
        for (auto it = digits.rbegin(); it != digits.rend();++it){
            tmp = *it+carry;
            *it = tmp%10;
            carry = tmp/10;
        }
        if (carry) digits.insert(digits.begin(),1);
        return digits;
    }
};