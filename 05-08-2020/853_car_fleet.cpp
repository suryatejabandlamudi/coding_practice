// https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        map<int,double> time_map;
        int res =0;
        double curr = 0;
        
        for(int i=0; i<position.size(); i++)
        {
            time_map[-position[i]] = (double)(target-position[i])/speed[i];
        }
        
        for(auto it : time_map)
        {
            if(it.second > curr)
            {
                curr = it.second;
                res++;
            }
        }
        
        return res;
    }
};