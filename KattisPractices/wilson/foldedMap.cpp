#include <iostream>
#define MAX 1000

using namespace std;


void readMap (int* Ar, int* Ac, int* Tr, int* Tc, char map[][MAX]);
void printMap (int Ar, int Ac, char map[][MAX]);
int floodFill (int Ar, int Ac, int Tr, int Tc, char map[][MAX], int startx, int starty, char flood[][MAX]);
int propogateCheck (int Ar, int Ac, int Tr, int Tc, int startx, int starty, char map[][MAX]);


int main(int argc, char const *argv[])
{
	char map[MAX][MAX];
	int Ar, Ac, Tr, Tc;
	readMap (&Ar, &Ac, &Tr, &Tc, map);
	// printMap(Ar, Ac, map);
	char flood[MAX][MAX] = {{0}};
	floodFill(Ar, Ac, Tr, Tc, map, 2, 2, flood);
	printMap(Ar, Ac, flood);

	return 0;
}


void readMap (int* Ar, int* Ac, int* Tr, int* Tc, char map[][MAX]) {
	scanf("%d %d %d %d", Ar, Ac, Tr, Tc);
	for (int i = 0; i < *Ar; i++) {
		cin >> map[i];
	}
}

void printMap (int Ar, int Ac, char map[][MAX]) {
	for (int i = 0; i < Ar; i++) {
		cout << map[i] << endl;
	}
}

int foldedMap (int Ar, int Ac, int Tr, int Tc, char map[][MAX]) {
	int best = Ar*Ac;
	for (int i = 0; i < Ar; i++) {
		for (int d = 0; d < Ac; d++) {
			if (map[i][d] == 'X') {
				char flood[MAX][MAX] = {{0}};
				int numTiles = floodFill(Ar, Ac, Tr, Tc, map, d, i, flood);
				if (numTiles < best) {
					best = numTiles;
				}
			}
		}
	}
	return best;
}


int floodFill (int Ar, int Ac, int Tr, int Tc, char map[][MAX], int startx, int starty, char flood[][MAX]) {
	int i, d, count = 0;
	// Flood fill square by square/ tile by tile as we count how many squares are there
	// Always start the process from bottom right and build the tiles upwards 
	if (propogateCheck(Ar, Ac, Tr, Tc, startx, starty, map)) {
		for (i = starty; i > starty - Tr && i >= 0; i--) {
			for (d = startx; d > startx - Tc && d >= 0; d--) {
				flood[i][d] = 'X'; // Why does this not place the X in flood? 
			}
		}
	}
	


	return count;
}

// Create new function to propogate forward and test to see if it can contain any X before advancing - to aid with flood fill 

int propogateCheck (int Ar, int Ac, int Tr, int Tc, int startx, int starty, char map[][MAX]) {
	int i, d;
	for (i = starty; i > starty - Tr && i >= 0; i--) {
		for (d = startx; d > startx - Tc && d >= 0; d--) {
			if (map[i][d] == 'X') return 1;
		}
	}
	return 0;
}