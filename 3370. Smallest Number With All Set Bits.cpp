// Approach 1 :
class Solution {
public:
    bool isAllBitsSet(int n) {
        return (n & (n+1)) == 0;
    }
    int smallestNumber(int n) {
        int result = n;
        while(!isAllBitsSet(result)) {
            result++;
        }
        return result;
    }
};

// Approach 2 :
class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;

        while(result < n) {
            result = 2 * result + 1;
        }
        return result;
    }
};

// Approach 3 :
class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;
        return (1 << bits) - 1;
    }
};