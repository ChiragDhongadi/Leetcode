//Bruteforce : TC = O ( n )
class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int first = -1, last = -1;
        for(int i=0; i<nums.size(); i++) {
            if(arr[i]==n) {
                if(first==-1) first = -1;
                last = i; 
            }
        }
    }
};

//Better : 
//TC = 2 x O ( log n )   
class Solution {
public:
int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,target);
        if(lb == n || nums[lb] != target) return {-1,-1};
        return {lb,upperBound(nums,target)-1};
    }
};

// OR


class Solution {
public:
    int firstOccurence(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        int first = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == k) {
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid]<k) low = mid + 1;
            else high = mid -1;
        }
        return first;
    }

    int lastOccurence(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        int last = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == k) {
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid]<k) low = mid + 1;
            else high = mid -1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurence(nums,target);
        if(first == -1) return {-1,-1};
        int last = lastOccurence(nums,target);
        return {first,last};
    }
};