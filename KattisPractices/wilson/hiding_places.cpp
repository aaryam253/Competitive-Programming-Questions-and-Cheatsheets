#include <iostream>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;


class chessboard {
private:
    unordered_map<string, int> added_weights;
    
    void bfs (char x, char y) {
        // Init
        for (int i = '1'; i <= '8'; i++) {
            for (int d = 'a'; d <= 'h'; d++) {
                string combined;
                combined += d; combined += i;
                added_weights[combined] = 100000;
            }
        }
        string combined; combined += x; combined += y;
        added_weights[combined] = 0; // initialise it to zero
        
        // BFS
        queue<string> q;
        q.push(combined);
        while (!q.empty()) {
            char i = q.front()[1], d = q.front()[0];
            q.pop();
            string combined_original; combined_original += (d); combined_original += i;

            for (int j = -2; j <= 2; j++) {
                for (int k = -2; k <= 2; k++) {
                    if (i + j <= '8' && i + j >= '1' && d + k <= 'h' && d + k >= 'a' && k != 0 && j != 0
                        && !(k == 1 && j == 1) && !(k == -1 && j == -1) && !(k == -1 && j == 1) && !(k == 1 && j == -1)
                        && !(k == 2 && j == 2) && !(k == -2 && j == -2) && !(k == -2 && j == 2) && !(k == 2 && j == -2)
                        )
                    {
                        string combined; combined += (d + k); combined += (i + j);
                        if (added_weights[combined] >= 100000) {
                            if (added_weights[combined] > added_weights[combined_original] + 1) {
                                // relax
                                added_weights[combined] = added_weights[combined_original] + 1;
                            }
                            q.push(combined);
                        }
                        
                    }
                }
            }

        }
        
        /*
        for (int i = '1'; i <= '8'; i++) {
            for (int d = 'a'; d <= 'h'; d++) {
                // examine all neigbours
                string combined_original; combined_original += (d); combined_original += i;

                for (int j = -2; j <= 2; j++) {
                    for (int k = -2; k <= 2; k++) {
                        if (i + j <= '8' && i + j >= '1' && d + k <= 'h' && d + k >= 'a' && k != 0 && j != 0
                            && !(k == 1 && j == 1) && !(k == -1 && j == -1) && !(k == -1 && j == 1) && !(k == 1 && j == -1)
                            && !(k == 2 && j == 2) && !(k == -2 && j == -2) && !(k == -2 && j == 2) && !(k == 2 && j == -2)
                            )
                        {
                            string combined; combined += (d + k); combined += (i + j);
                            if (added_weights[combined] >= 100000) {
                                if (added_weights[combined] > added_weights[combined_original] + 1) {
                                    // relax
                                    added_weights[combined] = added_weights[combined_original] + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        */
    }

public:
    chessboard (char x, char y) {
        bfs(x, y);
    }
    
    void print_all () {
        for (auto it : added_weights) {
            cout << it.first << " " << it.second << endl;
        }
    }
    
    void process_all () {
        map<int, vector<string> > order;
        for (auto it : added_weights) {
            if (it.second < 100000) {
                order[it.second].push_back(it.first);
            }
        }
        cout << order.rbegin()->first << " ";
        
        int n = order.rbegin()->second.size();
        
        // Bubble sort
        for (int c = 0; c < n; c++) {
            for (int d = 0; d < (n-c-1); d++) {
                if (order.rbegin()->second[d][1] < order.rbegin()->second[d+1][1]) {
                    swap(order.rbegin()->second[d], order.rbegin()->second[d+1]);
                }else if (order.rbegin()->second[d][1] == order.rbegin()->second[d+1][1]) {
                    if (order.rbegin()->second[d][0] > order.rbegin()->second[d+1][0]) {
                        swap(order.rbegin()->second[d], order.rbegin()->second[d+1]);
                    }
                }
            }
        }

        
        
        for (auto it : order.rbegin()->second) {
            cout << it << " ";
        }
        cout << endl;
    }
    
};



int main() {
    string input;
    int TC;
    cin >> TC;
    while (TC--) {
        char x, y;
        cin >> input;
        x = input[0];
        y = input[1];
        chessboard mychessboard (x ,y);
        //cout << mychessboard.get_max().first << endl;
        mychessboard.process_all();
    }
    
    //char i = y, d = x;
    
    /*
    for (int j = -2; j <= 2; j++) {
        for (int k = -2; k <= 2; k++) {
            if (i + j <= '8' && i + j >= '1' && d + k <= 'h' && d + k >= 'a' && k != 0 && j != 0
                && !(k == 1 && j == 1) && !(k == -1 && j == -1) && !(k == -1 && j == 1) && !(k == 1 && j == -1)
                && !(k == 2 && j == 2) && !(k == -2 && j == -2) && !(k == -2 && j == 2) && !(k == 2 && j == -2)
                )
            {
                string combined_original; combined_original += (d); combined_original += i;
                string combined; combined += (d + k); combined += (i + j);
                cout << combined << endl;
            }
        }
    }
     */
    

}



