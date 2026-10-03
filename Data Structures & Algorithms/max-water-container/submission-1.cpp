// two pointers from both end, O(n) time, O(1) space
// area is min height times width, always move the shorter side
// moving the taller one won't grow the area.
// equal heights: either side can move, neither can do better with an inner bar
class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size() - 1;
        int best = 0;

        while(l < r){
            int h = std::min(heights[l], heights[r]);
            int area = h * (r - l);
            best = std::max(area, best);

            // instead of h == heights[l] better readability
            if (heights[l] <= heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return best;
    }
};
