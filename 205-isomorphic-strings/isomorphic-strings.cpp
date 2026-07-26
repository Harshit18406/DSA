class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Length should be same
        if (s.size() != t.size())
            return false;

        // Store last occurrence index of every character
        vector<int> m1(256, -1);
        vector<int> m2(256, -1);

        for (int i = 0; i < s.size(); i++) {

            // If last occurrence is different,
            // mapping is not possible
            if (m1[s[i]] != m2[t[i]])
                return false;

            // Update last occurrence
            m1[s[i]] = i;
            m2[t[i]] = i;
        }

        return true;
    }
};