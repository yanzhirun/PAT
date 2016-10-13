#include<map>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator output;
    for (size_t i = 0; i != 10; ++i)
    {
        v.push_back(i);
    }
    for (output = v.begin(); output != v.end(); ++output)
    {
        cout<<*output<<endl;
    }

    cout<<"============"<<endl;

    vector<int>::iterator it = v.begin()+ 3;
    cout<<*it<<endl;
    advance(it,-1);
    cout<<*it<<endl;
    prev(it,2);
    cout<<*it<<endl;

//    vector<int> ::iterator first = v.begin(), last = v.end();
    return 0;
}
