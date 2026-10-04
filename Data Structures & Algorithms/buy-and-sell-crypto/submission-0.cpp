// 2 pointers move together O(n)
// update left if current is smaller, which would allow better profit in other rights 
// using the same r for both profit and l, then r++, so there's no day skipped
// keep the best and return at the end
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int best = 0;

        while(r < prices.size()){
            int profit = prices[r] - prices[l];
            best = std::max(profit, best);

            // check if update l
            if(prices[r] < prices[l]){
                l = r;
            }

            r++;
        }

        return best;
    }
};
