class Solution {
public:
    void sortColors(vector<int> &vtr){
	int n = vtr.size();
	if (n <= 1) return;
	int low = 0, high = n-1, lt = low,rt = high;
	int i,j;
	for (i = 0 ; i < n && vtr[i] != 1; ++i);
	if (i == n) i = n/2;
	swap(vtr[i],vtr[low]);
	int key = vtr[low];
	while(low < high){
		//cout << key <<endl;
		while(low < high && vtr[high] >= key){
			if (vtr[high] == key){
				swap(vtr[high],vtr[rt]);
				--rt;
			}
			--high;
		}
		if (low < high) vtr[low] = vtr[high];

		while(low < high && vtr[low] <= key){
			if (vtr[low] == key ){
				swap(vtr[low],vtr[lt]);
				++lt;
			}
			++low;
		}
		if (low < high) vtr[high] = vtr[low];
	}
	vtr[low] = key;

	i = 0,j=low-1;
	while(i < lt && vtr[j] != key){
		swap(vtr[j],vtr[i]);
		++i,--j;
	}

	i = low+1,j=n-1;
	while(j > rt && vtr[i] != key){
		swap(vtr[i],vtr[j]);
		++i,--j;
	}
}
};