#include <iostream>
#include <list>


using namespace std;

int checkRemaining (list<int> mylist) {
    
    for (auto it=mylist.begin(); it != prev(mylist.end()); ++it)
    {
        if ((*it + *next(it))%2 == 0)
        {
            return 1;
        }
    }
    return 0;
}

int step (list<int> mylist) {
    int count = mylist.size();
    // Terminations
    if (!checkRemaining(mylist)) {
        return mylist.size();
    }
    if (mylist.empty()) {
        return 0;
    }
    //printf("mysize: %d\n", mylist.size());

    // Else we do not terminate first
    for (auto i=mylist.begin(); i != prev(mylist.end()); ++i)
    {
        if ((*i + *next(i))%2 == 0) // Problem starts from here, bad access
        {
            mylist.erase(next(i));
            i = mylist.erase(i);
            
            //printf("this size %lu\n", mylist.size());
            
            list<int> tempList = mylist;
            /*
            for (auto it = tempList.begin(); it != tempList.end(); it++) {
                printf("%d ", *it);
            }
            printf("\n");
            */
            int temp = step (tempList);
            if (temp < count) count = temp;
        }
    }
    return count;
}



int main(int argc, char const *argv[])
{
    clock_t start, end;

    list<int> mylist;
    int num;
    cin >> num;
    /*
    for (int i = 0; i < num; ++i)
    {
        int number;
        cin >> number;
        mylist.push_back(number);
    }
    */
    
    for (int i = 0; i < num; i++) {
        mylist.push_back(rand()%101 + 1);
    }
    
    start = clock();

    
    cout << step (mylist) << endl;
    end = clock();
    cout << (((double)end - start) / CLOCKS_PER_SEC) << endl;

    return 0;
}
