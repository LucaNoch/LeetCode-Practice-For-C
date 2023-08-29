// Solution 1 (stack)
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int i, j, num, flag = 0, *ret = (int *)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;

    for (i = 0; i < nums1Size; i++)
    {
        for (j = 0, flag = 0; j < nums2Size; j++)
        {
            if (flag)
            {
                if (nums2[j] > num)
                {
                    num = nums2[j];
                    break;
                }
            }
            else if (nums1[i] == nums2[j])
            {
                ret[i] = nums2[j];
                num = nums2[j];
                flag++;
            }
        }
        if (num == ret[i])
        {
            ret[i] = -1;
        }
        else
        {
            ret[i] = num;
        }
    }
    return ret;
}

// Solution 2
#define MAX_STACK_SIZE 10000

struct Stack{
    int element[MAX_STACK_SIZE];
    int top;
};

void init(struct Stack *s){
    s->top = -1;
}

void push(struct Stack *s, int element){
    if(s->top + 1 == MAX_STACK_SIZE)
        return;
    s->element[++(s->top)] = element;
}

int pop(struct Stack *s){
    if(s->top - 1 < -1) return -1;
    return s->element[(s->top)--];
}

int peek(struct Stack *s){
    if(s->top - 1 < -1) return -1;
    return s->element[(s->top)];
}


int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    struct Stack *s = malloc(sizeof(struct Stack));
    init(s);
    int *ans = malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;    
    int hashset[MAX_STACK_SIZE];
    push(s, nums2[0]);
    for(int i = 1; i < nums2Size; i++){
        if(peek(s) < nums2[i]){
            while(s->top >= 0 && peek(s) < nums2[i]){
                hashset[pop(s)] = nums2[i];
            }
            push(s,nums2[i]);
        }
        else{
            push(s,nums2[i]);
        }
    }

    while(s->top > -1){
        hashset[pop(s)] = -1;
    }
    

    for(int i = 0; i < nums1Size; i++){
        ans[i] = hashset[nums1[i]];
    }

    free(s);
    return ans;
}