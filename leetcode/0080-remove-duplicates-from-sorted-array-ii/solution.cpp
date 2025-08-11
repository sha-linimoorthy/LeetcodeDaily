#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<size(nums);i++)
        {
            mp[nums[i]]++;
        }
        int k=0;
        for(auto &p: mp)
        {
            if(p.second>=2)
            {
                for(int j=0;j<2;j++)
                {
                    nums[k++] = p.first;
                }
            }
            else
            {
                nums[k++] = p.first;
            }
        }

        return k;
        
    }
};
