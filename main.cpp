#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

//Sand 1
//Grass 2
//Water 3
//Dirt 4
//Snow 5

vector< vector<int> > cell(int x, int y, vector< vector<int> > map) {
  if (x != 0) {
    if (map[x-1][y] == 1) {
      map[x][y] == rand() % 3 + 1;
    } else if (map[x-1][y] == 2) {
      int i = rand() % 3 + 1;
      if (i == 1) {
        map[x][y] = 1;
      } else if (i == 2) {
        map[x][y] = 4;
      } else {
        map[x][y] = 2;
      }
    }
  }
  return map;
}

int main(int argc, char *argv[]) {
  srand(time(0));
  vector< vector<int> > map;
  map = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0},{0, 0, 0, 0, 0},{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}};
  map[0][0] = rand() % 5;
  cout << map[0][0] << endl;
  map = cell(1,0,map);
  //Sand -> Sand || Sand -> Grass || Sand -> Water
  //Grass -> Sand || Grass -> Dirt || Grass -> Grass
  //Water -> Sand || Water -> Water
  //Dirt -> Snow || Dirt -> Grass || Dirt -> Dirt
  //Snow -> Dirt || Snow -> Grass || Snow -> Snow
  for (int i = 0; i<map.size(); i++) {
    for (int i1 = 0; i1<map[0].size(); i1++) {
      cout << map[i][i1] << " ";
    }
    cout << endl;
  }
}
