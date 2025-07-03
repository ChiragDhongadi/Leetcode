//Brute Force:
class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<k) {
            string t = "";
            for(int i=0; i<s.size(); i++) {
                t += (s[i]+1);
            }

            s += t;
        }

        return s[k-1];
    }
};

//Optimized:
class Solution {
public:
    char kthCharacter(int k) {
        int x = __builtin_popcount(k-1); // counts no. of 1s in binary rep of k-1
        return 'a' + x;
    }
};