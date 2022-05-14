#include <bits/stdc++.h>

using namespace std;

void printer(vector<auto> a)
{
    for(int itr=0; itr<a.size(); itr++)
    {
        cout<<a[itr]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> c = {2, 2, 4};
    vector<int> t = {8, 6, 12};
    vector<int> d = {4, 5, 8};
    vector<int> w(c.size(),0);
    vector<bool> valid(c.size(),true);
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
                current[1]+=(c[j]*ceil((float)current[0]/(float)t[j]));
            }
            cout<<current[1]<<" ";
            if(current[0]==current[1])
            {
                w[i]=current[0];
                break;
            }
            if(hasDeadline && current[1]>d[i])
            {
                w[i]=current[1];
                valid[i]=false;
                break;
            }
            if(!hasDeadline && current[1]>t[i])
            {
                w[i]=current[1];
                valid[i]=false;
                break;
            }
            current[0]=current[1];
        }
        cout<<endl;
    }
    printer(w);
    printer(valid);
    return 0;
}
