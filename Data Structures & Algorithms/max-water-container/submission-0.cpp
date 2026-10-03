// two pointers from both end, O(n) time
// move the shorter side, move the taller one only shrink the width
// while the height is still capped by the shorter one
// Three branches repeat the same area calculation, could be better
class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size() - 1;
        int max_area = 0;

        while(l < r){
            int h;
            int tmpArea;
            if(heights[l] < heights[r]){
                h = heights[l];
                tmpArea = areaCal(h, r-l);
                l++;
            }
            else if(heights[l] > heights[r]){
                h = heights[r];
                tmpArea = areaCal(h, r-l);
                r--;
            }
            else{
                h = heights[l];
                tmpArea = areaCal(h, r-l);
                l++;
            }

            // update area
            if(tmpArea > max_area){
                max_area = tmpArea;
            }
        }
        return max_area;
    }

    int areaCal(int h, int w){
        return h * w;
    }
};
