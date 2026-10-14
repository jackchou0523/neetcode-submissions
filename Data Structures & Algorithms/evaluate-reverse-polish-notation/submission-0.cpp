// stack of ints, push numbers, handle ops
// pop order matters, first pop is the right operand
// s.size() == 1 separates the '-' operator from negetive numbers
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> nums;
        std::unordered_set<char> operators = {'+', '-', '*', '/'};

        for(const string& s : tokens){
            if(s.size() == 1 && operators.contains(s[0])){
                // do the calculation
                int a = nums.back();
                nums.pop_back(); 
                int b = nums.back();
                nums.pop_back();
                switch (s[0]){
                    case '+':
                        nums.push_back(b + a);
                        break;
                    case '-':
                        nums.push_back(b - a);
                        break;
                    case '*':
                        nums.push_back(b * a);
                        break;
                    case '/':
                        nums.push_back(b / a);
                        break;
                }
            }
            else{
                nums.push_back(stoi(s));
            }
        }

        return nums.back();
    }
};
