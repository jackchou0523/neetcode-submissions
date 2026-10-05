// sliding window with last seen index, O(n) time, O(1) space
// last[c] is the index where c last appeared, -1 if never
// on each char, l = max(1, last[c]+1), max keeps l from moving back when the old copy is outside the window (abba)
// no erase needed; stale enteires are ignored because of l
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int best = 0;
        std::array<int, 128> last;
        last.fill(-1); 

        while(r < s.size()){
            // l only moves when last index is inside the window;
            // never-seen (-1) and outside the window leaves l unchanged
            l = std::max(l, last[s[r]] + 1);

            last[s[r]] = r;

            best = std::max(r - l + 1, best);
            r++;
        }
        return best;
    }
};
