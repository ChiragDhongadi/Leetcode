class Solution {
public:

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    } 
    
    string sortVowels(string s) {
        vector<char> v;

        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i])) {
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        int k = 0;
        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = v[k];
                k++;
            }
        }
        return s;
    }
};