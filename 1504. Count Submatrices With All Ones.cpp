class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n,0);
        int ans =0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]) height[j]++;
                else height[j] = 0;

                int sum = 0, h = height[j];
                for(int k=j; k>=0; k--) {
                    h = min(h,height[k]);
                    sum += h;  // sum stores ans for (i,j)
                }
                ans += sum;
            }
        }
        return ans;
    }
};