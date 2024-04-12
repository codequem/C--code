#include <cstdio>
#include <iostream>

void solve(int i, int j)
{
    int v;
    if (j == 9)
    { // When next cell is in next row:
        j = 0;
        i++;
    }
    if (i == 9 && j == 0)
    {              // When a solution was found:
        display(); // Print the solution, CPU time, branching...
        return;
    }
    nodes++;     // One more node visited
    cnt[i][j]++; // One more visit to this node
    if (m[i][j] > 0)
    { // When this cell is a clue:
        br[i][j]++;
        solve(i, j + 1);
        return;
    }
    for (v = 1; v <= 9; v++)
    { // Free cell. Assign all possible values
        m[i][j] = v;
        if (ok(i, j))
        {               // Test constraints: row, column, 3*3 square
            br[i][j]++; // One more branch
            solve(i, j + 1);
        }
        m[i][j] = 0; // Mark the cell as free
    }
}