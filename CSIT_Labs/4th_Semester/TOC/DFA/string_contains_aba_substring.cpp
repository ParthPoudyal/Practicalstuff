// cpp program for DFA for the language of string over {a,b} such that each string contain aba as substring

#include <iostream>
#include <string>
using namespace std;

enum States {
    Initial,   // q0
    Terminal1, // q1
    Terminal2, // q2
    Final      // q3
};

int main()
{
    string str;
    States state = Initial;

    cout << "Enter the string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
        {
            cout << "String not accepted.\nPlease enter a string over {a,b}" << endl;
            return 0;
        }

        if (state == Initial && str[i] == 'a')
            state = Terminal1;
        else if (state == Initial && str[i] == 'b')
            state = Initial;
        else if (state == Terminal1 && str[i] == 'a')
            state = Terminal1;
        else if (state == Terminal1 && str[i] == 'b')
            state = Terminal2;
        else if (state == Terminal2 && str[i] == 'a')
            state = Final;
        else if (state == Terminal2 && str[i] == 'b')
            state = Initial;
        else if (state == Final && (str[i] == 'a' || str[i] == 'b'))
            state = Final;
    }

    if (state == Final)
        cout << "String accepted" << endl;
    else
        cout << "String not accepted" << endl;

    return 0;
}