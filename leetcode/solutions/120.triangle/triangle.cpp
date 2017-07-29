class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if (!size) return 0;
        if (size == 1) return triangle[0][0];
        int **minsum = new int*[2];
        minsum[0] = new int [size];
        minsum[1] = new int [size];
        memset(minsum[1],0,sizeof(int)*size);
        memset(minsum[0],0,sizeof(int)*size);
        minsum[0][0] = triangle[0][0];
        for (int i=1; i<size; ++i){
            minsum[i%2][0] = minsum[(i-1)%2][0]+triangle[i][0];
            minsum[i%2][i] = minsum[(i-1)%2][i-1]+triangle[i][i];
            for (int j=1; j<i; ++j){
                minsum[i%2][j] = min(minsum[(i-1)%2][j-1],minsum[(i-1)%2][j])+triangle[i][j];
            }
        }
        int ret = -1u/2;
        for (int i=0; i<size; ++i)ret = min(ret,minsum[(size-1)%2][i]);
        delete minsum[0];
        delete minsum[1];
        return ret;
    }
};