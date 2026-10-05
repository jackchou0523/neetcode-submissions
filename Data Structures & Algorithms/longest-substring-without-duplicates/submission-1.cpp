// sliding window with unordered_set, O(n) time
// seen matches the chas in window [l,r], length r-l+1 
// While s[r] in seen, erase s[l] and l++, loop stops after the copy is erased
// Then insert s[r] back, each char is inserted and erased at most once
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int best = 0;
        std::unordered_set<char> seen;

        while(r < s.size()){
            
            // check if seen, erase from l until the duplicate get erased
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            best = std::max(r - l + 1, best);
            r++;
        }
        return best;
    }
};
