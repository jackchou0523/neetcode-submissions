// two pointers directly on s
// inner loop check left < right, so '.,' won't run out of bound
// alphaNum wraps the unsigned char cast for negative chars
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right){

            while(left < right && !alphaNum(s[left])){
                left++;
            }

            while(left < right && !alphaNum(s[right])){
                right--;
            }

            if (tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right]))){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool alphaNum(char c){
        return (std::isalnum(static_cast<unsigned char>(c)));
    }
};
