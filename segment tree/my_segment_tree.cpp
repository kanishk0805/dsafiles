#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int>  ST;
    int n;
    public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        ST.resize(4*n);
        buildSegmentTree(arr,1,0,n-1);
    }
    
    void buildSegmentTree(vector<int> &A,int si,int ss,int se) {
        if (ss == se) {
            ST[si] = A[ss];
            return ;
        }
        int mid= (ss + se)/2;
        buildSegmentTree(A,si*2, ss ,mid);
        buildSegmentTree(A,si*2+1,mid+1,se);
        ST[si]=ST[si*2]+ST[si*2+1];
        return;
    // Return sum of values in
    }
    void update(int si,int ss,int se,int index,int val){
        if(index==ss && index==se){
            ST[si] = val;
            return ;
        }
        int mid=(ss+se)/2;
        if(mid<index) update(si*2,mid+1,se,index,val);
        else  update(si*2+1,ss,mid,index,val);
        ST[si]=ST[si*2]+ST[si*2+1];
        return ;
    }
    void updateval(int indx,int val){
        update(1,0,n-1,indx,val);
    }
    int givesum(int si,int ss,int se,int l,int r){
        if(ss<l || se>r) return 0;
        
        if(ss>=l && se<=r) return ST[si];
        int mid = (ss + se)/2;
        return givesum(si*2,ss,mid,l,r)+givesum(si*2+1,mid+1,se,l,r);
    }
    int query(int l,int r){
        return givesum(1,0,n-1,l,r);
    }
    void printSegmentTree(){
        int t=0;
        auto it=++ST.begin();
        auto end=next(ST.begin(),2*n);
        int i=0;
        while(it!=end){
            cout<<*it<<' ';
            if(i==t){
                cout<<endl;
                t<<1;
            }
            ++i;
            ++it;
        }
        cout<<endl;
    }
};


int main(){
    int n;
    // cin>>n;
    vector<int> v={1,2,3,4,5};
    // for(auto &i : v) cin>>i;
    SegmentTree st(v);
    st.printSegmentTree();
    v[3]=5;
    // st.update(0,0,n-1,3);
    st.printSegmentTree();
    cout<<st.givesum(0,0,n-1,0,3)<<endl;

}