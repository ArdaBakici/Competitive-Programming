#include <stdio.h>

int main(){
    unsigned int primeNumber;
    unsigned int numOfCases;
    int i;
    scanf("%d", &numOfCases);
    for(i=0; i<numOfCases;i++){
        scanf("%d", &primeNumber);
        printf("%d %d\n", 2, primeNumber-1);
    }
    return 0;
}