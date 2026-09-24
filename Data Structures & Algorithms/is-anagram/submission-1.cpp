// using array instead of map 
// Better memory allocation 
// count{} zero initializes
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }

        std::array<int, 26> count{};

        for(char x:s){
            auto i = x - 'a';
            count[i] += 1;
        }
        for(char x:t){
            auto i = x - 'a';
            if (--count[i] < 0){
                return false;
            }
        }
        return true;
    }
};
