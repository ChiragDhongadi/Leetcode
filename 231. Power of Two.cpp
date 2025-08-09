class Solution {
public:
    bool isPowerOfTwo(int n) {
    //using Log Operation   
        if(n==0) return false;
        
        return floor(log2(n))==ceil(log2(n))?true:false;  
    }
};

//OR
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && (log2(n))==(int)log2(n);  
    }
};

//OR
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && (__builtin_popcount(n)==1;   
    }
};

//OR
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && ((n&(n-1))==0);   
    }
};

//OR Optimized
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && ((1<<30)%n==0);   
    }
};