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
void print3(int len){
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j;
        }
        cout<<endl;
        
    }
}
void print4(int len){
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<i;
        }
        cout<<endl;
        
    }
}
void print5(int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
}

void print6(int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i; j++)
        {
            cout<<j+1;
        }
        cout<<endl;
        
    }
}
void print7(int len){
    for (int i = 0; i < len; i++)
    {
        for (int space = 0; space < len-i-1; space++)
        {
            cout<<" ";
        }
        
        for (int j = 0; j < 2*i+1; j++)
        {
            cout<<"*";
        }

        for (int space = 0; space < len-i-1; space++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}

void print8(int len){
    for (int i = 0; i < len; i++)
    {
        for (int space = 0; space < i; space++)
        {
            cout<<" ";
        }
        
        for (int j = 0; j < 2*len-(2*i+1); j++)
        {
            cout<<"*";
        }

        for (int space = 0; space < i; space++)
        {
            cout<<" ";
        }
        
        cout<<endl;
    }
}
void print9(int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
}
void print10(int len){
    for (int i = 0; i <= 2*len-1; i++)
    {
        int stars = i;
        if(i>len){
            stars = 2*len-i;
        }
        for (int j = 0; j < stars; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
        
    }
}

void print11(int len){
    int start = 1;
    for (int i = 0; i < len; i++)
    {

        if(i%2==0) start = 1;
        else start = 0;
        for (int j = 0; j <=i; j++)
        {
            cout<<start;
            start = 1-start;
        } 
        cout<<endl;
    }
}

void print12(int len){
    for(int i=1;i<=len;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int x=1;x<=2*len-2*i;x++){
            cout<<" "; 
        }
        for(int z=i;z>=1;z--){
            cout<<z;
        }
        cout<<endl;
    }
}

void print13(int len){
    int count = 1;
    for(int i=1;i<=len;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<' ';
            count++;
        }
        cout<<endl;
    }
}

void print14(int len){
    int count = 0;
    for(int i=0;i<len;i++){
        for(char ch='A';ch<='A'+i;ch++){
            cout<<ch<<' ';
        }
        cout<<endl;
    }
}

void print15(int len){
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len-i;j++){
            cout<<" ";
        }
        for(int k=1;k<=i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int len;
    cin>>len;
    // print7(len);
    // print8(len);
    print15(len);
}