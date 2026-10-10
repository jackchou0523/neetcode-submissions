// Binary Search on the answer k in [1, max_pile] O(n log max)
// larger k never needs more hours, so F F F..T T T T
// Find the first feasible k, which r is always feasible
// feasible mid - might be the answer so r = mid
// infeasible mid - can't be the answer so l = mid + 1
// loops end when l == r which is the only candidate, so no best need
// Overflow: mid = l + (r - l) / 2; pile / k + 1 if there's remainder
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        
        // loop ends when l == r
        while(l < r){
            int mid = l + (r - l)/2;
            // if hours < h, then find smaller k, save mid as best
            if(hoursNeeded(piles, mid) <= h){
                r = mid;
            }
            else{
                // if hours needed too much, then find bigger k
                // skip the unable one
                l = mid + 1;
            }
        }

        return l;
    }

    long long hoursNeeded(const vector<int>& piles, int k){
        long long total = 0;
        for(int pile: piles){
            int tmp = pile/k;
            if(pile % k != 0) tmp++;
            total += tmp;
        }
        return total;
    }
};
