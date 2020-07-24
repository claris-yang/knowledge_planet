
#include <stdlib.h>
#include <stdio.h>

int* sub_permute(int *nums, int cur, int numsSize, int **rsp, int *returnSize) {
    if(cur == numsSize) {
        int *p = malloc(numsSize * sizeof(int));
        
        return
    }
    
        
    for(int i = 0; i < numsSize; i++) {
        int flag = 1;
        for(int j = 0; j < cur; j++) 
            if( nums[j] == nums[i]) {
                flag = 0;
                break;
            }
        
        if (flag == 1) {
            nums[cur] = nums[i];
            sub_permute(nums, cur + 1, numsSize, rsp, returnSize);
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize) {
    int **rsp;
    sub_permute( *nums,  cur,  numsSize, rsp, returnSize);    

}

void main() {
}
