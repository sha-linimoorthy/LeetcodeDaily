class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xor_val = 0;
        int n = size(nums);
        vector<int> answer;
        //XOR 1 to n and vals in arr
        for(int i=0; i<n; i++)
        {
            xor_val = xor_val ^ nums[i] ^ (i+1);
        }

        //Find the nth bit whish is diff
        int bitNo = 0;
        while(true)
        {
            if(xor_val & (1<<bitNo))
            {
                break;
            }
            bitNo++;
        }

        int ones = 0, zeros = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] & (1<<bitNo))
            {
                ones ^= nums[i];
            }

            else
            {
                zeros ^=nums[i];
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(i & (1<<bitNo))
            {
                ones ^= i;
            }
            else
            {
                zeros ^=i;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ones) count++;
        }

        if(count==2) 
        {
            answer.push_back(ones);
            answer.push_back(zeros);
        }
        else
        {
            answer.push_back(zeros);
            answer.push_back(ones);
        }

        return answer;
    }
};
