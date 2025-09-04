class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distx = abs(z-x);
        int disty = abs(z-y);

        if(distx == disty) {
            return 0;
        }
        
        return distx < disty ? 1 : 2;
        
    }
};