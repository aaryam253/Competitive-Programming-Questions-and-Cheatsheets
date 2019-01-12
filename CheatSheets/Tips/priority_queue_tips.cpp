#include <iostream>
#include <queue>

using namespace std;

int main () {
	priority_queue<int> q1; // max heap
	priority_queue<int, std::vector<int>, std::greater<int> > q2; // min heap

}
/*Notes for priority
    priority_queue<int> pq;

Member Functions
    pq.empty()
    pq.size()
    pq.top()
    pq.push(<value>)
    pq.pop()
    pq.swap(<another pq>)
*/
