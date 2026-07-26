class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";

        for (char c : s) {
            if (c != ' ') {
                word += c;
            } 
            else {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            }
        }

        // Last word
        if (!word.empty())
            st.push(word);

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();

            if (!st.empty())
                ans += " ";
        }

        return ans;
    }
};