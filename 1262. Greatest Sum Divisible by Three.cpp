class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        int smallest_one = INT_MAX;
        int smallest_two = INT_MAX;

        for (int n : nums) {
            total += n;

            if (n % 3 == 1) {
                // candidate for removing remainder 2
                if (smallest_one != INT_MAX)
                    smallest_two = min(smallest_two, smallest_one + n);

                // smallest remainder-1 number
                smallest_one = min(smallest_one, n);
            }
            else if (n % 3 == 2) {
                // candidate for removing remainder 1
                if (smallest_two != INT_MAX)
                    smallest_one = min(smallest_one, smallest_two + n);

                // smallest remainder-2 number
                smallest_two = min(smallest_two, n);
            }
        }

        if (total % 3 == 0) return total;

        if (total % 3 == 1) {
            // remove smallest remainder-1
            return (smallest_one == INT_MAX ? 0 : total - smallest_one);
        }

        // total % 3 == 2 → remove smallest remainder-2
        return (smallest_two == INT_MAX ? 0 : total - smallest_two);
    }
};