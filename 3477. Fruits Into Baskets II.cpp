class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int flag = 1;
            for(int j=0; j<n; j++) {
                if(baskets[j]>=fruits[i]) {
                    baskets[j] = 0;
                    flag = 0; break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};