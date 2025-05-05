class Solution {
public:
    int M = 1000000007; // question me bola hai
    int t[1000];

    int solve(int n){
        if(n == 1 || n == 2){
            return n;
        }

         if(n == 3){
            return 5;
        }

        if(t[n] != -1){
            return t[n];
        }

        return t[n] = (2*solve(n-1) % M + solve(n-3) % M) % M;
    }

    int numTilings(int n) {
        return solve(n);
    }
};