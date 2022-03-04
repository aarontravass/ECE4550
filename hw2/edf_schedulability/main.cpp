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

void set_printer(set<int> s){
    for(auto itr=s.begin();itr!=s.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


int main()
{
    vector<int> c = {2, 2, 3};
    vector<int> t = {6, 8, 9};
    vector<int> d = {4, 5, 7};
    set<int> l;
    int h = lcm(t[0],t[1]);
    for(int i=2;i<t.size();i++){
        h=lcm(h,t[i]);
    }
    for(int i=0;i<c.size();i++){
        int D = d[i];
        while(D<=h){
            l.insert(D);
            D+=t[i];
        }
    }
    vector<int> w(l.size(),0);
    int k=0;
    for(auto itr=l.begin();itr!=l.end();itr++){
        for(int i=0;i<c.size();i++){
            w[k]+=c[i]*(floor((float)(*itr - d[i])/(float)t[i])+1);
        }
        k++;
    }
    printer(w);
    set_printer(l);


    return 0;
}
