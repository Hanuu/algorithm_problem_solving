#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void pick(int n,vector<int>& picked, int toPick){
    if(toPick==0){
        for(int order=0;order<picked.size();order++){
            printf("%d ",picked[order]);
        }
        printf("\n");
        return;
    }
    int smallest=picked.empty() ? 0:picked.back() + 1;
    
    for(int next = smallest; next < n; ++next){
        picked.push_back(next);
        pick(n, picked,toPick - 1);
        picked.pop_back();
    }
}

int main(){
    vector<int> picked;
    // for(int n=1;n<=8;n++){
    //     picked.push_back(n);
    // }
    // printf("%d",picked[1]);
    pick(8,picked,4);
}