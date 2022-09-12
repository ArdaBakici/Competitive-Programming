#include <stdio.h>

int main(){
    int i;
    int friendList[300000];
    int costList[300000];
    int numOfCases;
    scanf("%d", &numOfCases);
    for(i=0; i<numOfCases; i++){
        unsigned int sum = 0;
        int n, m, k, a, j, l;
        
        scanf("%d", &n);
        scanf("%d", &m);

        for(k = 0; k < n; k++){
            scanf("%d", &friendList[k]);
        }
         
        for(k = 0; k < m; k++){
            scanf("%d", &costList[k]);
        }

        // order array
        for (l = 0; l < n; ++l) 
        {
            for (j = l + 1; j < n; ++j) 
            {
                if (friendList[l] < friendList[j]) 
                {
                    a = friendList[l];
                    friendList[l] = friendList[j];
                    friendList[j] = a;
                }
            }
        }

        // count sum
        int lastOne = 0;
        int lastGift = 0;
        for(j = 0; j<n; j++){
            if(costList[lastGift] < costList[friendList[j]-1]){
                sum += costList[lastGift++];
            }
            else{
                sum += costList[friendList[j]-1];
            }
        }
        printf("%d\n", sum);
    }
}