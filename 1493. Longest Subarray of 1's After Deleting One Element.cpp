// Bruteforce :
class Solution {
public:
    int n;

    int findMax(vector<int>& nums, int skip_idx) {
        int currLength = 0;
        int maxLength = 0;

        for(int i=0; i<n; i++) {
            if(i == skip_idx) 
                continue;

            if(nums[i] == 1) {
                currLength++;
                maxLength = max(maxLength, currLength);
            } else {
                currLength = 0;
            }
        }
        return maxLength;
    }

    int longestSubarray(vector<int>& nums) {
        n = nums.size();

        int result = 0;
        int countZero = 0;
				// O (n^2)
        for(int i=0; i<n; i++) {
            if(nums[i]==0) {
                countZero++;
                result = max(result,findMax(nums,i));
            }
        }
        if(countZero == 0) {
            return n-1;
        }
        return result;
    }
};

// Better :
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int maxLength = 0;

        int i = 0;
        // O (n+n) ~ O (n)
        for(int j=0; j<nums.size(); j++) {
            if(nums[j] == 0) {
                zeroCount++;
            }

            while(zeroCount > 1) {
                if(nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }
            maxLength = max(maxLength,j-i);
        }
        return maxLength;
    }
};

// optimized :
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;

        int last_zero_idx = -1;

        int result = 0;
				// O ( n )
        while(j < nums.size()) {
            if(nums[j] == 0) {
                i = last_zero_idx + 1;
                last_zero_idx = j;
            }
            result = max(result,j-i);
            j++;
        }
        return result;
    }
};
