class Solution {
public:
    int slots(string v) {
        int cnt = 0;
        for(auto c : v) if(c == '.') cnt++;
        return cnt+1;
    }
    void split(string& version, vector<int> &v) {
        int n = version.size(), ind = 0;
        for(int i=0; i<n; i++) {
            string s = "";
            while(version[i]!='.' && i!=n) {
                s += version[i];
                i++;
            }
            v[ind] = stoi(s);
            ind++;
        }
    }
    int compareVersion(string version1, string version2) {
        int n = max(slots(version1),slots(version2));
        vector<int> v1(n), v2(n);
        split(version1,v1);
        split(version2,v2);
        for(int i=0; i<n; i++) {
            if(v1[i]>v2[i]) return 1;
            if(v1[i]<v2[i]) return -1;
        }
        return 0;
    }
};