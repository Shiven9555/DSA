class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int days) {
        
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= days) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long required = 1LL * m * k;

        if (required > bloomDay.size()) {
            return -1;
        }

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }
};