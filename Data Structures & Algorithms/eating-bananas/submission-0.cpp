// try k from 1 to max pile, first k with hoursNeeded <= h O(max* n)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *std::max_element(piles.begin(), piles.end());

        for(int i = 1; i <= max; i++){
            if(hoursNeeded(piles, i) <= h){
                return i;
            }
        } 
        return max;
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
