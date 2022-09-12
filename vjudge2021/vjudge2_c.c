#include <stdio.h>

int main(){
    char list[300000];
    unsigned int numOfRooms;
    unsigned int numOfCases;
    unsigned int i, k;
    scanf("%d", &numOfCases);
    for(i=0; i<numOfCases;i++){
        scanf("%d", &numOfRooms);
        scanf("%s", list);
        unsigned int returnableRooms = 0;
        int returnPossible = 1;
        int anyclockwise = 0;
        int anyanticlockwise = 0;
        for(k = 0; k < numOfRooms; k++){
            //if a room iş hosted by off it is returnable
            if(k == 0){
                if(list[k] == '-' || list[numOfRooms-1] == '-'){
                    returnableRooms++;
                }
            }
            else{
                if(list[k] == '-' || list[k-1] == '-'){
                    returnableRooms++;
                }
            }
            if(list[k] == '>'){
                anyclockwise = 1;
                if(anyanticlockwise){
                    returnPossible = 0;
                }
            }
            else if(list[k] == '<'){
                anyanticlockwise = 1;
                if(anyclockwise){
                    returnPossible = 0;
                }
            }
        }
        if(returnPossible){
            printf("%d\n", numOfRooms);
        }
        else{
            printf("%d\n", returnableRooms);
        }
    }
    return 0;
}