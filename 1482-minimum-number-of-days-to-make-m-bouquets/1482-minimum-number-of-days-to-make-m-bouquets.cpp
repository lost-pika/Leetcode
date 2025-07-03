class Solution {
public:
    int findMin(vector<int>& bloomDay){
        int n = bloomDay.size();
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    };

    int findMax(vector<int>& bloomDay){
        int n = bloomDay.size();
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    };

    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0;
        int noOfBouquets = 0;

        for(int i = 0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        return (noOfBouquets >= m);

    };

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        int ans = 0;
        int n = bloomDay.size();
        long long val = 1LL * m * k;

        if(val > n) return -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};