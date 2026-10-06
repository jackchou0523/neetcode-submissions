// fixed size window, recount every window O(n*m) time
// compare window counts using array ==
// index is c-'a'
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()) return false;
        
        int l = 0;
        int r = s1.size() - 1;
        std::array<int, 26> counts1{};
        std::array<int, 26> counts2{};
        for(char s: s1){
            counts1[s-'a'] += 1; 
        }

        while(r < s2.size()){
            string tmp = s2.substr(l, r-l+1); 
            for(char s: tmp){
                counts2[s-'a'] += 1; 
            } 

            if(counts2 == counts1){
                return true;
            }

            // reset the array
            std::fill(std::begin(counts2), std::end(counts2), 0);
            l++;
            r++;   
        }
        return false;
        
    }

};
