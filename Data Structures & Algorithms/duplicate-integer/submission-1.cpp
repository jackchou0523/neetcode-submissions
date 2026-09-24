// Use insert's return value instead of find
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int i=0; i<nums.size();i++){
            auto [it,inserted] = seen.insert(nums[i]);
            if (!inserted){
                return true;
            }
        }
        return false;
    }
};