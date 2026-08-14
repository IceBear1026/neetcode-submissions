class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        // check if the row is within the boundary.
        if(row >= grid.size() || row < 0){
            // basically end the recursive
            return;
        }
        // check if the column is within the boundary.
        if(col >= grid[0].size() || col < 0){
            // end recursive as well
            return;
        }

        // catch if it's '0' then it will just top the recursive here and there.
        if(grid[row][col] == '0'){
            return;
        }

        // make the current '1' to '0'
        grid[row][col] = '0';

        // check all of the surrounding numbers to see if it is also '1' in a recursive process. 
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
};
