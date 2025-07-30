class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        for(auto x : nums) mx = max(x,mx);
        int cnt = 0, mxcnt = 0;

        for(int i=0; i<n; i++) {
            while(i<n && nums[i]==mx) {
                cnt++;
                i++;
            } 
            mxcnt = max(mxcnt,cnt);
            cnt = 0;
        }
        
        return mxcnt;
    }
};