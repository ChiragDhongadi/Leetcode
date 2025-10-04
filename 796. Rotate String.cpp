// Brute force :
// TC : O ( n^2 )
// SC : O ( 1 )
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n) {
            return false;
        }

        for(int count=1; count<=m; count++) {
            rotate(s.begin(),s.begin()+1,s.end());
            if(s == goal) {
                return true;
            }
        }
        return false;
    }
};

// Optimized :
// TC : O ( n )
// SC : O ( n )
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n) {
            return false;
        }

        if((s+s).find(goal) != string::npos) {
            return true;
        }

        return false;
    }
};