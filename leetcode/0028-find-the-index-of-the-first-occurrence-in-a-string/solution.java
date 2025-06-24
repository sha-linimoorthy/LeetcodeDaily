class Solution {
    public int strStr(String haystack, String needle) {
        int[] lps = new int[needle.length()];
        int prev=0,i=1,j=0;
        while(i<needle.length())
        {
            if(needle.charAt(i)==needle.charAt(prev))
            {
                lps[i] = prev+1;
                prev++;
                i++;
            }
            else
            {
                if(prev==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    prev = lps[prev-1];
                }
            }
        }
        i=0;
        while(i<haystack.length())
        {
            if(haystack.charAt(i)==needle.charAt(j))
            {
                i++;j++;
            }
            else
            {
                if(j==0)
                {
                    j=0;
                    i++;
                }
                else
                {
                    j=lps[j-1];
                }
                
            }
            if(j==needle.length())
            {
                return (i-needle.length());
            }
        }
        return -1;
    }
}
