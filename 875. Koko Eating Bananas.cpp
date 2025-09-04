class Solution {
public:

    long long findHour(vector<int>piles,int mid){
        long long  hour=0;
        for(int i=0;i<piles.size();i++){
           hour+=ceil((double)piles[i]/mid);
        }
        return hour;
    }
    int maxx(vector<int>arr){
        int sum =INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum=max(arr[i],sum);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int n=piles.size();
        int e=maxx(piles);
        int ans=0;

        while(s<=e){
           int mid=s+(e-s)/2;
            long long data=findHour(piles,mid);
            if(data<=h){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;

        }
        return s;
    }
};