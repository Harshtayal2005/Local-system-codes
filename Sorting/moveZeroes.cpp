#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int k=i+1; k<nums.size(); k++){
            if(nums[k]!=0 && nums[i]==0){
                swap(nums[i], nums[k]);
                i++;
            } else if(nums[k]==0 && nums[i]==0){
                continue;
            } else if(nums[i]!=0 && nums[k]==0){
                i++;
            } else{
                i++;
                continue;
            }
        }
    }
int main(){
    vector<int> nums = {0,2,0,3,4,0,4,4};
    moveZeroes(nums);
    for(int ele:nums){
        cout<<ele<<" ";
    } cout<<endl;
    return 0;
}