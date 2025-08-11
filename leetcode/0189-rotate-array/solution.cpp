class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        int n = size(nums);

        for(int start=0;count<n;start++)
        {
            int current = start;
            int prev = nums[start];

            while(true)
            {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
                if(current==start) break;
            }
        }
        
    }
};
