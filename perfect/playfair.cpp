#include<bits/stdc++.h>
using namespace std;

char pat[5][5] = {{'L', 'G', 'D', 'B', 'A'},
                          {'Q', 'M', 'H', 'E', 'C'},
                          {'U', 'R', 'N', 'I', 'F'},
                          {'X', 'V', 'S', 'O', 'K'},
                          {'Z', 'Y', 'W', 'T', 'P'}};

void findChar(char ch, int &x, int &y)
{
        if(ch == 'I' || ch == 'J')
        {
                x = 2, y = 3;
                return;
        }
        else
        {
                int i, j;
                for(i=0; i<5; i++)
                {
                        for(j=0; j<5; j++)
                        {
                                if(pat[i][j] == ch)
                                {
                                        x = i, y = j;
                                        return;
                                }
                        }
                }
        }
}

void putChar(int x1, int x2, int y1,int y2)
{
        if(x1==x2)
        {
                cout<<pat[x1][(y1+1)%5]<<pat[x1][(y2+1)%5];
                return;
        }
        if(y1==y2)
        {
                cout<<pat[(x1+1)%5][y1]<<pat[(x2+1)%5][y2];
                return;
        }

        cout<<pat[x2][y1]<<pat[x1][y2];
}

void showEnc(string str)
{
    int len = str.size();
    int i=0, x1, x2, y1,  y2;
    while(i<len)
    {
        findChar(str[i], x1, y1);
        i++;
        if(i<len && str[i]!=str[i-1])
        {
            findChar(str[i], x2, y2);
            i++;
        }
        else
            findChar('P', x2, y2);
        putChar(x1, x2, y1, y2);
    }
}
int main()
{
    string str;
    cout << "Enter Plaintext:\n";
    cin >> str;
    cout << "CipherText is:\n";
    showEnc(str);
    cout << endl;
    return 0;
}