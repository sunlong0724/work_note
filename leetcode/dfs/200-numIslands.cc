#include "std.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }        
        int ret = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }

    vector<vector<int>> directions = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    void dfs(vector<vector<char>>& grid, int cr, int cc){
        if (cr < 0 || cr >= grid.size() || cc < 0 || cc >= grid[cr]. size() || grid[cr][cc] == '0'){
            return;
        }

        grid[cr][cc] = '0';

        for (auto& d : directions){
            dfs(grid, cr + d[0], cc + d[1]);
        }
    }
};