class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum=Integer.MIN_VALUE,currSum=0;
        int rightPtr;

        for(rightPtr=0;rightPtr<nums.length;rightPtr++)
        {
            currSum+=nums[rightPtr];
            if(nums[rightPtr]>currSum)
            {
                currSum=nums[rightPtr];
            }

            if(currSum>maxSum)
            {
                maxSum=currSum;
                System.out.println(maxSum);

            }
            

        }
        return maxSum;
    }
}
