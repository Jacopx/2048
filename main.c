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
void gmove(int n, int **map);

int main(int argc, const char * argv[]) {
    int **map=allocmap(N), go=1;
//    mapprint(N, map);
//    printf("\n\n");
//    randmap(N, 2, map);
//    mapprint(N, map);
    
    //game play
    while(go)
    {
        gmove(N, map);
        randmap(N, 1, map);
        go=check(N, map);
        system("clear");
        mapprint(N, map);
    }
    
    //free matrix
    
    return 0;
}

void gmove(int n, int **map) {
    char ch[2],c; int f=1;
    //ask move
    puts("\nGiocata: ");
    scanf(" %s", ch); c=ch[0];
    while(f)
    {
        //up move
        if(c=='w')
        {
            
            f=0;
        }
        //left move
        else if(c=='a')
        {
            
            f=0;
        }
        //down move
        else if(c=='s')
        {
            
            f=0;
        }
        //right move
        else if(c=='d')
        {
            
            f=0;
        }
    }

}

int check(int n, int **map) {
    //playable?
    
    return 1;
}

void randmap(int dim, int n, int **map) {
    int i,j,r=0;
    //n ramdom number in [0,dim)
    srand(time(NULL));
    for(r=0;r<n;r++)
    {
        i=rand()%dim; j=rand()%dim;
        if(map[i][j]==0)
            map[i][j]=2;
        else
            r--;
    }
}

int **allocmap(int n) {
    //matrix N*N of Integer
    int **matrix=malloc(n*sizeof(int *));
    for(int i=0; i<n; i++)
        matrix[i]=malloc(n*sizeof(int));
    //clean matrix
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrix[i][j]=0;
    
    return matrix;
}

void mapprint(int n, int **map) {
    //print table
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    
    return;
}
