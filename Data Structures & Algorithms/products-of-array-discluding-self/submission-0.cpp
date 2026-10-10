// Multiply every other elements
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ans;
        ans.reserve(nums.size());
        // index counters use for loop
        for(int i = 0; i < nums.size(); i++){
            int product = 1;
            for(int j = 0; j < nums.size(); j++){
                if (j !=i){
                    product *= nums[j];
                }
                if (product == 0){
                    break;
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};
