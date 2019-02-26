#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    auto inbounds = [&arr](int i, int j) {
        if(i + 1 > arr.size() - 1)
            return false;

        if(i + 2 > arr.size() - 1)
            return false;

        if(j + 1 > arr[i].size() - 1)
            return false;

        if(j + 2 > arr[i].size() - 1)
            return false;

        return true;
    };

    int maxSum = numeric_limits<int>::min();
    for(int i = 0; i < arr.size(); ++i)
        for(int j = 0; j < arr[i].size(); ++j) {
            if(!inbounds(i, j))
                continue;

            int sum = 0;

            sum += arr[i][j];
            sum += arr[i + 1][j];
            sum += arr[i + 2][j];

            sum += arr[i + 1][j + 1];

            sum += arr[i][j + 2];
            sum += arr[i + 1][j + 2];
            sum += arr[i + 2][j + 2];

            cout << sum << endl;
            maxSum = max(sum, maxSum);
        }

        return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
