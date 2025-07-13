#include<iostream>
#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int number) {
    string binary = "";
    while(number>0){
        binary+= number%2==0 ? '0' : '1';
        number /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int convertToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();
    int power = 0;
    for(int i = length-1; i >= 0; i--) {
        if(binary[i]=='1'){
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main(){
    string s = convertToBinary(10);
    cout << "Binary representation of 10 is: " << s << endl;
    cout<<"Decimal representation of 1010 is: "<<convertToDecimal("1010")<<endl;
}