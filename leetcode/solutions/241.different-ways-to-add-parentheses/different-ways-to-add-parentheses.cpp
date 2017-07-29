class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        int len = input.size();
        if (len == 0) return ret;
        for (int i=0; i<len; ++i) {
            if (ispunct(input[i])) {
                for (auto a:diffWaysToCompute(input.substr(0,i)))
                for (auto b:diffWaysToCompute(input.substr(i+1))) {
                    if (input[i] == '+') ret.push_back(a+b);
                    if (input[i] == '-') ret.push_back(a-b);
                    if (input[i] == '*') ret.push_back(a*b);
                }
            }
        }
        return ret.size() ? ret : vector<int>{stoi(input)};
    }
};