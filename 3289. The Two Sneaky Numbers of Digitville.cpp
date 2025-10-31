class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;

        int XOR = 0; //a^b

        for(int &num : nums) {
            XOR ^= num;
        }

        for(int num=0; num <= n-1; num++) {
            XOR ^= num;
        }

        int trailZeroCount = __builtin_ctz(XOR);
        int mask = 1 << trailZeroCount;
        int g1=0, g2=0;

        for(int &num : nums) {
            if(num & mask) {
                g1 ^= num;
            }
            else {
                g2 ^= num;
            }
        }

        for(int num=0; num<=n-1; num++) {
            if(num & mask) {
                g1 ^= num;
            }
            else {
                g2 ^= num;
            }
        }

        return {g1,g2};

    }
};