// http://hihocoder.com/contest/hiho114/problem/1
// 矩阵的最小表示
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int A[105][105];
int B[105][105];
int mat[105][105];
int mat1[105][105];
int N;

int cmp(int a[105][105], int b[105][105], int x, int y, int sz){
	for (int i=x; i<x+sz; ++i)
		for (int j=y; j<y+sz; ++j){
			if(a[i][j] != b[i][j]) return a[i][j] < b[i][j]? 1:-1;
		}
	return 0;
}

void copyMat(int a[105][105], int b[105][105], int x, int y, int sz){
	for (int i=x; i<x+sz; ++i)
		for (int j=y; j<y+sz; ++j) b[i][j] = a[i][j];
}
void swapBlock(int matrix[105][105], int x1, int y1, int x2, int y2, int sz){
	for (int i=0; i<sz; ++i)
	for (int j=0; j<sz; ++j)
		swap(matrix[x1+i][y1+j],matrix[x2+i][y2+j]);
}

void rot(int matrix[105][105], int x1, int y1, int size){
	if (size == 1) return;
	if (size%2 == 0) {
		swapBlock(matrix, x1, y1, x1, y1 + size/2, size/2);
		swapBlock(matrix, x1, y1, x1+size/2, y1+size/2, size/2);
		swapBlock(matrix, x1, y1, x1+size/2, y1, size/2);

	} else {
        for (int i = 0 ; i<size/2; ++i){
            for (int j = 0; j<size-size/2; ++j){
                swap(matrix[x1+i][y1+j],matrix[x1+j][y1+size-1-i]);
                swap(matrix[x1+i][y1+j],matrix[x1+size-1-i][y1+size-1-j]);
                swap(matrix[x1+i][y1+j],matrix[x1+size-1-j][y1+i]);
            }
        }
	}
}

void regulate(int m[105][105], int x1, int y1, int size) {
	if (size%2==0){
		int s_2 = size >> 1;
		regulate(m,x1,y1,s_2);
		regulate(m,x1,y1+s_2,s_2);
		regulate(m,x1+s_2,y1,s_2);
		regulate(m,x1+s_2,y1+s_2,s_2);
	}
	copyMat(m,mat,x1,y1,size);
	copyMat(mat,mat1,x1,y1,size);
	for (int k=0; k<3; ++k){
		rot(mat1,x1,y1,size);
		if (cmp(mat1,mat,x1,y1,size) == 1){
			copyMat(mat1,mat,x1,y1,size);
		}
	}
	copyMat(mat,m,x1,y1,size);

}


int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(sumA,0,sizeof sumA);
		scanf("%d",&N);
		for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%d",&A[i][j]);
		for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%d",&B[i][j]);
		memset(mat,0,sizeof mat);
		memset(mat1,0,sizeof mat1);
		regulate(A,0,0,N);
		memset(mat,0,sizeof mat);
		memset(mat1,0,sizeof mat1);
		regulate(B,0,0,N);
		printf("%s\n",cmp(A,B,0,0,N)==0?"Yes":"No" );
	}
	return 0;
}