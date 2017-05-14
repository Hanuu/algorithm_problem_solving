#include<iostream>
#include<string>

using namespace std;

char answer[1000];

string reverse(string::iterator &it){
    char head = *it;
    ++it;
    if(head=='b'){
        return "b";
    }
    else if(head=='w'){
        return "w";
    }
    string one = reverse(it);
    string two = reverse(it);
    string three = reverse(it);
    string four = reverse(it);
    
    return "x"+ three + four + one +two;
}

int main(){
    freopen("189p.in.txt","r",stdin);
    
    int t;
    cin>> t;
    char picture[1000];
    for(int tc=1;tc<=t;tc++){
        scanf("%s",picture);
        printf("%s\n",picture);
        string::iterator it = picture.begin();
        cout << reverse(it)<<endl;
    }
}