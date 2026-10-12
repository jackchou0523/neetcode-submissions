class Solution {
public:
    bool isValid(string s) {
        std::stack<char> seen;
        std::unordered_map<char, char> dict = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char p : s){
            if(dict.contains(p)){
                if(seen.empty() || seen.top() != dict[p]){
                    return false;
                }
                seen.pop();
            }
            else{
                seen.push(p);
            }
        }
        return seen.empty();
    }
};
