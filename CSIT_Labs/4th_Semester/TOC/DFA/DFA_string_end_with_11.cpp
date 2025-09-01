// Cpp program for DFA for the language of string over {0,1} in which each string ends with 11

#include <iostream>
#include <string>
using namespace std;

enum States {
    Initial,    // q0
    Terminal,   // q1
    Final       // q2
};

int main()
{
    string str;
    States state = Initial;

    cout << "Enter the string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
            return 0;
        }

        if (state == Initial && str[i] == '0')
            state = Initial;
        else if (state == Initial && str[i] == '1')
            state = Terminal;
        else if (state == Terminal && str[i] == '0')
            state = Initial;
        else if (state == Terminal && str[i] == '1')
            state = Final;
        else if (state == Final && str[i] == '0')
            state = Initial;
        else if (state == Final && str[i] == '1')
            state = Terminal;
    }

    if (state == Final)
        cout << "String accepted";
    else
        cout << "String not accepted";

    return 0;
}
