// Use a separate min vector to track status of min
// O(1) time, O(n) space
// <= not < bc duplicate minumums each need their own entries
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        vec.push_back(val);
        // to include the first push
        if(mins.empty() || vec.back() <= mins.back()){
            mins.push_back(val);
        }
    }
    
    void pop() {
        // if popping == current min
        if(vec.back() == mins.back()){
            mins.pop_back();
        }
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return mins.back();
    }
private:
    std::vector<int> vec;
    std::vector<int> mins;
};
