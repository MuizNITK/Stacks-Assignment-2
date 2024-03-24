#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> num2(2*n);
        for(int i=0;i<n;i++){
            num2[i] = nums[i];
            num2[n+i] = nums[i];
        } 
        int n2 = num2.size();
        stack<int> st;
        vector<int> nge(2*n);
        nge[n2-1] = -1;
        st.push(num2[n2-1]);
        for(int i=n2-2; i>=0;i--){
            while(st.size()>0 && st.top()<=num2[i]){
                st.pop();
            }
            if(st.size()==0) nge[i] = -1;
            else nge[i] = st.top();
            st.push(num2[i]);
        }    
        while(st.size()>0){
            st.pop();
        }
        vector<int> pge(n);
        for(int i=0;i<n;i++){
            pge[i] = nge[i];
        }
        return pge;
    }
int main(){
    int n=5;
    vector<int> nums(n);

    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    nums[4] = 3;
    for(int i=0;i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    vector<int> pge = nextGreaterElements(nums);

    for(int i=0;i<pge.size(); i++){
        cout<<pge[i]<<" ";
    }
 
}