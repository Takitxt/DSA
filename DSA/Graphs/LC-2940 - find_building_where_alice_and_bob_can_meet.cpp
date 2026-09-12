class Solution {
public:

vector<int> st;
vector<int> res;

void build_tree(int idx,vector<int>& heights,int l, int r){

    if(l==r){
        st[idx] = heights[l];
        return;
    }

    int mid = (l+r) / 2;

    build_tree(2*idx+1,heights,l,mid);
    build_tree(2*idx+2,heights,mid+1,r);

    st[idx] = max(st[2*idx+1],st[2*idx+2]);

}

int update_tree(int idx,vector<int>& heights,int value,int l,int r, int lr, int rr){

    if(r < lr || l > rr) return -1;

    if(st[idx] <= value) return -1;

    if(l==r) return l;
    int mid = (l+r) / 2;

    int left = update_tree(2*idx+1,heights,value,l,mid,lr,rr);
    if(left!=-1) return left;

    return update_tree(2*idx+2,heights,value,mid+1,r,lr,rr);

}

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();

        st.resize(4*n);
        build_tree(0,heights,0,n-1);

        vector<int> res;

        for(auto q : queries){
            int a = q[0];
            int b = q[1];

            if(a > b) swap(a,b);

            if(a == b) {
                res.push_back(a);
            }else if(heights[a] < heights[b]){
                res.push_back(b);
            }else{
                int ans = update_tree(0,heights,heights[a],0,n-1,b+1,n-1);
                res.push_back(ans);
            };
            
        };


        return res;

    }
};