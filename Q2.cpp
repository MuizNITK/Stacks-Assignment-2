#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Next greater node in linked list [Leetcode 1019]
class ListNode{
     public:
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        
        stack<int> st;
        ListNode* temp = head;
        int n=0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        
        ListNode* ne = reverse(head);
        temp = ne;
        vector<int> ng(n);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top()<=temp->val){
                st.pop();
            }
            if(st.size()==0) ng[i] =0;
            else ng[i] = st.top();
            st.push(temp->val);
            temp=temp->next;
        }
        return ng;
    }

    int main(){
        ListNode* a = new ListNode(2);
        ListNode* b = new ListNode(7);
        ListNode* c = new ListNode(4);
        ListNode* d = new ListNode(3);
        ListNode* e = new ListNode(5);
        a->next = b;
        b->next = c;
        c->next = d;
        d->next = e;
        ListNode* temp = a;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
        vector<int> NextGreaterNode = nextLargerNodes(a);
        for(int i=0;i<NextGreaterNode.size();i++){
            cout<<NextGreaterNode[i]<<" ";
        }
    }        