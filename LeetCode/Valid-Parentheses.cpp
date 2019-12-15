#include <map>


class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp{
            {')','('}, 
            {'}','{'},
            {']','['}
        };
        set<char> first{'(', '{','['};
        stack<char> st;
        for(char ch: s) {
            if(first.count(ch)) {
                st.push(ch);
            } else if(not st.empty()) {
                if(mp[ch] == st.top()) {
                    st.pop();
                } else{
                    return false;
                }
            } else {
                return false;
            }
        }
        return (st.empty());
        
        
    }
};
