#include<bits/stdc++.h>
using namespace std;
#define f2(i,x) for((i)=0;(i)<(x);(i)++)
int main(){
    int n,i,j,a[4][4],m,x,y,z;
    cin>>n;
    f2(i,4)f2(j,4)cin>>a[i][j];
    while(n--){
        cin>>m>>x>>y>>z;
        f2(i,4){
            vector<int>v;
            f2(j,4){
                int l=i,h=j;
                if(m>2)h=3-h;
                if(m%2)swap(l,h);
                if(a[l][h]==0)continue;
                int t=a[l][h];
                while(v.size()&&v.back()==t){
                    v.pop_back();
                    t*=2;
                }
                v.push_back(t);
            }
            f2(j,4){
                int l=i,h=j;
                if(m>2)h=3-h;
                int k=h;
                if(m%2)swap(l,h);
                if(m>2)k=3-k;
                if(v.size()<=k)a[l][h]=0;
                else a[l][h]=v[k];
            }
        }
        a[x-1][y-1]=z;
    }
    f2(i,4){
        f2(j,4)cout<<a[i][j]<<' ';
        puts("");
    }
}
