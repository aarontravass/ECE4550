#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> c = {3,3,5};
    vector<int> t = {7,12,20};
    vector<int> w(0,c.size(),0), r(0,c.size(),0);

    for(int i=0;i<c.size();i++){
        //w[i]+=c[i];
        int current[2] = {0,c[i]};
        while(1){
            int last = current[1];
            for(int j=i;j>=0;j--){
                current[1]+=c[i]*ceil(last/t[i]);
            }
            if(current[0]==current[1]){
                r[i]=current[0];
                break;
            }
            else if(current[1]>t[i]){
                r[i]=-1;
                break;
            }
            current[0]=current[1];

        }
    }
    return 0;
}
