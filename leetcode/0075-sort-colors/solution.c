void swap(int* p, int* q){
    *p = *p^*q;
    *q = *p^*q;
    *p = *p^*q;
}

void sortColors(int* nums, int numsSize) {
    int sorted_arr[numsSize];
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j>0 && nums[j]<nums[j-1];j--){
            swap(&nums[j],&nums[j-1]);
        }

    }    
}
