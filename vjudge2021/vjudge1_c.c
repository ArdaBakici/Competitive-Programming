#include <stdio.h>

int main(){
    unsigned int n;
    char inputArray[200000];
    int i;
    unsigned int num_of_red = 0;
    unsigned int num_of_op = 0;
    scanf("%d", &n);
    scanf("%s", inputArray);
    for(i=0; i<n; i++){
        if (inputArray[i] == 'R') num_of_red++;
    }
    for (i=0; i<num_of_red; i++){
        if (inputArray[i] == 'W') num_of_op++;
    }
    printf("%d", num_of_op);
}