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
    map<int, string> mapStudent;
    mapStudent[1] = "student_one";
    mapStudent[3] = "student_three";
    mapStudent[5] = "student_five";
    map<int, string>::iterator iter;
    iter = mapStudent.upper_bound(1);
    {
        cout<<"mapStudent.upper(1)";
        cout<<iter->first<<",,,"<<iter->second<<endl;
    }
    iter = mapStudent.lower_bound(1);
    {
        cout<<"mapStudent.lower(1)";
        cout<<iter->second<<endl;
    }
    iter = mapStudent.lower_bound(2);
    {
        cout<<"mapStudent.lower(2)";
        cout<<iter->second<<endl;
    }
    iter = mapStudent.lower_bound(4);
    {
        cout<<"mapStudent.lower(4)";
        cout<<iter->first<<",,,"<<iter->second<<endl;
    }

    cout<<"---------------"<<endl;

    list<int> mylist;
    list<int>::iterator listiter;
    for (int i = 0; i< 10; i++)
        mylist.push_back (i*10);
    //print
    for (listiter = mylist.begin();listiter != mylist.end();++listiter)
    {
        cout<<*listiter<<endl;
    }
    list<int>::iterator iter2 = mylist.end();
    advance(iter2, -5);
    std::cout<<"the sixth element in mylist is: "<< *iter2 <<std::endl;
    //next(iter2, 2);
    //cout<< "the last enement is :" << *std::prev(mylist.end())<<endl;
    std::cout<<"the sixth element prev 2 in mylist is: "<< *iter2 <<std::endl;
    cout << "--=========="<<endl;
    std::for_each (mylist.begin(), std::next(mylist.begin(), 5),[](int x){cout<< " "<<x;});
    cout<< endl;

    return 0;
}
