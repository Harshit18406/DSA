class Solution {
public:

    int value(char c) {

        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;

        return 1000;
    }
    int romanToInt(string s) {
        // Your code goes here
        int ans=0;
        for(int i=0;i<s.size();i++){
            int curr = value(s[i]);
            if(i+1<s.size()&&curr < value(s[i+1])){
                ans = ans -curr;
            }
            else{
                ans+=curr;
            }
        }
        return ans;
    }
};
