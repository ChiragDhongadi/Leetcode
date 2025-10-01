class Solution {
public:
    int numWaterBottles(int a, int b) {
        int count =a;
            int i=0;
        while(a>=b){
           count+=a/b;
           int val =a/b;
       
           a-=(val)*b;
           a+=val;

         //  cout<<a<<" "<<count<<endl;

        }
        return count;
    }
};