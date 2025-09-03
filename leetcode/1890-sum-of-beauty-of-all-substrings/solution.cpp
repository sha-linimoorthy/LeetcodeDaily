class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        int n = s.length();
        string str;
        for(int i=0; i<n; i++)
        {
            str = "";
            int freq[26]={0};
            for(int j=i; j<n; j++)
            {
                freq[s[j] - 'a']++;
                int minVal = INT_MAX, maxVal = 0;
                for(int l=0; l<26; l++)
                {
                    if(freq[l]!=0)
                    {
                        minVal = min(freq[l],minVal);
                        maxVal = max(freq[l],maxVal);
                    }
                   
                }
                count+= maxVal - minVal;
            }
        }
        return count;
    }
};
