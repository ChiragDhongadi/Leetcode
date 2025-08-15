//Time limit exceeded
class Solution {
public:
    bool isPowerOfFour(int n) {
    if(n == 0) return false;
        while(n%4 == 0) {
            n /= 4;
        }

        if(n == 1) return true;
        return false;
    }
};

//OR
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double x = log10(n) / log10(4);
        return x == (int)x;
    }
};
//OR
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int x = log(n) / log(4);
        if(pow(4,x) == n) return true;
        return false;
    }
};

//OR
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        
        //if n divisible by 2  and n-1 divisible by 3
        if((n & (n-1)) == 0 && (n-1)%3 == 0) {  
            return true;
        }
        return false;
    }
};