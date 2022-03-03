#include <bits/stdc++.h>

using namespace std;

void printer(vector<int> a){
    for(int itr=0;itr<a.size();itr++){
        cout<<a[itr]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> c = {3,3,5};
    vector<int> t = {7,12,20};
    vector<int> w(c.size(),0), r(c.size(),0);
    w[0] =c[0];
    for(int i=1;i<c.size();i++){
        //w[i]+=c[i];
        int current[2] = {c[i],c[i]};
        while(1){
            current[1] = c[i];
            for(int j=0;j<i;j++){
                current[1]+=(c[i-1]*ceil((float)current[0]/(float)t[j]));
            }
            if(current[0]==current[1]){
                w[i]=current[0];
                break;
            }
            if(current[1]>t[i]){
                break;
            }
            current[0]=current[1];
        }
    }
    printer(w);
    return 0;
}
