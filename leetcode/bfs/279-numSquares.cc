#include "std.h"

class Solution {
public:
    int numSquares(int n) {
        int cnt = 0;
        vector<int> squares = generateSquare(n);
        vector<bool> marked(n + 1, false);
        queue<int> q;
        q.push(n);
        marked[n] = true;

        while(!q.empty()){
            int size = q.size();
            cnt++;
            while(size-- > 0){
                int cur = q.front();
                q.pop();

                for (int s : squares){
                    int next = cur -s ;
                    if (next < 0){
                        break;
                    }
                    if (next == 0){
                        return cnt;
                    }
                    if (marked[next]){
                        continue;
                    }
                    marked[next] = true;
                    q.push(next);
                }
            }
        }
        return n;
    }

    vector<int> generateSquare(int n){
         vector<int> ret;
         int square = 1;
         int diff = 3;
         while(square <= n){
             ret.push_back(square);
             square += diff;
             diff += 2;
         }
         return ret;
    }
};