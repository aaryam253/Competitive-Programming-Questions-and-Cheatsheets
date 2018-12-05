#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define NOTHING -1
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> p;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

int screenW = 0, screenH = 0;
int totalWindows = 0;

class window {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int x, y, w, h, id;
    vector<int> distToBorder;
    
    window() {};
    
    window(int wx, int wy, int ww, int wh) {
        x = wx; y = wy; w = ww; h = wh;
        distToBorder.assign(4, 0);
        setDimensions();
        id = totalWindows;
        totalWindows++;
    }
    
    window(int wx, int wy, int ww, int wh, int wid) {
        x = wx; y = wy; w = ww; h = wh;
        distToBorder.assign(4, 0);
        setDimensions();
        id = wid;
    }
    
    void shift(int dx, int dy) { x += dx; y += dy; setDimensions();}
    
    int dir(int wdx, int wdy) {
        int wx = wdx/abs(wdx + wdy);
        int wy = wdy/abs(wdx + wdy);
        for (int i = 0; i < 4; i++) {
            if (wx == dx[i] && wy == dy[i]) return i;
        }
        
        return -1;
    }
    
    void setDimensions() {
        distToBorder[0] = screenW - (x + w);
        distToBorder[1] = screenH - (y + h);
        distToBorder[2] = x;
        distToBorder[3] = y;
    }
    
    int dist(window next, int dir) {
        if (dir % 2 == 0) {
            if (this->y >= next.y + next.h || this->y + this->h <= next.y) return NOTHING;
            if (dir == 0) {
                if (this->x + this->w > next.x) return NOTHING;
                else return next.x - (this->x + this->w);
            }
            if (this->x < next.x + next.w) return NOTHING;
            return this->x - (next.x + next.w);
        } else {
            if (this->x >= next.x + next.w || this->x + this->w <= next.x) return NOTHING;
            if (dir == 1) {
                if (this->y + this->h > next.y) return NOTHING;
                else return next.y - (this->y + this->h);
            }
            if (this->y < next.y + next.h) return NOTHING;
            return this->y - (next.y + next.h);
        }
    }
    
    bool cross(window next) {
        //cout << this->x << " " << this->y << " " << this->w << " " << this->h << endl;
        //cout << next.x << " " << next.y << " " << next.w << " " << next.h << endl;
        if ((this->x + this->w) <= next.x) return false;
        if ((next.x + next.w) <= this->x) return false;
        if ((this->y + this->h) <= next.y) return false;
        if ((next.y + next.h) <= this->y) return false;
        return true;
    }
    
    bool inWindow(int wx, int wy) {
        return wx >= x && wx < (x+w) && wy >= y && wy < (y+h);
    }
};

bool intersect(window newW, vector<window> all_windows) {
    for (int i = 0; i < all_windows.size(); i++) {
        if (newW.cross(all_windows[i])) return true;
    }
    
    for (int i = 0; i < 4; i++) {
        if (newW.distToBorder[i] < 0) return true;
    }
    
    return false;
}

int index(int x, int y, vector<window> all_windows) {
    for (int i = 0; i < all_windows.size(); i++) {
        if (all_windows[i].inWindow(x, y)) return i;
    }
    return NOTHING;
}

int moveCommand(vector<window> all_windows, int curr_window, int dx, int dy) {
    window w;
    int maxdis = max(abs(dx), abs(dy));
    int dir = w.dir(dx, dy);
    
    vector<int> dist(all_windows.size(), NOTHING);
    dist[curr_window] = 0;
    vector<bool> visited(all_windows.size(), false);
    
    while (1) {
        int best = -1, bestD = 1000000001;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] != NOTHING && dist[i] < bestD && !visited[i]) {
                bestD = dist[i]; best = i;
            }
        }
        
        if (best == -1 || bestD > maxdis) break;
        
        visited[best] = true;
        
        maxdis = min(maxdis, all_windows[best].distToBorder[dir] + dist[best]);
        
        for (int i = 0; i < all_windows.size(); i++) {
            if (i == best) continue;
            
            if (all_windows[best].dist(all_windows[i], dir) != NOTHING) {
                if (dist[i] == NOTHING || dist[best] + all_windows[best].dist(all_windows[i], dir) < dist[i]) {
                    dist[i] = dist[best] + all_windows[best].dist(all_windows[i], dir);
                }
            }
        }
    }
    
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != NOTHING && dist[i] < maxdis) {
            int actdis = maxdis - dist[i];
            all_windows[i].shift(w.dx[dir]*actdis, w.dy[dir]*actdis);
        }
    }
    
    return maxdis;
}

struct sortbyopen {
    inline bool operator() (const window w1, const window w2) {
        return (w1.id < w2.id);
    }
};

int main() {
    sortbyopen s;
    
    int x, y, w, h, dx, dy, place;
    string cmd;
    cin >> screenW >> screenH;
    
    vector<window> all_windows; int id_count = 1;
    
    while (cin >> cmd) {
        if (cmd == "OPEN") {
            cin >> x >> y >> w >> h;
            window curr(x,y,w,h);
            
            if (!intersect(curr, all_windows)) {
                all_windows.push_back(curr);
            } else cout << "Command " << id_count << ": OPEN - window does not fit" << endl;
        } else if (cmd == "CLOSE") {
            cin >> x >> y;
            place = index(x, y, all_windows);
            
            if (place != NOTHING) all_windows.erase(all_windows.begin() + place);
            else cout << "Command " << id_count << ": CLOSE - no window at given position" << endl;
        } else if (cmd == "RESIZE") {
            cin >> x >> y >> w >> h;
            place = index(x, y, all_windows);
            
            if (place != NOTHING) {
                window prev = all_windows[place];
                window newW(prev.x, prev.y, w, h, prev.id);
                all_windows.erase(all_windows.begin() + place);
                
                if (!intersect(newW, all_windows)) {all_windows.push_back(newW);}
                else {
                    all_windows.push_back(prev);
                    cout << "Command " << id_count << ": RESIZE - window does not fit" << endl;
                }
            } else cout << "Command " << id_count << ": RESIZE - no window at given position" << endl;
        } else {
            cin >> x >> y >> dx >> dy;
            place = index(x, y, all_windows);
            
            if (place != NOTHING) {
                int valid = moveCommand(all_windows, place, dx, dy);
                if (valid < abs(dx + dy)) cout << "Command " << id_count << ": MOVE - moved " << valid << " instead of " << abs(dx + dy) << endl;
            } else cout << "Command " << id_count << ": MOVE - no window at given position" << endl;
        }
        id_count++;
    }
    
    cout << all_windows.size() << " window(s):" << endl;
    sort(all_windows.begin(), all_windows.end(), s);
    
    for (int i = 0; i < all_windows.size(); i++) {
        cout << all_windows[i].x << " " << all_windows[i].y << " " << all_windows[i].w << " " << all_windows[i].h << endl;
    }
    
    return 0;
}
