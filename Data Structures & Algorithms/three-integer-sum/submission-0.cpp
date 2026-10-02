// Sort, fix sorted[i], then use 2 pointers. O(n^2) time
// Copy first to prevent modification on caller's array
// skip i if sorted[i] == sorted[i-1], which gives same triplets
// after a match, skip l and r past equal values
// inner skip loop check l<r first, letting l+1 r-1 stay in range 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() <= 2){
            return {};
        }
        vector<vector<int>> ans;
        vector<int> sorted = nums;

        std::sort(sorted.begin(), sorted.end());

        for(int i = 0; i < sorted.size()-2; i++){

            // skip if the smallest is greater than 0
            if(sorted[i] > 0) break;

            // skip duplicate first numbers; i > 0 make sure sorted[i-1] valid
            if(i > 0 && sorted[i] == sorted[i-1]){
                continue;
            }
            int l = i+1;
            int r = sorted.size() - 1;

            while(l < r){
                int sum = sorted[l] + sorted[r];
                if(sum == -sorted[i]){
                    ans.push_back({sorted[i], sorted[l], sorted[r]});
                    
                    // skip the duplicates
                    while(l < r && sorted[l] == sorted[l+1]) l++;
                    while(l < r && sorted[r] == sorted[r-1]) r--;

                    l++;
                    r--;
                }
                else if (sum < -sorted[i]){
                    l++;
                }
                else{
                    r--;
                }

            }

        }

        return ans;
    }
};
