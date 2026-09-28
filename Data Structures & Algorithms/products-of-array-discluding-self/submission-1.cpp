// left[i], product of everything before i, left[0]=1
// right[i], from i to the end, including i, right[n]=1
// ans[i] = left[i] * right[i+1], since right[i+1] is everything after i
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ans(nums.size());
        std::vector<int> left(nums.size() + 1, 1);
        std::vector<int> right(nums.size() + 1, 1);

        for(int i = 0; i < nums.size(); i++){
            left[i + 1] = left[i] * nums[i];
        }

        for(int j = nums.size(); j > 0; j--){
            right[j - 1] = right[j] * nums[j - 1];
        }

        for(int i = 0; i < nums.size(); i++){
            ans[i] = left[i] * right[i + 1];
        }

        return ans;
    }
};
