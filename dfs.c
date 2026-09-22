#include<stdio.h>

int grap [5][5] = {

    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1},
    {0,2,0,0,1},
    {0,0,1,1,0}
};

int visited[5] = {0};

void dfs(int v){
    printf("%d",v);
    visited[v] = 1;

    for(int i = 0 ; i < 5 ; i++){
        if(grap[v][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    dfs(0);
    return 0 ;
}
