class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> count;
        
        for(auto ch:s)
        {
            count[ch]++;
        }
        
        map<int,string> pq_map;
        
        for(auto i:count)
        {
            char c = i.first;
            int n = i.second;
            pq_map[n] += string(n,c);
        }
        
        string res;
        
        for(auto rit = pq_map.rbegin(); rit != pq_map.rend(); ++rit) {
            res += rit->second;
        }
        
        return res;
    }
};