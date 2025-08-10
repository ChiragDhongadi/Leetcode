class Solution {
public:
    string givesort(int num) {
        string ans = to_string(num);
        sort(ans.begin(),ans.end());
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        string tar = givesort(n);
        for(int i=0; i<31; i++) {
            if(givesort(1<<i)==tar) return true;
        }
        return false;
    }
};