# Applications of data structure 

1. Vector/ Arr
- Use when we need fast random access 
- Use when we need the index as reference 
- Use when we are only appending to the end of the 'list'



2. Linked list 
- Use when we need a proper sequence/ flow of data 
- Use when we need to insert elements into the center of the collection


3. Stack 
- Use when we need to gather instructions in sequence (FILO), handle whatever tasks are top in the stack
	fun fact, this is how instructions are stacked in a computer too



4. Queue 
- Use when we wish to constantly add elements into the collection while also constantly accessing it
	eg. Queueing up nodes to inspect in a graph algo 



5. Deque 
- Use when we wish to stack/ pop elements like a stack but also pop/ push elements to the front


6. Priority Queue 
- Use when we wish to obtain the largest or smallest item in Olog(n)
	largest/ smallest item will always float up

7. Hash tables (unordered_map/ set)
- Use when we wish to retrieve/ search for data in O(1)
- Use when we have many updates to the data set. 
- Use when we need to identify duplicates 

Note: We usually use double hashing or seperate chaining 


8. BSTs (ordered map/ set)
- Use when we need to have a balance between retrieval of random data and finding order
- Keys are harder to hash eg. tuples/ pairs 
- Need to use upper bound/ lower bound 


9. Graph DS
BFS/ DFS: 
- Reachability test
- Printing traversal path
- Identifying, counting and labelling connected components 
- Topological sort 



10. Shortest Path
- For Trees use DFS and BFS would be faster, the rest would be correct too 
- For small general graphs with cycles - use dijkstra and modified dijkstra 
- To solve many SP ending at vertex 2 - use Djikstra and modified Djikstra 
- Graphs with same edge weights - cannot use DFS (as its not a tree), BFS would be fastest 
- Negative cycle detection - use Bellman ford 
- Cycle detection - use BFS, check if visit the same source again 
Theory: 
Bellman ford runs at v - 1 passes to account for all lengths to reach each dest

All pairs shortest: 
- Use when we need to find multiple distances from multiple sources to multiple destinations 
- When source and destination is not explicitly specified

Virtual node: 
- Use when we need to pre-compute existing weight from current node (eg. arriving at any node has an additional weight imposed)

Longest path (can be weighted, can have negative weights) (Only DAG): 
- Use topological sort and then one-pass bellman ford (see code_snippets3)
- If have to, convert the graph to DAG first using dag converter
- Note: Cannot modify dijkstra to use max instead of min as it will result in infinite loop with positive weight cycles (see common mistakes)

Shortest path under k junctions (nodes)
- Top down bellman ford
- Convert graph to DAG and then use one-pass bellman ford under k passes

