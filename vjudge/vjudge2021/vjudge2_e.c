#include <stdio.h>

int main(){
    unsigned int varN, varM, varQ;
    int list[200000][2];
    int opList[200000][1];
    int x, y, i;
    scanf("%d", &varN);
    for(i=0; i<varN;i++){
        scanf("%d", &list[i][0]);
        scanf("%d", &list[i][1]);
    }
    scanf("%d", &varM);
    for(i=0; i<varM;i++){
        scanf("%d", &list[i][0]);
        scanf("%d", &list[i][1]);
    }
    scanf("%d",&varQ);
    for(i=0; i<varQ;i++){
        scanf("%d", &list[i][0]);
        scanf("%d", &list[i][1]);
    }
    return 0;
}