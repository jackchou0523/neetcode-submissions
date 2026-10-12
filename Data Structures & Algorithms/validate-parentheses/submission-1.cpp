// vector as stack (push_back, back, poop_back)
// std::stack (push/pop/top)
// vector allows reserve(s.size())
// back() and top() on an empty container are undefined, so check empty() first
class Solution {
public:
    bool isValid(string s) {
        std::vector<char> seen;
        std::unordered_map<char, char> dict = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char p : s){
            if(dict.contains(p)){
                // check if empty
                if(seen.empty() || seen.back() != dict[p]){
                    return false;
                }
                seen.pop_back();
            }
            else{
                seen.push_back(p);
            }
        }
        return seen.empty();
    }
};
