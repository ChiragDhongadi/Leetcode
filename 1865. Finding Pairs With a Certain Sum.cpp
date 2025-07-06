class FindSumPairs {
public:
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int,int> mp;
    //T.C : O(m+n)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1; //O(m)
        vec2 = nums2; //O(n)
        for(int &x : vec2) { //O(n)
            mp[x]++;
        }
    }
    //O(1) time
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0; //count
        for(int &x : vec1) { //size of vec1 is max 100, O(n)
            c += mp[tot-x];
        }

        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */