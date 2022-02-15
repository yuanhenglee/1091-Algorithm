#define MAX_H 200
#define MIN_H 150

int N,M,ANS;
int **Height;
int *Used;

int GetMin( int *set ){
    int min = 0;
    for( int i = 0 ; i < M ; ++i )
        min = set[i]<set[min]?i:min; 
    set[min] = __INT_MAX__;
    return min;
}

int SequenceCompare( int *a , int *b ){
    for( int i = 0 ; i < M ; ++i ){
        if(a[i]>b[i])
            return 0;
    }
    return 1;
}

int MaxSeqUsing( int i ){
    if(Used[i]>0) return Used[i];
    for( int j = i+1 ; j < M ; ++j ){
        if(SequenceCompare( Height[i],Height[j] )){
            Used[i] = 1 + MaxSeqUsing( j );
            ANS = Used[i]>ANS?Used[i]:ANS;
            return Used[i];
        }
    }
    Used[i] = 1;
    return Used[i];
}
int main(){
    scanf("%d%d",&M,&N);
    int **CountingTable = calloc(M,sizeof(int*));
    int *TableMin = calloc(M,sizeof(int));
    Height= calloc(M,sizeof(int));
    for( int i = 0 ; i < M ; ++i ){
        CountingTable[i] = calloc(MAX_H-MIN_H+1,sizeof(int));
        for( int j = 0 ; j <= MAX_H-MIN_H ; ++j )
            CountingTable[i][j] = 0;
        Height[i] = calloc(N,sizeof(int));
        for( int j = 0 ; j < N; ++j )
            Height[i][j] = 0;
    }
    int input;
    for( int i = 0 ; i < M ; ++i ){
        TableMin[i] = __INT_MAX__;
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d",&input);
            ++CountingTable[i][input-MIN_H];
            TableMin[i] = input<TableMin[i]? input : TableMin[i];
        }
    }
    /* for( int i = 0 ; i < M ; ++i ) */
    /*     for( int j = 0 ; j <= MAX_H-MIN_H ; ++j ) */
    /*         printf("%d",CountingTable[i][j]); */

    for( int i = 0 ; i < M ; ++i ){
        int MinStart = GetMin(TableMin);
        int j = 0;
        for( int k = MIN_H ; k <= MAX_H ; ++k ){
            for( int l = 0 ; l < CountingTable[MinStart][k-MIN_H] ; ++l ){
                Height[i][j++] = k;
            }
        }
    }
    free(TableMin);
    for( int i = 0 ; i < M ; ++i )
        free(CountingTable[i]);
    /* for( int i = 0 ; i < M ; ++i ){ */
    /*     for( int j = 0 ; j < N ; ++j ) */
    /*         printf("%d\t",Height[i][j]); */
    /*     printf("\n"); */
    /* } */
    ANS = 1;
    Used = calloc(M,sizeof(int));
    MaxSeqUsing(0);
    /* for( int i = 0 ; i < M ; ++i ){ */
    /*     printf("%d\t",Used[i]); */
    /* } */
    printf("%d",ANS);
    free(Used);
    for( int i = 0 ; i < M ; ++i )
        free(Height[i]);

    return 0;
}
