// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if(dict.find(endWord) == dict.end())
             return 0;
        
        queue<string> bfs_queue;
        bfs_queue.push(beginWord);
        
        int BFS_length = 1;
        while(!bfs_queue.empty())
        {
            int n = bfs_queue.size();
            for(int len=0; len<n; len++)
            {
                string curr_word = bfs_queue.front();
                bfs_queue.pop();

                if(curr_word == endWord)
                    return BFS_length;
                dict.erase(curr_word);

                for(int i=0; i<curr_word.size(); i++)
                {
                    char k = curr_word[i];
                    for(int j=0; j<26; j++)
                    {
                        curr_word[i] = 'a' + j;
                        if(dict.find(curr_word) != dict.end())
                        {
                             bfs_queue.push(curr_word); 
                             dict.erase(curr_word);

                        }

                    }
                    curr_word[i] = k;
                }
            }
            BFS_length++;
        }
        
        return 0;  
    }
};