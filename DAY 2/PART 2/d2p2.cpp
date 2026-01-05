#include <bits/stdc++.h>
using namespace std;

bool isInValid(string ss, int part)
{
    unordered_set<string> st;
    int i = 0;
    while (i <= ss.length() - part)
    {
        string a = ss.substr(i, part);
        st.insert(a);
        if (i + part <= ss.length() - part)
        {
            i += part;
        }
        else{
            a = ss.substr(i);
            st.insert(a);
            break;
        }
    }
    if (st.size() > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    string line;
    ifstream inputFile("d2p2.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string s;

    unsigned long long ans = 0;
    string temp;
    while (getline(inputFile, line))
    {
        s = line;
        size_t pos = s.find('-');
        string start = s.substr(0, pos);
        string end = s.substr(pos + 1);

        long long st = stoll(start);
        // cout<<st<<endl;
        long long ed = stoll(end);
        // cout<<ed<<endl;

        for (st; st <= ed; st++)
        {
            string ss = to_string(st);
            int len = ss.length();
            for (int j = 2; j <= len; j++)
            {
                if (isInValid(ss, len / j))
                {
                    cout << st << " added" << endl;
                    ans += st;
                    break;
                }
            }
        }
    }
    inputFile.close();
    cout << ans;
    return 0;
}
