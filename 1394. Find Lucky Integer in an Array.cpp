class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        map<int,int> mp;

        for(auto x : arr) mp[x]++;
        for(auto &[k,v] : mp) {
            if(k==v) {
                ans = max(ans,k);
            }
        }

        return ans;
    }
};