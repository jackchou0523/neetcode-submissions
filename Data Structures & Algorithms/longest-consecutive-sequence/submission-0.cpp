// O(n)
// start counting when it could be a seq start (num-1 not exist)
// Inner while loop only runs from a sequence start, so each number is walked at most once.
// Iterate the set, so duplicated ignored
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::unordered_set<int> numset(nums.begin(), nums.end());     
        int best = 0;
        int count = 0;
        int cur = 0;

        // check if can be start
        for(const int& num : numset){
            
            // if there's a before, skip
            if (numset.count(num - 1)){
                continue;
            }

            cur = num + 1;
            count = 1;

            // check if next is in the set
            while(numset.find(cur) != numset.end()){
                count++;
                cur++;
            }

            if (count > best){
                best = count;
            }

        }
        return best;
    }
};

