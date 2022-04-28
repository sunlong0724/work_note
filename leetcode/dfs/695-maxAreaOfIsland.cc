#include "std.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int ret = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                ret = max(ret, dfs(grid, i, j));
            }
        }
        return ret;
    }

    vector<vector<int>> directions = {
        {0,1},
        {0,-1},
        {-1,0},
        {1,0}
    };
    int dfs(vector<vector<int>>& grid, int cr, int cc){
        if (cr < 0 || cr >= grid.size() || cc <0 || cc >= grid[cr].size() || grid[cr][cc] == 0){
            return 0;
        }

        grid[cr][cc] = 0;
        int area = 1;
        for (auto& d : directions){
            area += dfs(grid, cr + d[0], cc + d[1]);
        }
        return area;
    }
};