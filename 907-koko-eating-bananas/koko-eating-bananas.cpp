class Solution {
public:

    bool canFinish(vector<int>& piles, int h, int k) {

        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (canFinish(piles, h, mid)) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }
};