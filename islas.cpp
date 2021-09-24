/***
 * 3. Aplicando DFS | BFS a Number of Islands 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/* Función recursiva DFS */
void DFS(vector<vector<char>> &grid, int i, int j, int m, int n)
{
  // Nuestro caso base se ejecuta cuando los índices i y j están fuera de los límites o 
  /* también verificamos que sigamos recorriendo la isla, osea grid[i][j] == 0 */
  if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
    return;

  grid[i][j] = '0';
  /* Recursión hacia arriba */
  DFS(grid, i - 1, j, m, n);
  /* Recursión hacia la derecha */
  DFS(grid, i, j + 1, m, n);
  /* Recursión hacia abajo */
  DFS(grid, i + 1, j, m, n);
  /* Recursión hacia la izquierda */
  DFS(grid, i, j - 1, m, n);
}

int main()
{
  // Ejemplo 1
  vector<vector<char>> grid, grid2;
  grid.push_back({'1','1','1','1','0'});
  grid.push_back({'1','1','0','1','0'});
  grid.push_back({'1','1','0','0','0'});
  grid.push_back({'0','0','0','0','0'});

  int islas = 0;
  int m = grid.size(); //filas
  int n = grid[0].size(); //columnas

  // recorremos la matriz para buscar islas
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if (grid[i][j] == '1')
      {
        islas++;
        DFS(grid, i, j, m, n);
      }
    }
  }
  cout << "Num Islas Ex1: " << islas << endl;

  //Ejemplo 2
  grid2.push_back({'1','1','0','0','0'});
  grid2.push_back({'1','1','0','0','0'});
  grid2.push_back({'0','0','1','0','0'});
  grid2.push_back({'0','0','0','1','1'});

  islas = 0;

  // recorremos la matriz para buscar islas
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if (grid2[i][j] == '1')
      {
        islas++;
        DFS(grid2, i, j, m, n);
      }
    }
  }
  cout << "Num Islas Ex2: " << islas << endl;

  return 0;
}