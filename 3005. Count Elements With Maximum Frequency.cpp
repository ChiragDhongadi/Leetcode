class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101);
        int mxf = 0;
        for(auto x : nums) {
            freq[x]++;
            mxf = max(mxf,freq[x]);
        }
        int sum = 0;
        for(auto x : freq) {
            if(x == mxf) {
                sum += x;
            }
        }
        return sum;
    }
};