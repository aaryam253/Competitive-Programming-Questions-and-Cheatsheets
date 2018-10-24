#include <iostream>
#include <list>

using namespace std;


int main(int argc, char const *argv[])
{
    list<int> mylist;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        int number;
        cin >> number;
        mylist.push_back(number);
    }
            
    int flag = 1;
    while (flag) {
        flag = 0;
        if (mylist.empty()) break;
        for (auto i = mylist.begin(); i != prev(mylist.end()) && i != mylist.end(); )
        {
            if ((*i + *next(i))% 2 == 0) {
                // Key to removal of elements
                mylist.erase(next(i));
                i = mylist.erase(i);
                flag = 1;
            }else {
                i++;
            }
        }
    }
    
    cout << mylist.size() << endl;

    return 0;
}

