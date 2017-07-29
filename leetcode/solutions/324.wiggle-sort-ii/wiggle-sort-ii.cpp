class Solution {
#define a(i) nums[(1+2*(i)) % (n|1)]
private:
    vector<int>  nums;
    int n;
    int partition(int low, int high){
	int mid = (low+high)>>1;
	if(a(mid)<a(high)) swap(a(mid),a(high));
	if(a(low)<a(high)) swap(a(low),a(high));
	if(a(mid)<a(low)) swap(a(mid),a(low));
	int key = a(low);
	while(low<high)
	{
		while(low<high && a(high)<=key)--high;
		if(low<high)a(low) = a(high);
		while(low<high && a(low)>=key)++low;
		if(low<high)a(high) = a(low);
	}
	a(low)=key;
	return low;

}

int quickSelect(int low, int high, int k){
	int part = partition(low,high)-low+1;
	if(part == k) return a(part+low-1);
	else if(k<part){
		return quickSelect(low,low+part-2,k);
	}else{
		return quickSelect(low+part,high,k-part);
	}

}
public:

    void wiggleSort(vector<int>& numbers) {
        n = numbers.size();
        if(n < 2) return;
        nums = numbers;
        int midv = quickSelect(0,n-1,n/2+1);
        int i=0,k=n-1,j=n/2-1;
        while(i<j) {
            if (a(i)!=midv) i++;
            else if (a(i) == midv && a(j) == midv) {
                --j;
            }
            else swap(a(i++),a(j));
        }
        j = n/2+1;
        while(j<k) {
            if(a(k) != midv) --k;
            else if (a(k) == midv && a(j) == midv) {
                ++j;
            } else swap(a(k--),a(j));
        }
        numbers = nums;
    }
};