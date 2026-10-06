// fixed size window, slide by updating entering and leaving
// compares with array ==
// loop is r < size - 1 bc r++ happens before the access, make sure staying in range
// O(n * 26) time, O(1) space, Index is c-'a' 

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()) return false;

        std::array<int, 26> counts1{};
        std::array<int, 26> counts2{};

        for(int i = 0; i < s1.size(); i++){
            counts1[s1[i]-'a'] += 1;
            counts2[s2[i]-'a'] += 1;
        }

        if(counts2 == counts1){
            return true;
        }

        int l = 0;
        int r = s1.size() - 1;

        while(r < s2.size()-1){
            
            // clear the last one
            counts2[s2[l]-'a'] -= 1;
            l++;

            // add the new one
            r++;
            counts2[s2[r]-'a'] += 1;

            if(counts2 == counts1){
                return true;
            }
        }
        return false;
        
    }

};
