#include <stdio.h>

int main(){
    int n, x, i;
    long long num_of_op = 0;
    unsigned int candy[100000];
    scanf("%d", &n);
    scanf("%d", &x);
    for(i = 0; i < n; i++){
        scanf("%d", &candy[i]);
    }

    for(i = 0; i < n-1; i++)
    {
        if((candy[i] + candy[i+1]) > x){
            int extra_candy = (candy[i] + candy[i+1])-x;
            num_of_op += extra_candy;
            if(extra_candy > candy[i+1]){
                candy[i] -= extra_candy - candy[i+1];
                candy[i+1] = 0;
            }
            else{
                candy[i+1] -= extra_candy;
            }
        }
    }
    printf("%lld\n", num_of_op);
}