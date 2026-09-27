// using len#content, decode skips len chars
// find('#', cur), searches from cur and return absolute index
// substr(pos, count), stoi hide the bug by stopping early (i - cur)
// push_back(s.substr) move without copying
class Solution {
public:

    string encode(vector<string>& strs) {
        
        std::string ans;
        for (const std::string& s : strs){
            // could also use .append
            ans += to_string(s.size());
            ans += '#';
            ans += s;
            // better memory allocation
        }
        return ans;
    }

    vector<string> decode(string s) {
        
        std::vector<string> ans;
        size_t cur = 0;
        while(cur < s.size()){
            // absolute index
            size_t i = s.find('#', cur);
            int len = stoi(s.substr(cur, i - cur)); // use i-cur
            ans.push_back(s.substr(i+1, len));
            cur = i + len + 1; 
        }

        return ans;
    }
};
