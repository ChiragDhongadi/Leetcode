class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0, white = 0, blue = n-1;

        for(int i=0; i<n; i++) {
            if(nums[red]==0) {
                swap(nums[red],nums[white]);
                red++;
                white++;
            }
            else if(nums[red]==1) {
                red++;
            }
            else {
                swap(nums[red],nums[blue]);
                blue--;
            }
        }
    }
};