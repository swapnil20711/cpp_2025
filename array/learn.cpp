#include<iostream>
#include <bits/stdc++.h>
using namespace std;    
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
        for (int j = i+1; j < nums.size(); j++)
        {
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
    }
    return {};
}
vector<int> twoSumOptimised(vector<int>& nums, int target) {
    map<int, int> numMap;
    for(int i=0;i<nums.size();i++){
        int more = target - nums[i];
        if(numMap.find(more)!= numMap.end()){
            return {numMap[more], i};
        }
        numMap[nums[i]] = i;
    }
    return {};

}
int main(){
    vector<int> input = {2, 7, 11, 15};
    vector<int> ans = twoSumOptimised(input, 9);
}