#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Graph
{
    int root_num;
    int route_num;
    int first_root_num;
    vector<vector<int>> matrix;

public:

    Graph() : root_num(0), route_num(0), first_root_num(0) { }

    Graph(int _root_num, int _route_num, int _first_root_num) : root_num(_root_num), route_num(_route_num), first_root_num(_first_root_num) { }

    void add(int begin, int end, int length)
    {
        vector<int> route;
        route.push_back(begin);
        route.push_back(end);
        route.push_back(length);
        matrix.push_back(route);
    }

    void dijkstra()
    {
        int * routes = new int[root_num];
        bool * flag = new bool[root_num];

        fill(routes, routes + root_num, INT_MAX);

        fill(flag, flag + root_num, false);

        routes[first_root_num] = 0;
        int id;

        for (int i = 0; i < route_num - 1; i++)
        {
            int min = INT_MAX;

            for (int j = 0; j < route_num; j++)
            {
                if (min > routes[j] && !flag[j])
                {
                    min = routes[j];
                    id = j;
                }
            }

            flag[id] = true;

            for (int k = 0; k < route_num; k++)
            {
                for (int j = 0; j < matrix.size(); j++)
                    if ((matrix[j])[0] == id && (matrix[j])[1] == k && routes[id] != INT_MAX && !flag[k] &&
                        routes[id] + (
                                      matrix[j])[2] < routes[k])
                        routes[k] = routes[id] + (matrix[j])[2];
            }
        }

        for (int i = 0; i < root_num; i++)
        {
            if (routes[i] != INT_MAX)
                cout << routes[i] << ' ';
        }
        cout << '\n';

        delete [] routes;
        delete [] flag;
    }

    ~Graph() { }
};



int main()
{
    int V, E, N;
    cin >> V >> E >> N;
    Graph graph(V, E, N);

    for (int i = 0; i != E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph.add(a, b, c);
    }

    graph.dijkstra();
    
    return 0;
}