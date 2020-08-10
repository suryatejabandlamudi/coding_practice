class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> freq;
        
        for(auto word:words)    
            freq[word]++;
        
        
        auto comp = [&](pair<string,int> &a , pair<string,int> &b){
            return a.second > b.second || (a.second == b.second && a.first<b.first);
        };
            
        
        priority_queue<pair<string, int>, vector<pair<string,int>>, decltype(comp)> pq(comp);
        
        for(auto it:freq)
        {
            pq.emplace(it.first, it.second);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};