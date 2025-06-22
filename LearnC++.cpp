#include <iostream>
using namespace std;

int sum(int a ,int b){
    return a+b;
}
void doSomething(int num){
    cout<< num <<endl;
    num+= 5;
    cout<< num <<endl;
    num+= 5;
    cout<< num <<endl;
    num+= 5;
    cout<< num <<endl;
}
void changeName(string &s){
    cout<<s<<endl;
    s[0] = 't';
    cout<<s<<endl;
}
void updateArray(int arr[],int len){
    arr[0]+= 100;
    cout<<"Value of arr[0] inside function is "<<arr[0]<<endl;
}
int main(){
    // string s;
    // getline(cin,s);
    // changeName(s);
    int n=5;
    int arr[n];
    for (int i = 0; i <= n-1; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    updateArray(arr,n);
    cout<<"Value of arr[0] is "<<arr[0];
    
}