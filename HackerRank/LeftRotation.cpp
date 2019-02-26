#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
// solution that uses a separate container. O(N) time, O(N) space
vector<int> rotLeft(vector<int> a, int d) {
    if (d % a.size() == 0 || a.size() == d)
        return a;
    int rot = d % a.size();
    vector<int> ans;
    for (int curr = rot; curr < a.size(); curr++)
    {
        ans.push_back(a[curr]);
    }

    for (int curr = 0; curr < rot - 1; curr++)
    {
        ans.push_back(a[curr]);
    }
    return ans;
}

// vector<int> rotLeft2(vector<int> a, int d)
// {
//     if (d % a.size() == 0 || a.size() == d)
//         return a;
//     int rot = d % a.size(); // number to add to index
//     for (int curr = 0; curr < a.size()/2; curr++)
//     {
//         if (curr + rot >= a.size())
//         {
//             int nextIndex = curr + rot - a.size() - 1; // look at what to replace with and reduce by 1 because starts with 0 index
//         }
//         else int nextIndex = curr + rot;

//         int temp = a[curr];
//         a[curr] = a[nextIndex];
//         a[nextIndex] = temp;

//     }
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
