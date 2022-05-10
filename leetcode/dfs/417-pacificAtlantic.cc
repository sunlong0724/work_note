#include "std.h"

class Solution {
public:

    /* 
        从两个海洋各自边逆流到最高点
        两个海洋都包含的最高点即为所求
    */


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i){
            dfs(heights, i, 0, pacificVisited);
            dfs(heights, i, n-1, atlanticVisited);
        }

        for (int j = 0; j < n; ++j){
            dfs(heights, 0, j, pacificVisited);
            dfs(heights, m-1,j, atlanticVisited);
        }        

        vector<vector<int>> ret;
        for(int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (pacificVisited[i][j] && atlanticVisited[i][j]){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited){
        visited[i][j] = true;
        vector<vector<int>> directions = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        for (auto& d : directions){
            auto ni = i + d[0];
            auto nj = j + d[1];
            if (ni < 0 || ni >= heights.size() || nj < 0 || nj >= heights[ni].size() || visited[ni][nj] || heights[i][j] > heights[ni][nj]){
                continue;
            }
            dfs(heights, ni, nj, visited);
        }
    }
};