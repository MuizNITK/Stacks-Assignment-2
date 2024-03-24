#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        ans[n-1] = -1;
        stack<int> st;
        st.push(prices[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.top()>prices[i]){
                st.pop();
            }
            if(st.size()==0) ans[i]=-1;
            else ans[i] = st.top();
            st.push(prices[i]); 
        }

        for(int i=0;i<n;i++){
            if(ans[i]==-1) continue;
            else prices[i] = prices[i] - ans[i];
        }
        ans.clear();
        return prices;
    }

int main(){
    vector<int> prices(5);
    prices[0] = 8;
    prices[1] = 4;
    prices[2] = 6;
    prices[3] = 2;
    prices[4] = 3;
    for(int i=0; i<prices.size(); i++){
        cout<<prices[i]<<" ";
    }
    cout<<endl;
    vector<int> finalprices = finalPrices(prices);
    for(int i=0; i<finalprices.size(); i++){
        cout<<finalprices[i]<<" ";
    }

}