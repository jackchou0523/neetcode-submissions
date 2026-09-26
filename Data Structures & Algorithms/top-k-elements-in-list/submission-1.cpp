// count with unordered_map and use bucket sort
// bucket[count] holds numbers appear count times; so iterate from high
// reserve only sets capacity, size stays 0
// construct bucket with a size directly. reserve caused a crash
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<vector<int>> bucket(nums.size() + 1); // index = count
        std::vector<int> ans;

        // count
        for(int num : nums){
            freq[num]++ ; 
        }

        // add into bucket
        for(const auto& [num, count] : freq){
            bucket[count].push_back(num);
        }

        for(int i = nums.size(); i >= 0; i--){
            for(int num: bucket[i]){
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
