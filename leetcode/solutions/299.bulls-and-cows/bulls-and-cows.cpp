class Solution {
public:
    string getHint(string secret, string guess) {
        int cntA[10] = {0};
        int cntB[10] = {0};
        int numA = 0, numB = 0;
        for(int i=0; i<secret.length(); ++i){
            if (secret[i] == guess[i]){
                numA ++;
            }else{
                cntA[secret[i]-'0']++;
                cntB[guess[i]-'0']++;
            }
            
        }
        for (int i=0; i<10; ++i) numB += min(cntA[i],cntB[i]);
        stringstream ss;
        ss << numA << 'A' << numB << 'B';
        return ss.str();
    }
};