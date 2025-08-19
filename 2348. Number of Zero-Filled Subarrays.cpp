//Approach 1 : TC = O ( n )
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;

        int n = nums.size();

        int i = 0;

        while(i<n) {
            long long l = 0;

            if(nums[i] == 0) {
                
                while(i<n && nums[i] == 0) {
                    i++;
                    l++;
                }
            } else {
                i++;
            }
            
            result += (l)*(l+1)/2;
        }
        return result;
    }
};

//Approach 2 : 
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) {
                count++;
            } else {
                count = 0;
            }
            result += count;
        }
        return result;
    }
};