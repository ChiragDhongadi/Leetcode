class Solution {
public:
    int numWaterBottles(int a, int b) {
        int count = a;

        while(a >= b){
           count += a/b;
           int val = a/b;

           a -= (val)*b;
           a += val;

        }
        return count;
    }
};