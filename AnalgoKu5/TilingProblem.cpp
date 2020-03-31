/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
using namespace std;

int ** tromino_tile;

int power_2(int k)
{
	int result = 1;
	for (int i = 0; i < k; i++) {
		result = result * 2;
	}
	return result;
}

void allocate(int n, int x, int y)
{
	tromino_tile = new int * [n];
	for (int i = 0; i < n; i++) {
		tromino_tile[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tromino_tile[i][j] = -1;
		}
	}
	tromino_tile[x][y] = 100;
}

void print_tromino(int n)
{
	for (int i = 0; i < n; i++) {
		cout<<"\n";
		for (int j = 0; j < n; j++) {
			if (tromino_tile[i][j] == 100)
				cout<<"\t"<<"X";
			else
				cout<<"\t"<<tromino_tile[i][j];
		}
		cout<<"\n";
	}
}

void free_memory(int n)
{
	for (int i = 0; i < n; ++i) {
		delete [] tromino_tile[i];
	}
	delete [] tromino_tile;
}

void trominoTile(int n, int hole_row, int hole_col, int x, int y)
{
	int i;
	int half = n/2;

	if (n == 2)	{
		if (hole_row < x + half && hole_col < y + half) {
            i = rand() % 10;
            tromino_tile[x + half][y + half - 1] = i;
            tromino_tile[x + half][y + half] = i;
            tromino_tile[x + half - 1][y + half] = i;
        }

        else if (hole_row < x + half && hole_col >= y + half) {
            i = rand() % 10;
            tromino_tile[x + half][y + half - 1] = i;
            tromino_tile[x + half][y + half] = i;
            tromino_tile[x + half - 1][y + half - 1] = i;
        }

        else if (hole_row >= x + half && hole_col < y + half) {
            i = rand() % 10;
            tromino_tile[x + half - 1][y + half] = i;
            tromino_tile[x + half][y + half] = i;
            tromino_tile[x + half - 1][y + half - 1] = i;
        }

        else {
            i = rand() % 10;
            tromino_tile[x + half - 1][y + half] = i;
            tromino_tile[x + half][y + half - 1] = i;
            tromino_tile[x + half - 1][y + half - 1] = i;
		}
	} else {
        if (hole_row < x + half && hole_col < y + half) {
            i = rand() % 10;
            tromino_tile[x + half][y + half - 1] = i;
            tromino_tile[x + half][y + half] = i;
            tromino_tile[x + half - 1][y + half] = i;

			trominoTile(half, hole_row, hole_col, x, y);
			trominoTile(half, x + half, y + half - 1, x + half, y);
			trominoTile(half, x + half, y + half, x + half, y + half);
			trominoTile(half, x + half - 1, y + half, x, y + half);
        } else if (hole_row < x + half && hole_col >= y + half) {
            i = rand() % 10;
            tromino_tile[x + half][y + half - 1] = i;
            tromino_tile[x + half][y + half] = i;
            tromino_tile[x + half - 1][y + half - 1] = i;

            trominoTile(half, hole_row, hole_col, x, y + half);
            trominoTile(half, x + half, y + half - 1, x + half, y);
            trominoTile(half, x + half, y + half, x + half, y + half);
            trominoTile(half, x + half - 1, y + half - 1, x, y);
		} else if(hole_row >= x + half && hole_col < y + half) {
            i = rand() % 10;
            tromino_tile[x + half - 1][y + half] = i;
            tromino_tile[x + half][y + half] = i;
            tromino_tile[x + half - 1][y + half - 1] = i;

            trominoTile(half, hole_row, hole_col, x + half, y);
            trominoTile(half, x + half - 1, y + half, x, y + half);
            trominoTile(half, x + half, y + half, x + half, y + half);
            trominoTile(half, x + half - 1, y + half - 1, x, y);
		} else {
            i = rand() % 10;
            tromino_tile[x + half - 1][y + half] = i;
            tromino_tile[x + half][y + half - 1] = i;
            tromino_tile[x + half - 1][y + half - 1] = i;

            trominoTile(half, hole_row, hole_col, x + half, y + half);
            trominoTile(half, x + half - 1, y + half, x, y + half);
            trominoTile(half, x + half, y + half - 1, x + half, y);
            trominoTile(half, x + half - 1, y + half - 1, x, y);
		}
	}
}

int main()
{
	int k = 2, hole_row = 2, hole_col = 2;
	srand(time(NULL));
	if (k < 1)
		cout<<"\n<nilai k> harus positive\n";
	else {
		if(hole_row == 0 || hole_col == 0)
			cout<<"\nThe <jumlah baris> dan <jumlah kolom> harus positive dan integer\n";
		else {
			int n = power_2(k);

			if (n >= hole_row && n >= hole_col) {
			hole_row--;
			hole_col--;

			allocate(n, hole_row, hole_col);

			trominoTile(n, hole_row, hole_col, 0, 0);
			print_tromino(n);
			free_memory(n);
			}
			else
				cout<<"\nBaris dan Kolom tidak boleh lebih dari 2^k\n";
		}
	}
}
