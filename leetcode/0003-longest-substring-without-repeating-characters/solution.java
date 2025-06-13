class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0)
        {
            return 0; //doubt to return 0 or -1
        }
        else if(s.length()==1)
        {
            return 1;
        }
        int s_len = s.length();
        String curr = String.valueOf(s.charAt(0));
        String max = curr;
        int frst_ptr=0, scnd_ptr=frst_ptr+1;
        while(frst_ptr<s_len-1 && scnd_ptr<s_len)
        {
            if(!curr.contains(String.valueOf(s.charAt(scnd_ptr))))
            {
                curr+=String.valueOf(s.charAt(scnd_ptr));
                scnd_ptr++;
                if(curr.length()>max.length())
                {
                    max = curr;
                }
            }
            else
            {
                frst_ptr++;
                scnd_ptr=frst_ptr+1;
                curr=String.valueOf(s.charAt(frst_ptr));
            }
        } 

        return max.length();
    }
}
