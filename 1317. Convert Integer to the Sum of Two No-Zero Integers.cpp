class Solution {
public:
    
    bool no_zero(int num) {
        int cnt_zero = 0;
        while(num>0) {
            int lsbit = num%10;
            num /= 10;
            if(lsbit == 0) {
                cnt_zero++;
            }
        }
        
        return cnt_zero == 0;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=(n+1)/2; i++) {
            int possible_a = i;
            int possible_b = n-i;
            if(no_zero(possible_a) && no_zero(possible_b)) {
                return {possible_a,possible_b};
            }
        }
        return {0,0};
    }
};