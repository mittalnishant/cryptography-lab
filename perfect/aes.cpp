#include<bits/stdc++.h>
using namespace std;
int sbox[256] =   {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

int RC[11] = {0x00, 0x01, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

vector<string> str;
map<char, int>hash;
map<int, char>mp;
void genHash()
{
        for(int i=0; i<10; i++)
        {
                char ch = '0'+i;
                hash[ch] = i;
                mp[i] = ch;
        }
        hash['a'] = 10, mp[10] = 'a';
        hash['b'] = 11, mp[11] = 'b';
        hash['c'] = 12, mp[12] = 'c';
        hash['d'] = 13, mp[13] = 'd';
        hash['e'] = 14, mp[14] = 'e';
        hash['f'] = 15, mp[15] = 'f';
}


void genDelta(string str, int t, string &temp)
{
        string delta = "";
        for(int i=26; i<=31; i++)
                delta += str[i];
        delta += str[24];
        delta += str[25];
        cout<<delta<<" ";
        for(int i=0; i<8; i+=2)
        {
                int num = (hash[delta[i]])*16+hash[delta[i+1]];
                int val = sbox[num];
                if(i==0)
                        val = val^RC[t];
                char ch = mp[val/16];
                temp += ch;
                ch = mp[val%16];
                temp += ch;
        }
}
void xorr(int r, string temp)
{
        int i=0;
        unsigned int p;
        for(i=0; i<8; i++)
        {
                p = p*16+hash[temp[i]];
        }
        i=0;
        string tp="";
        while(i<32)
        {
                int count = 0;
                unsigned int t = 0;
                while(count<8)
                {
                        t = t*16+hash[str[r-1][i+count]];
                        count++;
                }
                int k = 0;
                p = p^t;
                t = p;
                count--;
                char ch;
                string st = "";
                while(count>=0)
                {
                        ch = mp[t%16];
                        st  = ch+st;
                        t = t/16;
                        count--;
                }
                tp += st;
                i+=8;

        }
        str.push_back(tp);
}
void keyAddition(string &ptext, int n)
{
        for(int i=0; i<32; i+=2)
        {
                int a = (hash[ptext[i]]*16+hash[ptext[i+1]])^(hash[str[n][i]]*16+hash[str[n][i+1]]);
                ptext[i] = mp[a/16];
                ptext[i+1] = mp[a%16];
        }
}

void shift(string &ptxt, int low, int high)
{
        char c1 = ptxt[low];
        char c2 = ptxt[low+1];
        for(int i=low; i<high-2; i+=2)
        {
                ptxt[i] = ptxt[i+2];
                ptxt[i+1] = ptxt[i+3];
        }
        ptxt[high-1] = c1;
        ptxt[high] = c2;
}

void byteSubstitute(string &txt)
{
        for(int i=0; i<32; i+=2)
        {
                int a = hash[txt[i]]*16+hash[txt[i+1]];
                txt[i] = mp[a/16];
                txt[i+1] = mp[a%16];
        }
}

void mixColumn(string &ptxt)
{
        int arr;

}

void cipherText(string ptext)
{
        int i;
        for(i=0; i<=10; i++)
        {
                keyAddition(ptext, i);
                byteSubstitute(ptext);
                shift(ptext,  8, 15);
                shift(ptext, 16, 23);
                shift(ptext, 16, 23);
                shift(ptext, 24, 31);
                shift(ptext, 24, 31);
                shift(ptext, 24, 31);
                mixColumn(ptext);
        }
}


int main()
{
        genHash();
        string key;
        cout << "enter key\n";
        cin >> key;
        str.push_back(key);
        for(int i=1; i<11; i++)
        {
                string temp = "";
                genDelta(str[i-1], i, temp);
                cout<<temp<<" ";
                xorr(i, temp);
                cout<<str[i]<<endl;
        }
        string ptext;
        cin>>ptext;
        cipherText(ptext);

        return 0;
}