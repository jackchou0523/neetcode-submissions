// Binary Search [l,r] O(log n)
// r = n-1 is valid, loop while l<=r to include equals, drop mid with mid-1 / mid+1
// mid = l + (r - 1) / 2 avoids overflow
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            // (l + r) / 2
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};
