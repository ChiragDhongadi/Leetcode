class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size(), index = -1;
        //finding index 
        for(int i=n-1; i>=1; i--) {
            if(arr[i-1]<arr[i]) {
                index = i-1;
                break;
            }
        }
        //if large num not possible
        if(index==-1) {
            reverse(arr.begin(),arr.end());
            return;
        }
        //swap index and greater than index num
        for(int i=n-1; i>index; i--) {
            if(arr[i]>arr[index]) {
                swap(arr[i],arr[index]);
                break;
            }
        }
        //reverse left part of index
        reverse(arr.begin()+index+1,arr.end());
    }
};