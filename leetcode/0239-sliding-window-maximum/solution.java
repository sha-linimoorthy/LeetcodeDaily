class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
        int n= nums.length;
        int[] result = new int[n-k+1];

        for(int curr_ptr=0;curr_ptr<n;curr_ptr++)
        {
            while(!(dq.isEmpty()) && dq.peekFirst()<curr_ptr-k+1)
            {
                dq.pollFirst();
            }
            while(!(dq.isEmpty()) && nums[dq.peekLast()]<nums[curr_ptr])
            {
                dq.pollLast();
            }
            dq.offerLast(curr_ptr);
            if(curr_ptr>=k-1)
            {
                result[curr_ptr-k+1] = nums[dq.peekFirst()];
            }
        }

        return result;
    }
}
