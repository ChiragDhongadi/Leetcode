// TC = O ( n log n )
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, mx = INT_MIN;
        set<int> st;
        for(int i=0; i<n; i++) {
            mx = max(mx,nums[i]);
            if(nums[i]>0) {
                st.insert(nums[i]);
            }
        }
        if(mx<0) return mx;
        for(auto x : st) ans += x;
        return ans;
    }
};


// TC = O ( n )
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, mx = INT_MIN;
        vector<int> vis(101);
        for(int i=0; i<n; i++) {
            mx = max(mx,nums[i]);
            if(nums[i]>0 && !vis[nums[i]]) {
                ans += nums[i];
                vis[nums[i]] = 1;
            }
        }
        if(mx<0) return mx;
        return ans;
    }
};

