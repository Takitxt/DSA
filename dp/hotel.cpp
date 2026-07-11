#include <iostream>
#include <string>
#include <vector>

#include <climits>
using namespace std;

vector<int> st;

vector<int> res;



void build_tree(vector<int> &hotel,int l,int r,int i){
    if(l==r){
        st[i] = hotel[l];
        return;
    }

    int mid = (l+r) /2;

    build_tree(hotel,l,mid,2*i+1);
    build_tree(hotel,mid+1,r,2*i+2);

    st[i] = max(st[2*i+1],st[2*i+2]);

}

void update_tree(int i,int value,vector<int> &hotel,int l,int r){

    if(st[0] < value){
        res.push_back(0);
        return;
    }

    if(l==r){
        st[i] = st[i] - value;
        res.push_back(l+1);
        return;
    }
    int mid = (l + r) / 2;

    if(st[2*i+1] >= value){
        
        update_tree(2*i+1,value,hotel,l,mid);
        
    }else{
        update_tree(2*i+2,value,hotel,mid+1,r);
    }

    st[i] = max(st[2*i+1],st[2*i+2]);



}



int main() {
    int n , m;

    cin>> n;
    cin >> m;

    vector<int> hotel(n);
    
    

    for(int i =0;i<n;i++){
        cin >> hotel[i];
    }
    st.resize(4*n);
    build_tree(hotel,0,n-1,0);

    for(int i =0;i<m;i++){
        long long x;
        cin >> x;
        update_tree(0,x,hotel,0,n-1);
        
    }

    for(int i =0;i<m;i++){
        cout<< res[i] <<endl;
    }


    

}
