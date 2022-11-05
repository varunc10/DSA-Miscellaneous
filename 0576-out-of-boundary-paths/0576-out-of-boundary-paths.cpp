class Solution {
public:
    int memo[51][51][51];
    int mod=1e9+7;
    long long helper(int m, int n, int k, int i, int j) {
        if(k<0){
            return 0;
        }
        if(i>=m||j>=n||i<0||j<0){
            return 1;
        }
        if(memo[i][j][k]!=-1){
            return memo[i][j][k]%mod;
        }
        return memo[i][j][k]=((helper(m,n,k-1,i-1,j)%mod)+(helper(m,n,k-1,i,j-1)%mod)+(helper(m,n,k-1,i+1,j)%mod)+(helper(m,n,k-1,i,j+1)%mod))%mod;
    }
    int findPaths(int m, int n, int k, int i, int j) {
        memset(memo,-1,sizeof(memo));
        return helper(m,n,k,i,j);
    }
};