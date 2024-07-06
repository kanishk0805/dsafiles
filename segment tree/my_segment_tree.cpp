#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int>  A,ST;
    int n;
    public:
    SegmentTree(vector<int>& arr){
        n = arr.size();
        A = arr;
        ST.resize(2*n-1);
        buildSegmentTree(0,0,n-1);
    }
    
    void buildSegmentTree(int si,int ss,int se) {
        if (ss == se) {
            ST[si] = A[ss];
            return ;
        }
        int mid= (ss + se)/2;
        buildSegmentTree(si*2+1, ss ,mid);
        buildSegmentTree(si*2+2,mid+1,se);
        ST[si]=ST[si*2+1]+ST[si*2+2];
        return;
    // Return sum of values in
    }
    void update(int si,int ss,int se,int index){
        if(index==ss && index==se){
            ST[si] = A[index];
            return ;
        }
        int mid=(ss+se)/2;
        if(mid<index) update(si*2+1,mid+1,se,index);
        else  update(si*2+2,ss,mid,index);
        ST[si]=ST[si*2+1]+ST[si*2+2];
        return ;
    }
    int givesum(int si,int ss,int se,int l,int r){
        if(ss<l || se>r) return 0;
        
        if(ss>=l && se<=r) return ST[si];
        int mid = (ss + se)/2;
        return givesum(si*2+1,ss,mid,l,r)+givesum(si*2+2,mid+1,se,l,r);
    }
    void printSegmentTree(){
        int t=0;
        for(auto &i: ST){
            cout<<i<<' ';
            if(i==t){
                cout<<endl;
                t<<1;
            }
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
    st.update(0,0,n-1,3);
    st.printSegmentTree();
    cout<<st.givesum(0,0,n-1,0,3)<<endl;

}