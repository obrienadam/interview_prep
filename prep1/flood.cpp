#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

enum{WHITE=0, RED=1, BLUE=2};

int main() {

    int nx = 1000, ny = 1000;

    vector<vector<int>> grid(nx, vector<int>(ny));

    for(int j = 0; j < ny; ++j)
        for(int i = 0; i < nx; ++i) {
            grid[i][j] = rand() % 3;
        }

    set<pair<int, int>> blobbed;
    vector<pair<int, int>> maxBlob;

    for(int j = 0; j < ny; ++j)
        for(int i = 0; i < nx; ++i) {
            if(blobbed.find(make_pair(i, j)) != blobbed.end())
                continue;

            vector<pair<int, int>> blob(1, pair<int, int>(i, j));
            blobbed.insert(make_pair(i, j));

            queue<pair<int, int>> queue;
            set<pair<int, int>> visited;

            queue.push(make_pair(i, j));

            while(!queue.empty()) {
                visited.insert(queue.front());
                queue.pop();

                auto check = [&queue, &visited, &blob, &grid, &blobbed](int i, int j, int COLOR) {
                    cout << COLOR << endl;
                    if(visited.find(make_pair(i, j)) == visited.end() && grid[i][j] == COLOR) {
                        queue.push(make_pair(i, j));
                        blobbed.insert(make_pair(i, j));
                        blob.push_back(make_pair(i, j));
                    }
                };

                if(i > 0)
                    check(i - 1, j, grid[i][j]);

                if(i < nx - 1)
                    check(i + 1, j, grid[i][j]);

                if(j > 0)
                    check(i, j - 1, grid[i][j]);

                if(j < ny - 1)
                    check(i, j + 1, grid[i][j]);
            }

            if(blob.size() > maxBlob.size())
                maxBlob = blob;
        }

    cout << "Max blob size = " << maxBlob.size() << endl;

//    for(auto idx: maxBlob) {
//        cout << "(" << idx.first << "," << idx.second << ")\n";
//    }

    return 0;
}
