class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        // find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalHours = 0;
        int n = piles.size();
        // find total hours:
        for (int i = 0; i < n; i++) {
            totalHours += ceil((double)piles[i]/ (double)hourly);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalHours = calculateTotalHours(piles, mid);

            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};