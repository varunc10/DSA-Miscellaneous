class Solution {
public:
    int memo[51][51];
    int helper(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int i, int j){
        if(i == grid.size() - 1){
            return grid[i][j];
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int ans = INT_MAX;
        for(int k = 0; k < grid[0].size(); k++){
            int temp = grid[i][j] + moveCost[grid[i][j]][k] + helper(grid, moveCost, i+1, k);
            ans = min(ans, temp);
        }
        return memo[i][j] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        memset(memo, -1, sizeof(memo));
        int mn = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++){
            mn = min(mn, helper(grid, moveCost, 0, i));
        }
        return mn;
    }
};