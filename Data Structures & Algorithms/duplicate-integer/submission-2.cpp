// ranged-based for loop
// reverse(n) to allocate first, prevents rehash
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());

        for (int x: nums){
            auto [it,inserted] = seen.insert(x);
            if (!inserted){
                return true;
            }
        }
        return false;
    }
};