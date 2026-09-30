// build a new cleaned lowercase string and compare from both end
// need fix in isalnum and tolower, negative is undefined now
class Solution {
public:
    bool isPalindrome(string s) {

        std::string ss;

        for(char ch : s){
            if(std::isalnum(ch)){
                ss += std::tolower(ch);
            }
        }

        int left = 0;
        int right = ss.size() - 1;

        while (left < right){
            if (ss[left] != ss[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
