// Remove unnecessary copies
// Loop 1: const &, bc only reads and avoid copying
// Loop 2: & with std::move. modifies the map instead of copying
// using map bc std::array doesn't have hashing but supports comparing
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::array<int, 26>, std::vector<string>> groups;

        // ref for better efficiency
        for (const std::string& str : strs){
            std::array<int, 26> count={};
            for(char x : str){
                // count the characters
                auto i = x - 'a';
                count[i]++;
            }
            // add the array-word pair into the map
            groups[count].push_back(str);
        }

        std::vector<vector<string>> ans;
        ans.reserve(groups.size());

        // ref wih std::move
        for(auto& [key, value] : groups){
            ans.push_back(std::move(value));
        }

        return ans;
    }
};
