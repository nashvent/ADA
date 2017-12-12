#include <bits/stdc++.h>
using namespace std;
int* furthest(int *cur,int li[],int r){
    int *next_lily = new int[2];
    next_lily[0]=cur[0]+1;
    int max=li[cur[0]]+r;
    while(li[next_lily[0]]<max){
        next_lily[0]++;
    }
    if(li[next_lily[0]]>max)
        next_lily[0]--;

    next_lily[1]=li[next_lily[0]];
    return next_lily;
}

vector<int> frog_hopping(int li[],int r,int n){
    vector<int>H={0};
    int *cur_lily = new int[2];
    cur_lily[0]=cur_lily[1]=0;

    while(cur_lily[1]<n){
        int *next_lily = furthest(cur_lily,li,r);
        H.push_back(next_lily[1]);
        cur_lily=next_lily;
    }

    return H;
}

void print(vector<int>v){
    for(int a=0;a<v.size();a++)
        cout<<v[a]<<" ";
    cout<<endl;
}

int main() {
    int n;
    int r;
    int size;
    cin>>r>>n;
    cin>>size;
    int H[size];
    for(int a=0;a<size;a++){
        int temp;
        cin>>temp;
        H[a]=temp;
    }
    print(frog_hopping(H,r,n));
    return 0;
}