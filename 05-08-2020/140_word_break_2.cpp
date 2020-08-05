// https://leetcode.com/problems/word-break-ii/

class Solution {
    
    unordered_map<string, vector<string>> dp;
    vector<string> helper(string s, unordered_set<string>& wordSet)
    {
        vector<string> result;
        if(s.empty())
            return {""};
        
        if(dp.find(s)!= dp.end())
            return dp[s];
        
        
        for (auto i = wordSet.begin(); i != wordSet.end(); ++i)
        {
            string first_part = s.substr(0,(*i).size());
            
            if(first_part == (*i))
            {
                cout<<"First part-"<<first_part<<"-" <<endl;
                string second_part = s.substr((*i).size());
                vector<string> response = helper(second_part, wordSet);
                
                for(string res: response)
                {
                    if(res.size())
                        result.push_back(first_part+" "+res);
                    else
                        result.push_back(first_part);
                }
                
            }
            
            
        }
        
        dp[s] = result;
        return result;
        
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto str: wordDict)
        { wordSet.insert(str);}
        
        return helper(s, wordSet);
        
    }
};