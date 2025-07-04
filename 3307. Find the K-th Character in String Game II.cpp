Solution1 :
#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        ll len = 1;
        int it = 0;
        while(len<k){
            len *= 2; it++;
        }
        int cnt = 0; // no. of times a get changed
        while(k>1){
            if(k>len/2 && ops[it-1]==1){
                cnt++;
            }
            if(k>len/2) k-= (1ll<<(it-1));
            it--; len/=2;
        }
        return 'a' + cnt%26;
    }
};


Solution 2: (bit manipulation)
 ll mask = 0;
 for(int i=0;i<min(63,(int)ops.size());i++){
       mask |= (1ll* ops[i]<<i);
 }
 return 'a' + (__builtin_popcountll((k-1)&mask))%26;