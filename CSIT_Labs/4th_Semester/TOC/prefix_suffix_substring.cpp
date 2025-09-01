/* WAP to find prefix, suffix and substring from given string */

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100], prefix[100], suffix[100], substring[100];
    int i, j, k, l, m, n, o, p;

    cout << "Enter a string: ";
    cin >> str;
    l = strlen(str);

    cout << "Prefix: ";
    for (i = 0; i < l; i++)
    {
        for (j = 0; j <= i; j++)
        {
            prefix[j] = str[j];
        }
        prefix[j] = '\0';
        cout << prefix << " ";
    }
    cout << endl;

    cout << "Suffix: ";
    for (k = 0; k < l; k++)
    {
        for (m = k; m < l; m++)
        {
            suffix[m - k] = str[m];
        }
        suffix[m - k] = '\0';
        cout << suffix << " ";
    }
    cout << endl;

    cout << "Substring: ";
    string unique_substrings[5050]; // Maximum possible substrings for 100 chars: n(n+1)/2
    int unique_count = 0;
    for (n = 0; n < l; n++)
    {
        for (o = n; o < l; o++)
        {
            string sub = string(str).substr(n, o - n + 1); // (start, length) of substring
            bool found = false;
            for (int idx = 0; idx < unique_count; idx++) {
                if (unique_substrings[idx] == sub) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                unique_substrings[unique_count++] = sub;
                cout << sub << " ";
            }
        }
    }
    cout << endl;

    return 0;
}