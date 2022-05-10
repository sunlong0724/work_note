#include "std.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int ret = 0;
        for (int i = 0; i < isConnected.size(); ++i){
            if (!visited[i]){
                dfs(isConnected, i, visited);
                ret++;
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        visited[i] = true;
        for (int k = 0; k < isConnected[i].size(); ++k){
            if (!visited[k] && isConnected[i][k] == 1){
                dfs(isConnected, k, visited);
            }
        }
    }
};