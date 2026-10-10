// Binary search for the first index in the second segment O(log n)
// Compare with nums.back(), nums[i] < last means i is in the second segment
// F F T T T similar to KOKO
class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums.back()){
                r = mid;
            }
            else{
                // skip
                l = mid + 1;
            }
        }

        return nums[l];
    }
};
