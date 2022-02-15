#include <stdio.h>
#include <stdlib.h>

# define MAX_N 100000


int main(){
    int *BrickHeight = calloc(MAX_N,sizeof(int));
    int i = 0,Sum = 0,Cur_max = 0,Total_max = 0,Cur_min = 0,Total_min = 0;
    while( scanf("%d",&BrickHeight[i]) > 0 ){
        Sum += BrickHeight[i];
        Cur_max += BrickHeight[i];
        Cur_min += BrickHeight[i];
        Cur_max = Cur_max>0? Cur_max:0;
        Cur_min = Cur_min<0? Cur_min:0;
        Total_max = Cur_max>Total_max? Cur_max:Total_max;
        Total_min = Cur_min<Total_min? Cur_min:Total_min;
        ++i;
    }
    if( Total_max > Sum - Total_min )
        printf("%d",Total_max);
    else
        printf("%d",Sum-Total_min);
    free(BrickHeight);
    return 0;
}

