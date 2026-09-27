// using len#content
// length lets decode to skip len chars
// substr.find() returns position relative to cur not the whole string
class Solution {
public:

    string encode(vector<string>& strs) {
        
        std::string e;
        for (std::string s : strs){
            e += to_string(s.size()) + '#' + s;
        }
        return e;
    }

    vector<string> decode(string s) {
        std::vector<string> d;
        
        int cur = 0;
        while(cur < s.size()){
            size_t i = s.substr(cur).find('#');
            int l = stoi(s.substr(cur, i));
            std::string sub = s.substr(cur+i+1, l);
            d.push_back(sub);
            cur += i+l+1; 
        }

        return d;
    }
};
