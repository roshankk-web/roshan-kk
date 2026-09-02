#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int find(vector<int> &ldr,int id){
    if(ldr[id]==id){
        return id;
    }
    ldr[id]=find(ldr,ldr[id]);
    return ldr[id];
}
void join(vector<int> &ldr,int lt,int rt){
    int ldrlt=find(ldr,lt);
    int ldrrt=find(ldr,rt);
    ldr[ldrrt]=ldrlt;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>ldr(n+1);
    for(int i=1;i<=n;i++){
        ldr[i]=i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        join(ldr,x,y);
    }
    set<int>a;
    for(int i=1;i<=n;i++){
        a.insert(find(ldr,i));
    }
    cout<<a.size();

}
