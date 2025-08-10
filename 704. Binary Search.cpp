//iterator approach
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid]==target) {
                return mid;
            }
            else if(nums[mid]>target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};

//Recursive apprach
class Solution {
public:
    int binarysearch(vector<int>& nums, int low, int high, int target) {
        if(low>high) {
            return -1;
        }
        int mid = low + (high-low) / 2;
        if(nums[mid]==target) {
            return mid;
        }
        else if(nums[mid]>target) {
            return binarysearch(nums,low,mid-1,target);
        }
        else {
            return binarysearch(nums,mid+1,high,target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarysearch(nums,0,n-1,target);
    }
};

