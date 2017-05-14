#include<iostream>

using namespace std;


bool block[20][20];

const int coverType[4][3][2]={
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};
bool canCover(int mh,int mw,int h,int w,int type){
    if(mh+coverType[type][1][0]<0||mh+coverType[type][1][0]>=h){
        return 0;
    }
    if(mw+coverType[type][1][1]<0||mw+coverType[type][1][1]>=w){
        return 0;
    }
    if(mh+coverType[type][2][0]<0||mh+coverType[type][2][0]>=h){
        return 0;
    }
    if(mw+coverType[type][2][1]<0||mw+coverType[type][2][1]>=w){
        return 0;
    }
    
    if(block[mh+coverType[type][1][0]][mw+coverType[type][1][1]]==0){
        if(block[mh+coverType[type][2][0]][mw+coverType[type][2][1]]==0){
            return 1;
        }
    }
    return 0;
}
int minumumhw(int &mh,int &mw,int h,int w){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(block[i][j]==0){
                mh=i;
                mw=j;
                // printf("%d %d\n",i,j);
                return 0;
            }
        }
    }
    return 1;
}

int howmanyways(int h,int w){
    
    
    int mh=-1,mw=-1;
    if(minumumhw(mh,mw,h,w)==1){
        return 1;   
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            // printf("%d",block[i][j]);
        }
        // printf("\n");
    }
    // printf("mh: %d mw: %d\n",mh,mw);
    // printf("\n");
    int ret=0;
    for(int type=0;type<4;type++){
        if(canCover(mh,mw,h,w,type)==1){
            block[mh+coverType[type][1][0]][mw+coverType[type][1][1]]=1;
            block[mh+coverType[type][2][0]][mw+coverType[type][2][1]]=1;
            block[mh][mw]=1;
            // printf("type: %d\n",type);
            ret+=howmanyways(h,w);
            block[mh+coverType[type][1][0]][mw+coverType[type][1][1]]=0;
            block[mh+coverType[type][2][0]][mw+coverType[type][2][1]]=0;
            block[mh][mw]=0;
        }
    }
    // printf("%d %d\n",mh,mw);
    return ret;
    
}

int main(){
    
    freopen("161p.in.txt","r",stdin);
    int t;
    cin>> t;
    int h,w;
    for(int tc=1;tc<=t;tc++){
        cin>> h;
        cin>> w;
        
        char temp='?';
        for(int height=0;height<h;height++){
            for(int width=0;width<w;width++){
                cin>>temp;
                if(temp=='#'){
                    block[height][width]=1;
                }
                else if(temp=='.'){
                    block[height][width]=0;
                }
            }
        }
        
        printf("%d\n",howmanyways(h,w));
    }
    
}