class Solution {  
public:  
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size(); vector<vector<int> > ans;
    if(n<4) return ans;
    sort(nums.begin(), nums.end());

    int w, x, y, z, ly, ry, a, b, c, d, dc;
    for(w=0; w<n-3; w++){
        a=nums[w];
        if(a+nums[w+1]+nums[w+2]+nums[w+3]>target) return ans;

        for(x=w+1; x<n-2; x++){
            b=nums[x];
            if(a+b+nums[x+1]+nums[x+2]>target) break;
                    // if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;

            if(a+b+nums[n-2]+nums[n-1]<target) continue;
            z = x+1;
            y = n-1;
            // if(a+b+nums[z+1]+nums[z]>target) break;
            while(z<y){
                if (a+b+nums[z]+nums[y] == target)
                {
                    ans.push_back(vector<int> {a, b, nums[z], nums[y]});
                    while(nums[z] == nums[z+1]) {z++;if (z>n-2) break;}
                    while(nums[y] == nums[y-1]) {y--;if (y<z) break;}
                    z++;
                    y--;
                }
                else if (a+b+nums[z]+nums[y] > target)
                {
                    while(nums[y] == nums[y-1]) {y--;if (y<z) break;}
                    y--;
                }
                else
                {
                    while(nums[z] == nums[z+1]) {z++;if (z>n-2) break;}
                    z++;
                }
            }
                while(nums[x]==nums[x+1]){x++; if(x>n-3) break;}
            }
            while(nums[w]==nums[w+1]){w++; if(w>n-4) break;}
        }
    return ans;
}
};  