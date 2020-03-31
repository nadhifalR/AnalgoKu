/*
Nama    = Nadhifal A. Rendusara
NPM     = 140810180048
Kelas   = B
*/
#include <iostream>
#include <float.h>
#include <math.h>
using namespace std;

struct point {
    int x, y;
};

void input(int &n)
{
    cout << "Banyak titik dalam array : ";
    cin >> n;
}

void input(point P[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai x titik ke-" << i + 1 << " : ";
        cin >> P[i].x;
        cout << "Masukkan nilai y titik ke-" << i + 1 << " : ";
        cin >> P[i].y;
    }
}

int compareX(const void *a, const void *b)
{
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b)
{
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->y - p2->y);
}

float dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

float stripClosest(point strip[], int size, float d)
{
    float min = d;

    qsort(strip, size, sizeof(point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closestUtil(point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    point midpoint = P[mid];

    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    float d = min(dl, dr);

    point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midpoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d));
}

float closest(point P[], int n)
{
    qsort(P, n, sizeof(point), compareX);

    return closestUtil(P, n);
}

int main()
{
    int n = 0;
    input(n);

    point P[n];
    input(P, n);

    cout << "\nJarak pasangan titik terdekat adalah " << closest(P, n) << endl;
}
