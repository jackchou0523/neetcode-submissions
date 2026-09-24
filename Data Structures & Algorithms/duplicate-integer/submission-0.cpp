class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen={};

        for (int i=0; i<nums.size();i++){
            auto it = seen.find(nums[i]);
            if (it != seen.end()){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};