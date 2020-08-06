// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        
        string str_num = to_string(n);
        int pos = str_num.size() - 2;
        // find turning interger in the sequence
        for(; pos>=0; pos--)
        {
            if(str_num[pos] < str_num[pos+1])
                break;
        }
        
        // if all are increasing return not possible
        if(pos == -1)
            return -1;
        cout<<"pos-"<<pos<<endl;
        
        // then find next highest just for that interger in the remaning part and swap them
        for(int i=str_num.size()-1; i>pos; i--)
        {
            if(str_num[i] > str_num[pos])
            {
                swap(str_num[i] , str_num[pos]);
                break;
            }
        }
        
        
        reverse(str_num.begin()+pos+1 , str_num.end());
        
        long result = stol(str_num);
        
        return result > INT_MAX ? -1 : result;
        
        
        
    }
};