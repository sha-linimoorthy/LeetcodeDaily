class Solution {
public:
    void merge(vector<pair<int, int>>& nums_pair, int low, int mid, int high, vector<int>& count)
    {
        int left = low;
        int right = mid +1;
        int rightCount = 0;
        vector<pair<int,int>> temp;
        while(left<=mid && right<=high)
        {
            if(nums_pair[left].first <= nums_pair[right].first)
            {
                count[nums_pair[left].second] += rightCount;
                temp.push_back(nums_pair[left++]);
            }
            else
            {
                rightCount++;
                temp.push_back(nums_pair[right++]);
            }
        }

        while(left<=mid)
        {
            count[nums_pair[left].second] += rightCount;
            temp.push_back(nums_pair[left++]);
        }
        while(right<=high)
        {
            temp.push_back(nums_pair[right++]);
        }

        for(int i=low; i<=high;i++)
        {
            nums_pair[i] = temp[i-low];
        }

    }
    void mergeSort(vector<pair<int,int>>& nums_pair, int low, int high, vector<int>& count)
    {
        int mid = (low+high) / 2;
        if(low<high)
        {
            mergeSort(nums_pair, low, mid, count);
            mergeSort(nums_pair, mid +1, high, count);
            merge(nums_pair, low, mid, high, count);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> nums_pair;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            nums_pair.push_back({nums[i],i});
        }

        vector<int> count(n,0);
        mergeSort(nums_pair,0,n-1,count);
        return count;
    }
};
