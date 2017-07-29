class Solution {
public:
    string toHex(int num) {
    string res;
    for (int i = 0; num && i < 8; i++) {
        int bit = num & 0xF;
        if (bit < 10)
            res = char('0' + bit) + res;
        else
            res = char('a' + bit - 10) + res;
        num >>= 4;
    }
    return res.empty() ? "0" : res;
}
};