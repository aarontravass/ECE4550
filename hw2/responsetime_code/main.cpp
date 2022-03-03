#include <bits/stdc++.h>

using namespace std;

void printer(vector<int> a)
{
    for(int itr=0; itr<a.size(); itr++)
    {
        cout<<a[itr]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> c = {20, 10, 5};
    vector<int> t = {50, 40, 20};
    vector<int> d = {40, 30, 15};
    vector<int> w(c.size(),0);
    bool hasDeadline = d.size();
    w[0] =c[0];
    for(int i=1; i<c.size(); i++)
    {
        //w[i]+=c[i];
        int current[2] = {c[i],c[i]};
        while(1)
        {
            current[1] = c[i];
            for(int j=0; j<i; j++)
            {
                current[1]+=(c[i]*ceil((float)current[0]/(float)t[j]));
            }
            if(current[0]==current[1])
            {
                w[i]=current[0];
                break;
            }
            if(current[1]>d[i] && hasDeadline)
            {
                w[i] = -1;
                break;
            }
            if(current[1]>t[i] && !hasDeadline){
                w[i] = -1;
                break;
            }
            current[0]=current[1];
        }
    }
    printer(w);
    return 0;
}
