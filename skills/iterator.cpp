#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> list1;
    // list1[0]=0;
    // list1[1]=1
    // list1[2]=2; 
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list<int>::iterator iterFirst=list1.begin();
    list1.insert(iterFirst,100);
    list1.insert(iterFirst,2,200);
    list<int> list2;
    list2.push_back(11);
    list2.push_back(22);
    list2.push_back(33);
    list<int>::iterator it=list2.begin();
    list2.insert(it,list1.begin(),list1.end());
    
    list<int>::iterator iterEnd=list1.end();
    
    cout<< "list1 printing..."<<endl;
    for(list<int>::iterator iterPos=list1.begin();iterPos!=iterEnd;iterPos++){
        cout<<*iterPos<<endl;
    }
    cout<<"list2 printing..."<<endl;
    for(list<int>::iterator iterPos2=list2.begin();iterPos2!=list2.end();iterPos2++){
        cout<< *iterPos2 <<endl;
    }
    list<int>::iterator iterPos3=list1.begin();
    list1.erase(++iterPos3);
    
    list2.erase(++list2.begin(),--list2.end());
    cout<< "list1 printing..."<<endl;
    for(list<int>::iterator iterPos=list1.begin();iterPos!=iterEnd;iterPos++){
        cout<<*iterPos<<endl;
    }
    cout<<"list2 printing..."<<endl;
    for(list<int>::iterator iterPos2=list2.begin();iterPos2!=list2.end();iterPos2++){
        cout<< *iterPos2 <<endl;
    }
}