#include <iostream>

using namespace std;

int GetRoot(int * cursors, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (cursors[i] == -1)
            return i;
    }
    return -1;
}

void DirectOrderWalk(int * cursors, int n, int parent = -1)
{
    if (parent == -1)
        parent = GetRoot(cursors, n);
    cout << parent << " ";
    for (int i = 0; i < n; ++i)
    {
        if (cursors[i] == parent)
            DirectOrderWalk(cursors, n, i);
    }
}

void ReverseOrderWalk(int * cursors, int n, int parent = -1)
{
    if (parent == -1)
        parent = GetRoot(cursors, n);
    for (int i = 0; i < n; ++i)
    {
        if (cursors[i] == parent)
            ReverseOrderWalk(cursors, n, i);
    }
    cout << parent << " ";
}

void SymmetricOrderWalk(int * cursors, int n, int parent = -1)
{
    if (parent == -1)
        parent = GetRoot(cursors, n);
    int i = 0;
    for (i; i < n; ++i)
    {
        if (cursors[i] == parent)
        {
            SymmetricOrderWalk(cursors, n, i++);
            break;
        }
    }
    cout << parent << " ";
    for (i; i < n; ++i)
    {
        if (cursors[i] == parent)
            SymmetricOrderWalk(cursors, n, i);
    }
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;

    int * cursors = new int[n];
    cout << "Cursors: " << endl;

    for (int i = 0; i < n; ++i)
        cin >> cursors[i];
    DirectOrderWalk(cursors, n);
    cout << endl;
    ReverseOrderWalk(cursors, n);
    cout << endl;
    SymmetricOrderWalk(cursors, n);
    cout << endl;
    return 0;
}