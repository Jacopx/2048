//
//  main.c
//  2048
//
//  Created by Jacopo Nasi on 04/11/2016.
//  Copyright © 2016 Jacopo Nasi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

int **allocmap(int n);
void mapprint(int n, int **map);
void randmap(int dim, int n, int **map);
int check(int n, int **map);

int main(int argc, const char * argv[]) {
    int **map=allocmap(N), go=1;
    mapprint(N, map);
    printf("\n\n");
    randmap(N, 2, map);
    mapprint(N, map);
    
    while(go)
    {
        randmap(N, 1, map);
        system("clear");
        go=check(N, map);
        mapprint(N, map);
    }
    
    return 0;
}

int check(int n, int **map) {
    
}

void randmap(int dim, int n, int **map) {
    int i,j,r=0;
    srand(time(NULL));
    for(r=0;r<n;r++)
    {
        i=rand()%dim; j=rand()%dim; map[i][j]=2;
    }
}

int **allocmap(int n) {
    //matrix N*N of Integer
    int **matrix=malloc(n*sizeof(int *));
    for(int i=0; i<n; i++)
        matrix[i]=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrix[i][j]=0;
    
    return matrix;
}

void mapprint(int n, int **map) {
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    
    return;
}
