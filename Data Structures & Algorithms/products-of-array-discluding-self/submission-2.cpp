// First save product of everything before i into ans[i]
// Iterate right to left, accumulates product
// suffix update first, then applied to ans[j-1], so ans[n-1] is never touched
// apply to ans[j] first, then update suffi; loop must then run down to j=0
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1);

        // save into ans
        for(int i = 0; i < nums.size() - 1; i++){
            ans[i + 1] = ans[i] * nums[i];
        }

        int suffix = 1;
        for(int j = nums.size() - 1; j > 0; j--){
            suffix *= nums[j];
            ans[j - 1] *= suffix;
        }

        return ans;
    }
};
