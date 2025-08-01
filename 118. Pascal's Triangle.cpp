class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;

        n = n-2;
        while(n--) {
            vector<int> last = ans.back();
            vector<int> v;
            v.push_back(1);
            for(int i=0; i<last.size()-1; i++) {
                v.push_back(last[i]+last[i+1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};