#include "std.h"

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<vector<bool>> marked(grid.size(), vector<bool>(grid[0].size(), false));

        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0]){
            return -1;
        }
        q.push({0,0});
        grid[0][0] = 1;
        int path_length = 0;

        vector<vector<int>> directions = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0},
            {-1,-1},
            {-1,1},
            {1,1},
            {1,-1}
        };

        while(!q.empty()){
            int size = q.size();
            ++path_length;

            while(size-- > 0){
                auto cur = q.front();
                q.pop();

                auto cr = cur[0];
                auto cc = cur[1];
                //fprintf(stdout,"%d %d\n", cr, cc);

                /* 此处不应该这样判断 入队列之前已经检测是否为1，入队之后置1。
                    此处再检查==1，就不能往下走了。
                if (grid[cr][cc] == 1){
                    continue;
                }
                */

                if (cr == m-1 && cc == n-1){
                    return path_length;
                }

                for (auto& d : directions){
                    int nr = cr + d[0];
                    int nc = cc + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc]){
                        continue;
                    }

                    q.push({nr,nc});
                    grid[nr][nc] = 1;
                }

            }
        }
        return -1;
    }
};