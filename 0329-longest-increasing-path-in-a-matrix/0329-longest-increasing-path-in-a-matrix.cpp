class Solution {
public:
    int memo[201][201];
    int dfs(vector<vector<int>>& matrix,vector<pair<int,int>> v,int i,int j){
        int temp_ans=1;
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        for(int k=0;k<v.size();k++){
            int m=i+v[k].first,n=j+v[k].second;
            if(m<matrix.size()&&m>=0&&n<matrix[0].size()&&n>=0&&matrix[m][n]>matrix[i][j]){
                temp_ans=max(temp_ans,dfs(matrix,v,m,n)+1);
            }
        }
        return memo[i][j]=temp_ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(memo,-1,sizeof(memo));
        int ans=1;
        vector<pair<int,int>> v{{1,0},{0,1},{0,-1},{-1,0}};
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                ans=max(ans,dfs(matrix,v,i,j));
            }
        }
        return ans;
    }
};