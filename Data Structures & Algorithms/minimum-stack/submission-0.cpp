// Use a separate min vector to track status of min
// O(1) time, O(n) space
class MinStack {
public:
    std::vector<int> vec = {};
    std::vector<int> min = {};
    MinStack() {
    }
    
    void push(int val) {
        vec.push_back(val);
        // to include the first push
        if(min.empty() || vec.back() <= min.back()){
            min.push_back(val);
        }
    }
    
    void pop() {
        // pop only when not empty
        if(!min.empty() && vec.back() == min.back()){
            min.pop_back();
        }
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return min.back();
    }
};
