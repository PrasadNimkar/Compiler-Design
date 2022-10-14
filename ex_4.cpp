// Aim:     //
#include <iostream>
using namespace std;

class Trans
{
public:
    char ip_state, op_state, ip_symbol;
    Trans()
    {
        ip_state = op_state = ip_symbol = '\0';
    }
};

int main()
{
    int nos, ips, notr, lc, i;
    char state[10], ipsmb[10], str[5], istate, fstate, extra;
    Trans tr[20];

    cout << "Enter the numbeer of state:";
    cin >> nos;
    for (int i = 0; i < nos; i++)
    {
        cout << "Enter state:" << i + 1 << ":";
        cin >> state[i];
    }

    cout << "Enter initial state:";
    cin >> istate;
    cout << "Enter final sate:";
    cin >> fstate;

    cout << "Enter number of i/p symbol:";
    cin >> ips;

    for (int i = 0; i < ips; i++)
    {
        cout << "Enter i/p symbol:" << i + 1 << ":";
        cin >> ipsmb[i];
    }

    cout << "Enter no. of transition:";
    cin >> notr;

    for (i = 0; i < notr; i++)
    {
        cout << "Enter transition:" << i + 1 << ":";
        cin >> tr[i].ip_state >> tr[i].ip_symbol >> tr[i].op_state;
    }

    for (i = 0; i < notr; i++)
    {
        cout << tr[i].ip_state << "->" << tr[i].ip_symbol << tr[i].op_state << "\n";
    }
    extra = istate;

    cout << "Enter string:";
    cin >> str;
    int k = 0;
    for (i = 0; i < notr; i++)
    {
        if ((extra == tr[i].ip_state) && (str[k] == tr[i].ip_symbol))
        {
            extra = tr[i].op_state;
            k++;
            i = -1;
        }
    }
    if (extra == fstate)
        cout << "String is accepted";
    else
        cout << "String is not accepted";

    return 0;
}