// count with unordered_map, copy into vector<pair> and sort by freq
// vector can be built directly from another container's range: vec(begin, end).
// Lambda as sort comparator: return true if a should come before b.
// Small types (int) by value, not const&.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<int> ans;
        ans.reserve(k);

        // count
        for(int num : nums){
            freq[num]++ ; 
        }

        std::vector<std::pair<int, int>> vec(freq.begin(), freq.end());
        //sort
        std::sort(vec.begin(), vec.end(),[](const auto& a, const auto& b){
            return a.second > b.second; // Higher freq comes first
        });

        for(int i=0; i<k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
