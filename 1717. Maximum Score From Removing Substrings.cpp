class Solution {
public:
    int removeab(string& s, int x) {
        int n = s.size(), ans = 0;
        string res = "" ; res += s[0];
        for(int i=1; i<n; i++) {
            if(res.size()>0 && res.back()=='a' && s[i] == 'b') {
                ans += x;
                res.pop_back();
            } 
            else res += s[i];
        }
        s = res;
        return ans;
    }
    int removeba(string& s, int y) {
        int n = s.size(), ans = 0;
        string res = "" ; res += s[0];
        for(int i=1; i<n; i++) {
            if(res.size()>0 && res.back()=='b' && s[i] == 'a') {
                ans += y;
                res.pop_back();
            } 
            else res += s[i];
        }
        s = res;
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(x>y) {
            ans += removeab(s,x);
            ans += removeba(s,y);
        } else {
            ans += removeba(s,y);
            ans += removeab(s,x);
        }
        return ans;
    }
};