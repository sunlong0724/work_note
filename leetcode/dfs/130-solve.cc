#include "std.h"

/*

先处理最外层的情况，再处理里面的
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i){
                dfs(board,i,0);
                dfs(board,i,n-1);
        }
        for (int j = 0; j < n; ++j){
                dfs(board, 0,j);
                dfs(board, m-1,j);
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != 'O'){
            return;
        }

        board[i][j] = 'T';
        vector<vector<int>> directions = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        for (auto& d : directions){
            dfs(board, i+d[0], j+d[1]);
        }
    }
};