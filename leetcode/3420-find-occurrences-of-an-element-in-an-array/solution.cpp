class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int k = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x) {
                mp[k++] = i;
            }
        }

        for(int i=0;i<queries.size();i++) {
            if(mp.find(queries[i])!=mp.end()) ans.push_back(mp[queries[i]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
