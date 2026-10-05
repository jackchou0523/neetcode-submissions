// sliding window with unordered_set, O(n) time
// seen matches the chas in window [l,r], length r-l+1 
// On duplicate, erase chars from the left until reaching the old copy, then step past it
// the old copy's entry now stands for the new one
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int best = 0;
        std::unordered_set<char> seen;

        while(r < s.size()){
            
            // check if seen
            if(seen.count(s[r])){
                // move l one by one until the duplicate
                while(s[l] != s[r]){
                    seen.erase(s[l]);
                    l++;
                }
                // step pass it
                l++;
            }
            else{
                seen.insert(s[r]);
            }
            best = std::max(r - l + 1, best);
            r++;
        }
        return best;
    }
};
