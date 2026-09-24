// Using an unordered map to remember values seen
// Learned: find() returns an iterator, compare it against end() to check existence,
// then read the pair with it->first(key) and it->second(value).
// Got stuck on what to store, match when "the x(value) = your value",
// So the key is the value and the mapped value is the index.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i=0; i < nums.size(); i++){
            int x = target - nums[i];
            // if x in seen then return; else continue
            auto it = seen.find(x);
            if(it != seen.end()){
                return {it->second, i};
            }
            // save the num for finding
            seen[nums[i]] = i;
        }
        return {};
    }
};
