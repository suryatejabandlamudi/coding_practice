class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count, end;
        
        for(auto num:nums)
            count[num]++;
        
        for(auto num: nums)
        {
            if(count[num]==0) continue;
            count[num]--;
            if(end[num-1] > 0)
            {
                end[num-1]--;
                end[num]++;
            }
            else if(count[num+1] > 0 && count[num+2] > 0)
            {
                count[num+1]--;
                count[num+2]--;
                
                end[num+2]++;
            }
            else
                return false;
        }
        return true;
    }
};