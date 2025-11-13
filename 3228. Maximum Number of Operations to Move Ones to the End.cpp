class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int result = 0;
        int count1seen = 0;
        int i = 0;

        while(i<n) {
            if(s[i] == '0') {
                result += count1seen;
                while(s[i] == '0') 
                    i++;
            }
            else {
                count1seen++;
                i++;
            }
        }
        return result;
    }
};