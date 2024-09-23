#include<bits/stdc++.h>
using namespace std;

int timptnghichdao(int a, int m)
{
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m; a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

void khoaGiaiMa(int a[2][2], int b[2][2])
{
    int det = b[1][1] * b[0][0] - b[1][0] * b[0][1];
    det = (det % 26 + 26) % 26;  // ensure det is positive
    int det_inv = timptnghichdao(det, 26);
    a[0][0] = b[1][1] % 26;
    a[0][1] = (-b[0][1] + 26) % 26;
    a[1][0] = (-b[1][0] + 26) % 26;
    a[1][1] = b[0][0] % 26;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = a[i][j] * det_inv;
            a[i][j] = (a[i][j] % 26 + 26) % 26;  // ensure a[i][j] is positive
        }
    }
}

void tichMaTran(int a[][2], int b[][2], int c[][2])
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 26;
        }
    }
}

string maHoaHill(string s, int key[][2])
{
    int p = s.length() / 2;
    string res = "";
    int temp = 0;
    while (p--)
    {
        string ans = "";
        for (int i = 0; i < 2; i++)
        {
            ans += s[temp];
            temp++;
        }
        int a[1][2];
        for (int i = 0; i < 2; i++)
        {
            if (isupper(ans[i]))
            {
                a[0][i] = int(ans[i]) - 65;
            }
            else
            {
                a[0][i] = int(ans[i]) - 97;
            }
        }
        int c[1][2] = {0, 0};
        tichMaTran(a, key, c);
        for (int i = 0; i < 2; i++)
        {
            if (isupper(ans[i]))
            {
                res += char(int(c[0][i]) + 65);
            }
            else
            {
                res += char(int(c[0][i]) + 97);
            }
        }
    }
    return res;
}

string giaimaHill(string s, int key[][2])
{
    int p = s.length() / 2;
    string res = "";
    int temp = 0;
    int key_inv[2][2];
    khoaGiaiMa(key_inv, key);
    while (p--)
    {
        string ans = "";
        for (int i = 0; i < 2; i++)
        {
            ans += s[temp];
            temp++;
        }
        int a[1][2];
        for (int i = 0; i < 2; i++)
        {
            if (isupper(ans[i]))
            {
                a[0][i] = int(ans[i]) - 65;
            }
            else
            {
                a[0][i] = int(ans[i]) - 97;
            }
        }
        int c[1][2] = {0, 0};
        tichMaTran(a, key_inv, c);
        for (int i = 0; i < 2; i++)
        {
            if (isupper(ans[i]))
            {
                res += char(int(c[0][i]) + 65);
            }
            else
            {
                res += char(int(c[0][i]) + 97);
            }
        }
    }
    return res;
}

int main()
{
    int key[2][2] = { {5, 17}, {8, 3} };
    
    cout << "Nhap vao mot xau ky tu: ";
    string banMa;
    getline(cin, banMa);
    
    string banRo = "HARD";
    string banMaDuocMaHoa = maHoaHill(banRo, key);
    
    if (banMa == banMaDuocMaHoa) {
        cout << "Ban nhap dung" << endl;
    } else {
        cout << "Ban nhap sai" << endl;
    }
    
    int key_inv[2][2];
    khoaGiaiMa(key_inv, key);
    
    cout << "Khoa giai ma K(giai ma) la: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << key_inv[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
