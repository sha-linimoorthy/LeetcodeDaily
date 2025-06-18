class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> result = new ArrayList<>();
        if(s.length()<10)
        {
            return result; 
        }
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        String curr_str;
        for(int frst_ptr=0,scnd_ptr=9;frst_ptr<=(s.length()-10);frst_ptr++,scnd_ptr++)
        {
            curr_str = s.substring(frst_ptr,scnd_ptr+1);
            map.put(curr_str,(map.getOrDefault(curr_str,0))+1);
            System.out.println(curr_str);
        }

        for(String key: map.keySet())
        {
            if(map.get(key) > 1)
            {
                result.add(key);
            }
        }

        return result;
        
    }
}
