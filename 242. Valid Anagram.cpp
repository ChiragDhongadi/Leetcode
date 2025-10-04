// Brute force :
// TC : O ( n log n )
// SC : O ( 1 )
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(begin(s),end(s));
        sort(begin(t),end(t));

        return s == t;
    }
};

// Optimized :
// TC : O ( n )
// SC : O ( 26 )
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);

        for(char &ch : s) {
            count[ch - 'a']++;
        }
        for(char &ch : t) {
            count[ch - 'a']--;
        }

        //check if all elements in count are zero

        bool allZeros = all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });

        return allZeros;
    }
};