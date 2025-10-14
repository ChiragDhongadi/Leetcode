class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<=n-2*k; i++) {
            bool flag = true;
            for(int j=i+1; j<i+k; j++) {
                if(nums[j] <= nums[j-1]) {
                    flag = false;
                    break;
                }
            }

            if(!flag) {
                continue;
            }
            for(int j=i+k+1; j<i+2*k; j++) {
                if(nums[j] <= nums[j-1]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                return true;
            }
        }
        return false;
    }
};

// Better :
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> increasing(n+1,1);
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                increasing[i+1] += increasing[i];
            } else {
                increasing[i+1] = 1;
            }
        }

        for(int i=k; i<=n-k; i++) {
            if(increasing[i] >= k && increasing[i+k] >= k) {
                return true;
            }
        }
        return false;
    }
};