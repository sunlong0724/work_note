#include "std.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> ic_map = {
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}},
            {'5',{'j','k','l'}},
            {'6',{'m','n','o'}},
            {'7',{'p','q','r','s'}},
            {'8',{'t','u','v'}},
            
            {'9',{'w','x','y','z'}}
        };

        vector<string> res;
        if (digits.empty()){
            return res;
        }
        dfs(digits, 0, "", res, ic_map);
        return res;

    }

    void dfs(string& digits, int i, string cur, vector<string>& res, unordered_map<char,vector<char>>& ic_map){
        if (cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }

        for (int k = 0; k < ic_map[digits[i]].size(); ++k){
            dfs(digits, i+1, cur + ic_map[digits[i]][k], res,ic_map);
        }
    }
};