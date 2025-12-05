class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % 2 == 0)
            return n-1; 
        
        return 0;
    }
};