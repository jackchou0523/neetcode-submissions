// Two pointers on sorted array, O(n) time, O(1)space
// sum too big, right--
// sum too small, left++
// Each move discard one value, nothing is missed
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = size(numbers) - 1;

        while(l < r){
            int sum = numbers[l] + numbers[r];

            if (sum == target){
                return {l + 1, r + 1};
            }
            else if(sum > target){
                r--;
            }
            else if (sum < target){
                l++;
            }
        }
    }
};
