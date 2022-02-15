#include <stdio.h>
#include <stdlib.h>

# define MAX_N 100000

int Cur_P = 0, Max_P = 0, i = 0, j = 0;
int *BrickHeight ;


void FindMax(){
    Cur_P = 0;
    for( int k = j+1 ; k != j ; k=(k+1)%i ){
        /* printf("%d/%d\n",k,j); */
        Cur_P += BrickHeight[k];
        Max_P = Cur_P > Max_P ? Cur_P : Max_P;
        if( Cur_P < 0 ){
            Cur_P = 0;
            if( j < k ){
                j = k;
                /* printf("skipping to %d\n",k); */
                return;
            }
            break;
        }
    }
    ++j;
}

int main(){
    BrickHeight = calloc(MAX_N,sizeof(int));
    while( scanf("%d",&BrickHeight[i]) > 0 ){
        if( i == 0 || BrickHeight[i-1]*BrickHeight[i] < 0)
            ++i;
        else
            BrickHeight[i-1]+=BrickHeight[i];
    }
    if( i == 1 ){
        printf("%d",BrickHeight[0]);
        return 0;
    }
    while(  j < i  ){
        if( BrickHeight[j]>0 ) {
            ++j;
            continue;
        }
        FindMax();
    }




    printf("%d",Max_P);
    free(BrickHeight);
    return 0;
}

