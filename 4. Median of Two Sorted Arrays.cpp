// 1) Brute force approach:
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
     vector<int> arr3;
     int n1 = a.size(), n2 = b.size();
     int i = 0;
     int j =0;
     while(i<n1 && j<n2) {
        if(a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
     }
     while(i<n1) arr3.push_back(a[i++]);
     while(i<n2) arr3.push_back(b[j++]);
     int n = (n1+n2);
     if(n%2 == 1) {
        return arr3[n/2];
     }
     return (double)((double)(arr3[n/2]) + (double)(arr3[n/2 - 1])) / 2.0;
    }
};

// 2) Better solution :
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0;
        int j = 0;
        int n = (n1 + n2);
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;
        while(i<n1 && j<n2) {
            if(a[i] < b[j]) {
                if(cnt == ind1) ind1el = a[i];
                if(cnt == ind2) ind2el = a[i];
                cnt++;
                i++;
            }
            else {
                if(cnt == ind1) ind1el = b[j];
                if(cnt == ind2) ind2el = b[j];
                cnt++;
                j++;
            }
        }
        while(i<n1) {
            if(cnt == ind1) ind1el = a[i];
            if(cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        while(j<n2) {
            if(cnt == ind1) ind1el = b[j];
            if(cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
        if(n%2 == 1) {
            return ind2el;
        }
        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};

// 3) Optimal solution: 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2 , nums1);
        int low = 0 , high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = (n1 + n2);
        while(low <= high) {
            int mid1 = (low + high) >> 1;   //or /2
            int mid2 = left - mid1;
            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1-1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1) {
                if(n % 2 == 1) return max(l1 , l2);
                return (double) (max(l1,l2) + min(r1,r2)) / 2.0;    
            } 
            else if (l1 > r2) high = mid1 - 1;
            else if (l2 > r1) low = mid1 + 1;
        }
        return 0;

    }
};