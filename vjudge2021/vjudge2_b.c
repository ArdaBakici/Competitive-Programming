#include <stdio.h>

int main(){
    unsigned int varN;
    int currentValue;
    int best = 0;
    int i;
    int total = 0;
    int diff = 0;
    scanf("%d", &varN);
    int a;
    long ans = 0, hi = 0, sum = 0, pos = 0;
    for (int i = 1; i <= varN; ++i) {
        scanf("%d", &a);
        sum += a;
        if(sum > hi){
            hi = sum;
        }
        if(pos+hi > ans){
            ans = pos+hi;
        }
        pos += sum;
    }
    /*for(i=0; i<varN;i++){
        scanf("%d", &currentValue);
        diff += currentValue;
        if (diff > 0){
            int k = 0;
            for(k=0;k<i;k++){
                total += list[k];
                if (total > best){
                    best = total;
                }
            }
        }
        else{
            total += diff;
            list[i] = currentValue;
        }
    }*/
    printf("%d\n", ans);
    return 0;
}