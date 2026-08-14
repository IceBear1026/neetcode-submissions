class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int row = 0; row < grid.size(); ++row){ 
            for(int col = 0; col < grid[0].size(); ++col){
                if(grid[row][col] == '1') {
                    dfs(grid, row, col);
                    count++;
                }
            }
        }
        return count;
    }
    
    /*
    grid[row][col]

    row = y direction
    col = x direction

    grid = [
        ['1','0','1'],
        ['0','1','0']
    ]

    int rows = grid.size();
    int cols = grid[0].size();
    */
    void dfs(vector<vector<char>>& grid, int row, int col){
        // check the row boundary and stop the recursive.
        if(row < 0 || row >= grid.size()) {
            return;
        }

        // check the col boundary and stop the recursive.
        if(col < 0 || col >= grid[0].size()) {
            return;
        }

        // if we are on water stop the recursive.
        if(grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
};
