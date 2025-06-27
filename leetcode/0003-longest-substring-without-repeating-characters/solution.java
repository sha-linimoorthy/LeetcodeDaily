class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> unique_chars = new HashSet<Character>();
        int right_ptr,left_ptr=0,max_len=0;

        for(right_ptr=0;right_ptr<s.length();right_ptr++)
        {
            while(unique_chars.contains(s.charAt(right_ptr)))
            {
                unique_chars.remove(s.charAt(left_ptr));
                left_ptr++;
            }
            unique_chars.add(s.charAt(right_ptr));
            max_len=(max_len<right_ptr-left_ptr+1)?(right_ptr-left_ptr+1):max_len;
        }

        return max_len;
        
    }
}
