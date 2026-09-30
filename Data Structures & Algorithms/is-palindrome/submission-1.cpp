// build a new cleaned lowercase string and compare from both end
// cast to unsigned char so negative chars don't index outside the lookup table
// cast size to int before subtracting 1. Prevent wrap around on empty string
class Solution {
public:
    bool isPalindrome(string s) {

        std::string cleaned;
        cleaned.reserve(s.size());

        // avoid undefined behavior from input and output
        for(char ch : s){
            if(std::isalnum(static_cast<unsigned char>(ch))){
                cleaned += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
            }
        }

        int left = 0;
        int right = static_cast<int>(cleaned.size()) - 1;

        while (left < right){
            if (cleaned[left] != cleaned[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
