#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    ifstream inputFile("d1p2.txt");

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
        ans += temp/100;
        temp%=100;
        if (s[0] == 'L')
        {
            if(start == 0){
                ans--;
            }
            start = (start - temp);
            cout<< "L " << start << "  ";
        }
        else
        {
            start = (start + temp);
            cout<< "R " << start << "  ";
        }
        if(start > 99){
            ans ++;
            cout<<"increased99 ";
        }
        if(start <= 0){
            start += 100;
            ans ++;
            cout<<"increased0 ";
        }
        start %= 100;
        cout<< start << " " << ans << endl;
        
    }

    inputFile.close();
    cout << ans;
    return 0;
}
