// stack of ints, push numbers, handle ops , O(n)
// token is a number when the last char is a digit
// pop rhs first then lhs, order matters for - and /
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> nums;
        nums.reserve(tokens.size());

        for(const string& s : tokens){
            if(std::isdigit(static_cast<unsigned char>(s.back()))){
                nums.push_back(stoi(s));
                continue;
            }
                
            // do the calculation if it's not digit
            int rhs = nums.back();
            nums.pop_back(); 
            int lhs = nums.back();
            nums.pop_back();
            switch (s[0]){
                case '+':
                    nums.push_back(lhs + rhs);
                    break;
                case '-':
                    nums.push_back(lhs - rhs);
                    break;
                case '*':
                    nums.push_back(lhs * rhs);
                    break;
                case '/':
                    nums.push_back(lhs / rhs);
                    break;
            }
        }
        return nums.back();
    }
};
