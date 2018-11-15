#include <bits/stdc++.h>
using namespace std;

int main() {
  deque<int> d;
  d.push_back(3);
  d.push_back(4);
  d.push_back(5); // at this point we have 3,4,5
  d.push_front(2);
  d.push_front(1); // at this point we have 1,2,3,4,5
  return 0;
}
/*Notes for deque
    deque<int> d;

Iterators
    d.begin()
    d.end()
Capacity
    d.size()
    d.empty()
Element Access
    d[<index>]
    d.at(<index>)
    d.front()
    d.back()
Modifiers
    d.push_front(<value>)
    d.push_back(<value>)
    d.pop_front()
    d.pop_back()
    d.insert(<iterator position>)
    d.erase(<iterator position>)
    d.swap(<deque>)
    d.clear()
*/
