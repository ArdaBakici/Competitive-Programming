#include <stdio.h>

int main(){
    char inputArray[10000];
    char outputArray[10000];
    int animal_num;
    int i;
    int j;
    char n_assump;
    int assump; // 1 if ss/sw | 2 if ww/ws
    scanf("%d", &animal_num);
    scanf("%s", inputArray);

    for(j=0; j<5; j++){
        switch (j)
        {
            case 0:
                outputArray[0] = 'S';
                if (inputArray[0] == 'o'){
                    // ss or ww
                    outputArray[1] = 'S';
                    n_assump = 'S';
                }
                else{
                    // sw or ws
                    outputArray[1] = 'S';
                    n_assump = 'W';
                }
                break;
            case 1:
                outputArray[0] = 'S';
                if (inputArray[0] == 'o'){
                    // ss or ww
                    outputArray[1] = 'W';
                    n_assump = 'W';
                }
                else{
                    // sw or ws
                    outputArray[1] = 'W';
                    n_assump = 'S';
                }
                break;
            case 2:
                outputArray[0] = 'W';
                if (inputArray[0] == 'o'){
                    // sw or ws
                    outputArray[1] = 'S';
                    n_assump = 'W';
                }
                else{
                    // ss or ww
                    outputArray[1] = 'S';
                    n_assump = 'S';
                }
                break;
            case 3:
                outputArray[0] = 'W';
                if (inputArray[0] == 'o'){
                    // sw or ws
                    outputArray[1] = 'W';
                    n_assump = 'S';
                }
                else{
                    // ss or ww
                    outputArray[1] = 'W';
                    n_assump = 'W';
                }
                break;
            case 4:
                printf("-1");
                return 0;
        }

        for(i=1; i<animal_num-1; i++){
            if (outputArray[i] == 'S'){
                if (inputArray[i] == 'o'){
                    // i-1 and i+1 same
                    outputArray[i+1] = outputArray[i-1];
                }
                else{
                    // i-1 and i+1 different
                    if (outputArray[i-1] == 'S'){
                        outputArray[i+1] = 'W';
                    }
                    else{
                        outputArray[i+1] = 'S';
                    }
                }
            }
            else{
                if (inputArray[i] == 'x'){
                    // i-1 and i+1 same
                    outputArray[i+1] = outputArray[i-1];
                }
                else{
                    // i-1 and i+1 different
                    if (outputArray[i-1] == 'S'){
                        outputArray[i+1] = 'W';
                    }
                    else{
                        outputArray[i+1] = 'S';
                    }
                }
            }
        }

        if (outputArray[animal_num-1] == n_assump){
            if(inputArray[animal_num-1] == 'o'){
                if(n_assump == 'S'){
                    if (outputArray[0] == outputArray[animal_num-2]){
                        printf("%s", outputArray);
                        return 0;
                    }
                }
                else{
                    if (outputArray[0] != outputArray[animal_num-2]){
                        printf("%s", outputArray);
                        return 0;
                    }
                }
            }
            else{
                if(n_assump == 'W'){
                    if (outputArray[0] == outputArray[animal_num-2]){
                        printf("%s", outputArray);
                        return 0;
                    }
                }
                else{
                    if (outputArray[0] != outputArray[animal_num-2]){
                        printf("%s", outputArray);
                        return 0;
                    }
                }
            }
        }
    }
}