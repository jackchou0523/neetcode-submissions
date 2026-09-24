// using 2 unorder_maps
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }

        std::unordered_map<char, int> mp;
        std::unordered_map<char, int> mp_t;

        for(char x: s){
            mp[x] += 1;
        }
        for(char x:t){
            mp_t[x] += 1;
        }

        return mp == mp_t;
    }
};
