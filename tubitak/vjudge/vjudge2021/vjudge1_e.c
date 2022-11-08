#include <stdio.h>

/*
n and m (n 1 to 200000| m 0 to 200000)
m amount of lines
*/

int main(){
    unsigned int n_num_of_nobles;
    unsigned int m_num_friendships;
    unsigned int real_num_friendships;
    unsigned int q_num_of_queries;
    unsigned int friendship_array[400000];
    unsigned int dead_nobles[200000];
    unsigned int dead_noble_num = 0;
    int i;
    scanf("%d", &n_num_of_nobles);
    scanf("%d", &m_num_friendships);
    real_num_friendships = m_num_friendships;
    for(i=0;i<m_num_friendships;i++){
        unsigned int friend_one;
        unsigned int friend_two;
        scanf("%d", &friend_one);
        scanf("%d", &friend_two);
        if(friend_one < friend_two){
            friendship_array[i*2] = friend_one;
            friendship_array[(i*2)+1] = friend_two;
        }
        else{
            friendship_array[i*2] = friend_two;
            friendship_array[(i*2)+1] = friend_one;
        }
    }
    scanf("%d", &q_num_of_queries);
    for(i=0;i<q_num_of_queries;i++){
        int querry_type;
        scanf("%d", &querry_type);
        if(querry_type != 3){
            unsigned int friend_one;
            unsigned int friend_two;
            scanf("%d", &friend_one);
            scanf("%d", &friend_two);
            if(querry_type == 1){
                friendship_array[m_num_friendships*2] = friend_one;
                friendship_array[(m_num_friendships*2)+1] = friend_two;
                m_num_friendships++;
                real_num_friendships++;
            }
            else{
                if(friend_one < friend_two){
                    int j;
                    for(j = 0; j < m_num_friendships; j++){
                        if (friendship_array[j*2] == friend_one){
                            if(friendship_array[(j*2)+1] == friend_two){
                                friendship_array[j*2] = 0;
                                friendship_array[j*2+1] = 0;
                                real_num_friendships--;
                            }
                        }
                    }
                }
            }
        }
        else{
            //calculate
            int k;
            for(k=0;k<m_num_friendships;k++){
                unsigned int risked_noble = friendship_array[k*2];
                int l;
                int isDead = 0;
                for(l=0;l<dead_noble_num;l++){
                    if(risked_noble == dead_nobles[l]) isDead = 1;
                }
                if(isDead == 0){
                    dead_nobles[dead_noble_num] = risked_noble;
                    dead_noble_num++;
                }
            }
            printf("%d", n_num_of_nobles-dead_noble_num);
        }
    }

    return 0;
}