class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int m_ptr =0;
        int n_ptr=0;
        while(m_ptr < m && n_ptr < n)
        {
            if(nums1[m_ptr]<=nums2[n_ptr])
            {
                result.push_back(nums1[m_ptr]);
                m_ptr++;
            }
            else
            {
                result.push_back(nums2[n_ptr]);
                n_ptr++;
            }
        }

        while(m_ptr < m)
        {
            result.push_back(nums1[m_ptr++]);
        }

        while(n_ptr < n)
        {
            result.push_back(nums2[n_ptr++]);
        }

        for(int i=0;i<result.size();i++) nums1[i] = result[i];
    }
};
