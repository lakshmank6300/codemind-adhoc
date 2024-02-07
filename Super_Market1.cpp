#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    int c,i;
    for(i=0;i<n;i++){
        cin>>c;
        arr.push_back(c);
    }
    int tar;
    cin>>tar;
    map<int,int>mp;
    int mx=0;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]>mx)
            mx=mp[arr[i]];
    }
    // for(auto j=mp.begin();j!=mp.end();j++){
    //     cout<<j->first<<" "<<j->second<<endl;
    // }
    // cout<<mx;
    vector<vector<int>>ans(mx+1);
    for(auto i=mp.begin();i!=mp.end();i++){
        ans[i->second].push_back(i->first);
    }
    for(int i=0;i<mx+1;i++){
        sort(ans[i].begin(),ans[i].end());
    }
    vector<int>res;
    for(int i=mx;i>=0 &&  tar!=0 ;i--){
        for(int j=ans[i].size()-1;j>=0 && tar!=0 ;j--){
            res.push_back(ans[i][j]);
            tar--;
        }
    }
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}