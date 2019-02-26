#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

unordered_set<string> str;
string subExists = "YES";
string subDoesnt = "NO";
for (int curr = 0; curr < s1.size(); curr++)
{
    str.insert(s1[curr]);
}

for (int curr = 0; curr < s2.size(); curr++)
{
    auto itr = str.find(s2[curr]);
    if (itr != NULL)
        return subExists;
}
return subDoesnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
