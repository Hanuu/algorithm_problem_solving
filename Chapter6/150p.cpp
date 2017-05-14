#include <iostream>


char box[5][5];
char word[10];

void hasword(int length){
    if(length==0){
        printf("YES");
    }
}


int main(){
    int t;
    cin >> t;
    int n;
    for(int tc=1;tc<=t;tc++){
        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                scanf("%c",box[row][col]);
            }
        }
        
        cin >> n;
        for(int eachword=0;eachword<n;eachword++){
            scanf("%s",word);
            printf("%s ",word);
            hasword(word.size())
        }
        
        
    }
}