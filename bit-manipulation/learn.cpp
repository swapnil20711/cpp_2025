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

int numberOfBitFlips(int start,int goal){
    int ans = start ^ goal; 
    int count = 0;
    while(ans > 0) {
        count += ans & 1;
        ans >>= 1; 
    }
    return count;
}

vector<vector<int>> generateSubsets(vector<int> &nums) {
    vector<vector<int>> subsets;
    int n = nums.size();
    int totalSubsets = 1 << n; 
    for(int i =0 ;i<totalSubsets; i++) {
        vector<int> subset;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        subsets.push_back(subset);  
    }
    return subsets;
}
int singleNumber(vector<int> &nums) {
    int result = 0;
    for(int num:nums){
        result ^= num; 
    }
    return result;
}

int singleNumberBruteForce(vector<int> &nums) {
    map<int, int> countMap;
    for(int num: nums) {
        countMap[num]++;
    }
    for(auto &pair: countMap) {
        if(pair.second == 1) {
            return pair.first;
        }
    }
}

int singleNumber2Better(vector<int> &nums){
    // TC : O(32*N)
    int ans = 0;
    int n = nums.size();
    for(int bitIndex=0;bitIndex<32;bitIndex++){
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]&(1<<bitIndex)){
                count++;
            }
        }
        if(count%3==1){
            ans = ans | (1<<bitIndex);
        }
    }
    return ans;
}

int singleNumber2SecondApproach(vector<int> &nums){
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i=i+3){
        if(nums[i]!=nums[i-1]){
            return nums[i-1];
        }
    }
    return nums[nums.size()-1];
}


// leetcode 191
// Hamming Weight
 int hammingWeight(int n) {
    int count = 0;
    while(n > 0) {
        count += n & 1;
        n >>= 1;       
    }
    return count;
}

// 461. Hamming Distance
int hammingDistance(int x, int y) {
    int xorValue = x ^ y;
    int count = 0;
    while(xorValue > 0) {
        count += xorValue & 1;
        xorValue >>= 1; 
    }
    return count;
}
// 338. Counting Bits
vector<int> countBits(int n) {
    vector<int> result(n + 1, 0);
    for(int i = 0; i <= n; i++) {
        int count = 0;
        int num = i;
        while(num > 0) {
            count += num & 1; 
            num >>= 1; 
        }
        result[i] = count;
    }        
    return result;
}

bool isPowerOfFour(int n) {
    if(n <= 0) return false;
    if((n&n-1)==0){
        int index = 0;
        while(n>0){
            index++;
            n>>=1;
        }
        return (index-1) % 2 == 0; 
    }else{
        return false;
    }
}

// Leetcode 389. Find the Difference
char findTheDifference(string s, string t) {
    int result = 0;
    for(char c : s) {
        result ^= c;    
    }
    for(char c : t) {
        result ^= c;    
    }
    return char(result);
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

int getSum(int a, int b) {
    return a | b;
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
    cout << "Number of bit flips from 10 to 7: " << numberOfBitFlips(10, 7) << endl;
    vector <int> nums = {1, 2, 3};
    vector<vector<int>> subsets = generateSubsets(nums);
    
    vector<int> singleNum = {4, 1, 2, 1, 2};
    cout<< "Single number in the array: " << singleNumberBruteForce(singleNum) << endl;
    cout << "Single number in the array: " << singleNumber(singleNum) << endl;

    vector<int> singleNum2 = {2,2,2,3,3,3,6,6,6,1,5,5,5};
    cout<<"Single number in the array is : "<<singleNumber2Better(singleNum2)<<endl;
    cout<<"Single number in the array is : "<<singleNumber2SecondApproach(singleNum2)<<endl;

    cout<<"Sum is : "<<getSum(5,6);
}