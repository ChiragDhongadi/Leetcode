// Bruteforce :
// TC = O ( n )
// SC = O ( n )
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int result = 0;

        for(char &ch : s) {
            if(ch == '(') {
                st.push(ch);
            }
            else if(ch == ')') {
                st.pop();
            }
            result = max(result, (int)st.size());
        }
        return result;
    }
};

// Optimized :
// TC = O ( n )
// SC = O ( 1 )
class Solution {
public:
    int maxDepth(string s) {
        int openBrackets = 0;

        int result = 0;

        for(char &ch : s) {
            if(ch == '(') {
                openBrackets++;
            }
            else if(ch == ')') {
                openBrackets--;
            }
            result = max(result, openBrackets);
        }
        return result;
    }
};