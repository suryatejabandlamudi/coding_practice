class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;
        int u =0 , v=0, w=0;
     for(int i =0 ;i<N; i++)
     {
        for(auto time:times)
        {
            u=time[0];
            v=time[1];
            w=time[2];
            
            if(dist[u]!= INT_MAX && dist[v] > dist[u]+w)
                dist[v] = dist[u] + w;
        }
    }
        
        
        int res = 0;
        for(int i =1; i<=N; i++)
        {
            res = max(res, dist[i]);
        }
        return res==INT_MAX? -1: res;
    }
};