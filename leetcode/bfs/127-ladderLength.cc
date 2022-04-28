#include "std.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        int ret = 0;
        vector<bool> marked(wordList.size(), false);

        q.push(beginWord);

        while(!q.empty()){
            int size = q.size();
            ret++;
            while(size-- > 0){
                auto cur = q.front();
                q.pop();
                
                if (cur == endWord){
                    return ret;
                }

                for (int i = 0; i < wordList.size(); ++i){
                    if (!marked[i] && check(cur, wordList[i])){
                        q.push(wordList[i]);
                        marked[i] = true;
                    }
                }
            }
        }
        return 0;
    }

    bool check(string& cur, string& word){
        int i = 0;
        int cnt = 0;
        while (i < cur.size() && i < word.size()){
            if (cur[i] != word[i]) {
                cnt++;
            }
            i++;
        }
        return cnt == 1;
    }
};