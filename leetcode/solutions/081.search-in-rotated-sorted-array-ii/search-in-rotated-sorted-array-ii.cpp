class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lt = 0, rt = nums.size()-1;
        int mid;
        if (rt == -1) return false;
        while(lt <= rt){
            //if (nums[lt] > nums[rt] && nums[lt] >target && nums[rt] < target) return 0;
            while (lt <rt && nums[lt] == nums[lt+1])lt++;
            while (lt <rt && nums[rt] == nums[rt-1])rt--;
            mid = (lt+rt) >> 1;
            if (nums[mid] == target) return true;
            else if (nums[mid] > nums[rt] ){
                if (target >= nums[lt] && nums[mid] > target) rt = mid-1;
                else lt = mid+1;
            }
            else {
                if (target <= nums[rt] && target > nums[mid]) lt = mid+1;
                else rt = mid-1;
            }
            
        }
        return false;
    }
};

// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int start = 0;
//         int end = nums.size() - 1;
//         while(start <= end)
//         {
//             while(start < end && nums[start] == nums[start + 1])
//             start++;
//             while(start < end && nums[end] == nums[end - 1])
//             end--;
//             int mid = (end - start)/2 +start;
//             if(nums[mid] == target)
//             return true;
//             else if(nums[mid] > nums[end])
//             {
//                 if(nums[mid] > target && target >= nums[start])
//                 end = mid - 1;
//                 else
//                 start = mid + 1;
//             }
//             else
//             {
//                 if(target > nums[mid] && target <= nums[end])
//                 start = mid + 1;
//                 else
//                 end = mid - 1;
//             }
//         }
//         return false;
//     }
// };