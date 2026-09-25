class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::array<int, 26>, std::vector<string>> pair;
        std::vector<vector<string>> ans;
        for (std::string str : strs){
            std::array<int, 26> count={};
            for(char x : str){
                // count the characters
                auto i = x - 'a';
                count[i]++;
            }
            // add the array-word pair into the map
            pair[count].push_back(str);
        }

        for(auto [key, value] : pair){
            ans.push_back(value);
        }

        return ans;
    }
};
