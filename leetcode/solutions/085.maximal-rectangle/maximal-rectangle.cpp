class Solution {
public:
    int *lmost, *rmost,**ones;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        lmost = new int[cols];
        rmost = new int[cols];
        memset(lmost,0,sizeof(int)*cols);
        memset(rmost,0,sizeof(int)*cols);
        ones = new int*[rows];
        for (int i=0; i<rows; ++i){
            ones[i] = new int[cols];
            memset(ones[i],0,sizeof(int)*cols);
        }
        
        for (int i=0;i<rows;++i)
        for (int j=0;j<cols;++j){
            if (matrix[i][j] == '1')
                ones[i][j] = 1 +(i?ones[i-1][j]:0); 
        }
        int maxx = 0;
        for (int r=0;r<rows;++r){
            if (cols == 1) {maxx = max(maxx,ones[r][0]); continue;}
            
            for (int i=0;i<cols;++i){
                if (!ones[r][i]){lmost[i] = i-1;continue;}
                int j;
                if (i!=0 && ones[r][i-1] >= ones[r][i]){
                    j = lmost[i-1];
                }else j = i-1;
                for (;j>=-1;--j){
                    if (j==-1 || ones[r][j] <ones[r][i]){
                        lmost[i] = j;
                        break;
                    }
                }
            }
            
            for (int i=cols-1;i>=0;--i){
                if(!ones[r][i]){rmost[i] = i+1;continue;}
                int j;
                if(i!=cols-1 && ones[r][i+1] >= ones[r][i]){
                    j = rmost[i+1];
                }else j = i+1;
                for (;j<=cols;++j){
                    if (j ==cols || ones[r][j] < ones[r][i]){
                        rmost[i] = j;
                        break;
                    }
                }
            }
            
            for (int i=0; i<cols;++i) if (ones[r][i])maxx = max(maxx,ones[r][i]*(rmost[i]-lmost[i]-1));
        }
        delete[]lmost;
        delete[]rmost;
        for(int i=0;i<rows;++i) delete [] ones[i];
        delete [] ones;
        return maxx;
        
    }
};