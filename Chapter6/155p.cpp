#include <iostream>
#include <vector>
#include<stdio.h>

using namespace std;

int howmany(bool (&taken)[10],int n,int m);

int friends[10][10];

int main(){
    int c;
    cin >> c;
    for(int i=0; i<c;i++){
        for(int first=0;first<=9;first++){
            for(int second=0;second<=9;second++){
                friends[first][second]=0;
            }
        }
        
        int n,m;
        cin >> n;
        cin >> m;
        int temp1,temp2;
        for(int j=1;j<=m;j++){
            cin>>temp1;
            cin>>temp2;
            friends[temp1][temp2]=1;
            friends[temp2][temp1]=1;
        }
        bool taken[10];
        for(int students=0;students<10;students++){
            taken[students]=false;
        }
        cout<<endl;
        cout<<howmany(taken,n,m)<<endl;
        
    }
}
int howmany(bool (&taken)[10],int n,int m){
    int minimum=-1;
    for(int i=0;i<n;i++){
        if(!taken[i]){
            minimum=i;
            break;
        }
    }
    if(minimum==-1){
        return 1;
    }
    int ret=0;
    for(int candidate=minimum+1;candidate<n;candidate++){
        if(!taken[candidate]&&friends[candidate][minimum]){
            taken[candidate]=true;
            taken[minimum]=true;
            // printf("\n%d,%d\n",candidate,minimum);
            ret+=howmany(taken,n,m);
            // printf("the ret now is %d\n",ret);
            taken[candidate]=false;
            taken[minimum]=false;
        }
    }
    return ret;
}