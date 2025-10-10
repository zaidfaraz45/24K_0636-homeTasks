#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &grid, int x, int y, int n, vector<vector<int>> &visited)
{
    return (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1 && visited[x][y] == 0);
}

void findPaths(vector<vector<int>> &grid, int n, int x, int y, int destX, int destY, vector<vector<int>> &visited, vector<vector<int>> &path, vector<vector<vector<int>>> &allPaths)
{
    if (x == destX && y == destY)
    {
        path.push_back({x, y});
        vector<vector<int>> sol(n, vector<int>(n, 0));
        for (int i = 0; i < path.size(); i++)
        {
            int x = path[i][0];
            int y = path[i][1];
            sol[x][y] = 1;
        }

        allPaths.push_back(sol);
        path.pop_back();

        return;
    }

    visited[x][y] = 1;
    path.push_back({x, y});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int dir = 0; dir < 4; dir++)
    {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if (isSafe(grid, newX, newY, n, visited))
        {
            findPaths(grid, n, newX, newY, destX, destY, visited, path, allPaths);
        }
    }

    path.pop_back();
    visited[x][y] = 0;
}

void printMatrixPaths(string name, vector<vector<vector<int>>> &paths)
{
    cout << "\n" << name << " Paths (" << paths.size() << "):\n";
    int count = 1;
    for (int p = 0; p < paths.size(); p++)
    {
        cout << "Path " << count++ << ":\n";
        for (int i = 0; i < paths[p].size(); i++)
        {
            for (int j = 0; j < paths[p][i].size(); j++)
            {
                cout << paths[p][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void findIntersections(vector<vector<vector<int>>> &rabbitPaths, vector<vector<vector<int>>> &catPaths)
{
    cout << "\nIntersection Points:\n";
    bool found = false;
    int n = rabbitPaths[0].size();

    vector<vector<int>> intersection(n, vector<int>(n, 0));

    for (int row = 0; row < rabbitPaths.size(); row++)
    {
        for (int col = 0; col < catPaths.size(); col++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (rabbitPaths[row][i][j] == 1 && catPaths[col][i][j] == 1)
                    {
                        intersection[i][j] = 1;
                        found = true;
                    }
                }
            }
        }
    }


    if (found)
    {
        cout << "Intersection Matrix:\n";
        for (int i = 0; i < intersection.size(); i++)
        {
            for (int j = 0; j < intersection[i].size(); j++)
            {
                cout << intersection[i][j] << " ";
            }
            cout << endl;
        }

    }

    else
    {
        cout << "No intersection points found.\n";
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> grid = 
    {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<int>> path;
    vector<vector<vector<int>>> rabbitPaths, catPaths;

    findPaths(grid, n, 0, 0, 2, 2, visited, path, rabbitPaths);

    findPaths(grid, n, 4, 4, 2, 2, visited, path, catPaths);

    printMatrixPaths("Rabbit", rabbitPaths);
    printMatrixPaths("Cat", catPaths);

    findIntersections(rabbitPaths, catPaths);

    return 0;
}
