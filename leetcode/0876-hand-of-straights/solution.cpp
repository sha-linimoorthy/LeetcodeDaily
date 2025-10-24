class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size() % groupSize)!=0) return false;
        map<int, int> mp;
        for(int num : hand) mp[num]++;
        auto it = mp.begin();
        while(it!=mp.end()){
            if(it->second==0) {++it; continue;}
            int num = it->first;
            int count = it->second;
            for(int i =0; i<groupSize; i++)
            {
                if(mp[num+i]<count) return false;
                mp[num+i]-=count;
            }
            ++it;
        }
        return true;
    }
};
