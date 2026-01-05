#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    ifstream inputFile("d1p1.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string s;
    int start = 50;
    string op;
    int ans = 0;
    int temp;
    while (getline(inputFile, line))
    {
        s = line;
        op = s.substr(1);
        temp = stoi(op);
        // temp = temp % 100;
        if (s[0] == 'L')
        {
            start = (start - temp);
        }
        else
        {
            start = (start + temp);
        }
        start %= 100;
        if (start == 0)
        {
            ans++;
        }
    }

    inputFile.close();
    cout << ans;
    return 0;
}
