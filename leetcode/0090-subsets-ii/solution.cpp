class Solution {
public:
    void solve(vector<int> inp, vector<int> outp, vector<vector<int>>& ans)
    {
        if(inp.size()==0){
            bool present = false;
            for(int i=0;i<ans.size();i++) {
                if(ans[i]==outp) {present=true; break;}
            }
            if(!present) ans.push_back(outp);
            return;
        }
        outp.push_back(inp[0]);
        inp.erase(inp.begin()+0);
        solve(inp, outp, ans);
        outp.pop_back();
        solve(inp, outp, ans);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, vector<int>{}, ans);
        return ans;
    }
};
