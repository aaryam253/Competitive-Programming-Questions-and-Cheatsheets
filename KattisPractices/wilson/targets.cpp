#include <iostream>
#include <math.h>

using namespace std;
 
typedef struct {
	int x, y, r;
	int x1, y1, x2, y2;
	string type;
}shape;

int read_targets (shape shapes[]);
double cartesian_distance (int x, int y, int targetX, int targetY);
int draw_rect (int x_shot, int y_shot, int x1, int y1, int x2, int y2);
void read_shots (shape targets[], int size) ;


int main(int argc, char const *argv[])
{
	shape targets[30];
	int target_num;
	//init_array (matrix);
	target_num = read_targets (targets);

	read_shots (targets, target_num);


	return 0;
}


int read_targets (shape shapes[]) {
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		string type;
		int x1, x2, y1, y2;
		int x, y, r;
		cin >> type;
		if (type == "circle") {
			cin >> x >> y >> r;
			shapes[i].type = type;
			shapes[i].x = x + 1000;
			shapes[i].y = y + 1000;
			shapes[i].r = r;
		}else {
			cin >> x1 >> y1 >> x2 >> y2;
			shapes[i].type = type;
			shapes[i].x1 = x1 + 1000;
			shapes[i].y1 = y1 + 1000;
			shapes[i].x2 = x2 + 1000;
			shapes[i].y2 = y2 + 1000;
		}
	}

	return size;
}

int draw_rect (int x_shot, int y_shot, int x1, int y1, int x2, int y2) {
	int i, d;
	for (i = y1; i <= y2; i++) {
		for (d = x1; d <= x2; d++) {
			if (d == x_shot && i == y_shot) {
				return 1;
			}
		}
	}
	return 0;
}

double cartesian_distance (int x, int y, int targetX, int targetY) {
	double differenceX = targetX - x;
	double differenceY = targetY - y;

	return sqrt (differenceX * differenceX + differenceY * differenceY); 
}


void read_shots (shape targets[], int size) {
	int num_shots;
	cin >> num_shots;
	for (int i = 0; i < num_shots; i++) {
		int x, y, count = 0;
		cin >> x >> y;
		//cout << x+1000 << " " << y+1000 << endl;
		//init_array (matrix);
		for (int d = 0; d < size; d++) {
			if (targets[d].type == "circle") {
				if (cartesian_distance(x+1000, y+1000, targets[d].x, targets[d].y) <= double(targets[d].r)) count++;
			}else {
				if (draw_rect (x+1000 , y+1000, targets[d].x1, targets[d].y1, targets[d].x2, targets[d].y2)) count++;
			}
		}
		cout << count << endl;
	}
}

