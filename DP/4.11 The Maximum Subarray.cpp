#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    int size = arr.size();

    std::vector<int> positive(size);
    std::vector<int> negative(size);

    positive[0] = arr[0];
    negative[0] = arr[0];

    for (int i = 1; i != size; ++i) {
        positive[i] = std::max(positive[i - 1], 0) + arr[i];
        negative[i] = std::max(positive[i - 1], negative[i - 1]);
    }

    int maxSubarray = std::max(positive[size - 1], negative[size - 1]);

    int subSequence = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            subSequence += arr[i];
        }
    }

    if (subSequence == 0) {
        subSequence = arr[0];

        for (int i = 1; i < size; ++i) {
            if (subSequence < arr[i]) {
                subSequence = arr[i];
            }
        }
    }

    return std::vector<int> { maxSubarray, subSequence };
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
