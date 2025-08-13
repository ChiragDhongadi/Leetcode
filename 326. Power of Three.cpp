//iterative TC = O ( log base 3 n )
//SC = O ( 1 )
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n%3 == 0) {
            n /= 3;
        }
        return n==1;
    }
};

// Recursive TC = O ( log base 3 n )
//SC = O ( 1 ) / O ( log base n 3 )
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(n%3 != 0) return false;
        return isPowerOfThree(n/3);
        // return n%3 == 0 && isPowerOfThree(n/3);
    }
};

//OR
//TC = O ( 1 ) 
//SC = O ( 1 )
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double x = log10(n) / log10(3);
        return x == (int)x;
    }
};

//OR
//TC = O ( 1 ) 
//SC = O ( 1 )
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467%n == 0;
    }
};