class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ret;
        if (rowIndex == 0){ret.push_back(1); return ret;}
        int **a = new int*[2];
        a[1] = new int [rowIndex+10];
        a[0] = new int [rowIndex+10];
        memset(a[1],0,sizeof(int)*(rowIndex+10));
        memset(a[0],0,sizeof(int)*(rowIndex+10));
        //rowIndex--;
        a[0][0] = 1;
        for (int i=1 ;i<=rowIndex;++i){
            a[i%2][0] = 1;
            a[i%2][1] = i;
            for (int j=2; j<=i; ++j){
                a[i%2][j] = a[(i-1)%2][j-1]+a[(i-1)%2][j];
            }
        }
        for (int i=0; i<=rowIndex; ++i) ret.push_back(a[rowIndex%2][i]);
        delete [] a[1];
        delete [] a[0];
        delete [] a;
        return ret;
    }
};