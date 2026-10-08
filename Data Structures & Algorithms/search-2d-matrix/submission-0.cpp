// Binary Search, O(log(rows * cols))
// Index i maps to row (i / cols) and col (i % cols), both use the length of a row
// similar to image indexing: y = i / width, x = i % width
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0;
        int r = rows * cols - 1;

        while(l <= r){
            int mid = l + (r - l)/ 2;
            int midval = matrix[mid/cols][mid%cols];
            if(midval == target){
                return true;
            }
            else if(midval < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};
