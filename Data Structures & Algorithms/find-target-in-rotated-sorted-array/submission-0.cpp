// Binary search on a rotated sorted array, [l, r], O(log n)
// nums[mid] >= nums[0] means [0, mid] is sorted
// >= not >: whem nums[mid] == nums[0], it's in first segment [3, 1]
// Range checks exlude nums[mid] == target bc already handled
// C++ has no chained comparison: a < x < b compiles but mean (a < x) < b, Split using &&
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target){
                return mid;
            }

            // left is sorted
            if (nums[mid] >= nums[0]){
                // target in sorted part
                if(nums[0] <= target && target < nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                // target in right sorted part
                if(nums[mid] < target && target <= nums.back()){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return -1; 
    }
};
