#include<iostream>
using namespace std;
void print1(int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
}
void print2(int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
}
int main(){
    int len;
    cin>>len;
    print2(len);
}