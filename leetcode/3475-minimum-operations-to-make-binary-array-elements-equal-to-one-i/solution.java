class Solution {
    public int minOperations(int[] nums) {
        int count=0;
        int frst_ptr=0;
        boolean is_one=false;
        while(frst_ptr<nums.length-2)
        {
            System.out.println(is_one);
            if(nums[frst_ptr]==1)
            {
                if(nums[frst_ptr]>nums.length-2) 
                {
                    
                }
                frst_ptr++;
                is_one=true;
            }
            else{
                is_one=false;
                    for(int i=frst_ptr;i<frst_ptr+3;i++)
                    {
                        if(nums[i]==0) 
                        {
                            nums[i]=1;
                        }
                        else {
                            nums[i]=0;
                        }
                    }
                    count++;
                    frst_ptr++;

            }
        }
        System.out.println(is_one);
        if(nums[frst_ptr]==1 && nums[frst_ptr+1]==1) 
        {
            return count;
        }
        else 
        {
            return -1;
        }
        
    }
}
