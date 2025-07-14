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

void bitwiseOperations() {
    int a = 5; // 0101
    int b = 3; // 0011

    // AND 0001 -> 1
    // OR 0111 -> 7
    // XOR 0110 -> 6
    // NOT 1010 (inverts all bits) -> -6
    // Left Shift 1010 (5*2 = 10) -> 10
    // Right Shift 0010 (5/2 = 2) -> 2 = x>>k = x/(2^k)
    //Largest integer is 2^31-1, so we can use 32 bits for representation INT_MAX
    // Smallest integer -2^31, so we can use 32 bits for representation INT_MIN

    cout << "Bitwise AND: " << (a & b) << endl; 
    cout << "Bitwise OR: " << (a | b) << endl; 
    cout << "Bitwise XOR: " << (a ^ b) << endl;
    cout << "Bitwise NOT: " << (~a) << endl; 
    cout << "Left Shift: " << (a << 1) << endl; 
    cout << "Right Shift: " << (a >> 1) << endl;
}

void swap(int &a, int &b) {
    a = a ^ b; 
    b = a ^ b; //(a = a ^ b)^b = a ^ b ^ b = a
    a = a ^ b; // (a = a ^ b)^a = a ^ b ^ a = b
}

void checkIfIthBitIsSet(int n, int i) {
    if((n & (1 << i))!= 0) {
        cout << "The " << i << "th bit is set." << endl;
    } else {
        cout << "The " << i << "th bit is not set." << endl;
    }
}

void checkIfIthBitIsSetSecondApproach(int n, int i) {
    if(((n>>i) & 1)!= 0) {
        cout << "The " << i << "th bit is set." << endl;
    } else {
        cout << "The " << i << "th bit is not set." << endl;
    }
}

int setIthBit(int n, int i) {
    return n | (1 << i);
}

int clearIthBit(int n, int i) {
    return n & ~(1 << i);
}

int toggleIthBit(int n, int i) {
    return n ^ (1 << i);
}

int removeLastSetBit(int n) {
    return n & (n - 1);
}

bool checkIfPowerOf2(int n) {
    return (n&n-1) == 0;
}

int countSetBits(int n) {
    //1101
    //0001 ->1
    //0010 -> 0
    //0100 -> 1 
    //1000 -> 1
    //Total 3 set bits
    int count = 0;
    while(n > 0) {
        count += n & 1; 
        n >>= 1; 
    }
    return count;
}

int main(){
    string s = convertToBinary(10);
    cout << "Binary representation of 10 is: " << s << endl;
    cout<<"Decimal representation of 1010 is: "<<convertToDecimal("1010")<<endl;
    bitwiseOperations();
    int a = 5, b = 3;
    swap(a, b);
    cout << "After swapping: ";
    cout<< a << " " << b << endl;
    // checkIfIthBitIsSet(13, 1);
    // checkIfIthBitIsSet(13, 2);
    checkIfIthBitIsSetSecondApproach(13, 1);
    checkIfIthBitIsSetSecondApproach(13, 2);
    cout<<setIthBit(9, 2)<<endl;
    cout<<clearIthBit(13, 2) << endl;
    cout<<clearIthBit(9, 2) << endl;  
    cout<<toggleIthBit(13, 1) << endl;
    cout<<removeLastSetBit(40) << endl;
    cout<< checkIfPowerOf2(32) << endl;
    cout<< checkIfPowerOf2(15) << endl;
    cout<< countSetBits(13) << endl;
}