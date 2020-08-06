// https://leetcode.com/problems/distant-barcodes/


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> counts;
        
        int max_n = 0, max_count = 0;
        
        for(int i=0; i<barcodes.size(); i++)
        {
            counts[barcodes[i]]++;
            if(counts[barcodes[i]] > max_count)
            {
                max_count = counts[barcodes[i]];
                max_n = barcodes[i];
            }
        }
        
        int pos = 0;
        
        for(int i=0; i<max_count; i++)
        {
            barcodes[pos] = max_n;
            pos = pos+2;
        }

       for(auto it: counts)
        {
           if(it.first == max_n) continue;
           
           while(it.second-- > 0)
           {
               if(pos >= barcodes.size())
                {
                    pos = 1;
                }
                barcodes[pos] = it.first;
                pos = pos + 2;
           }

        } 

        return barcodes;
    }
};