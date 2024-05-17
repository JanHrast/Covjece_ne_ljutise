#include <iostream>
#include <windows.h>
using namespace std;

void pause()
{
    cout << endl
         << " -- Pritisnite enter za povratak -- ";
    string dummy;
    cin.ignore();
    getline(cin, dummy);
}

int igra()
{
    int n;
    cout << "upisi broj" << endl;
    cin >> n;
    cout << "tvoj broj je:" << n << endl;
    return 0;
}

    int zasluge()
    {

        cout << "Martin Gorisek i Jan Hrastnik";
        return 0;
}

int main()
{
    int izbor;

    while (1)
    {
        system("cls");
        cout << "COVJECE NE LJUTI SE" <<endl;
        cout << " -- pritisnete 1 za pokretanje nove igre -- " << endl;
        cout << " -- pritisnete 2 za nastavak igre -- " <<endl;
        cout << " -- pritisnite 3 kako bi vidjeli zaasluge -- " <<endl;
        cout << " -- pritisnite 4 za izlaz iz programa -- " << endl;
        cin >> izbor;

        if(izbor == 1)
        {
            igra();
        }

        else if (izbor == 2)
        {
            
        }

        else if (izbor == 3)
        {
            zasluge();
        }

        else if (izbor == 4)
        {
            cout << " -- izlaz iz programa -- ";
            break;
        }
    }


}