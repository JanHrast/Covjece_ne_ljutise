#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

string ploca = "";
int zeleniPijuni[4]={-1,-1,-1,-1};
int brojPiunaZeleni=0;

struct celija{
    int index;
    char znak;
};

   celija ploca2[11][11] = {
        {{-1, 'Z'}, {-2, 'Z'}, {-1000, ' '}, {-1000, ' '}, {33, 'O'}, {32, 'O'}, {31, 'O'}, {-1000, ' '}, {-1000, ' '}, {-5, 'C'}, {-6, 'C'}},
        {{-3, 'Z'}, {-4, 'Z'}, {-1000, ' '}, {-1000, ' '}, {34, 'O'}, {-1000, ' '}, {30, 'O'}, {-1000, ' '}, {-1000, ' '}, {-7, 'C'}, {-8, 'C'}},
        {{-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {34, ' '}, {35, 'O'}, {-1000, ' '}, {29, 'O'}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}},
        {{-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {35, ' '}, {36, 'O'}, {-1000, ' '}, {28, 'O'}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}},
        {{1, 'O'}, {40, 'O'}, {39, 'O'}, {38, 'O'}, {37, 'O'}, {-1000, ' '}, {27, 'O'}, {26, 'O'}, {25, 'O'}, {24, 'O'}, {23, 'O'}},
        {{2, 'O'}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {22, 'O'}},
        {{3, 'O'}, {4, 'O'}, {5, 'O'}, {6, 'O'}, {7, 'O'}, {-1000, ' '}, {17, 'O'}, {18, 'O'}, {19, 'O'}, {20, 'O'}, {21, 'O'}},
        {{-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {8, 'O'}, {-1000, ' '}, {16, 'O'}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}},
        {{-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {9, 'O'}, {-1000, ' '}, {15, 'O'}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}, {-1000, ' '}},
        {{-9, 'P'}, {-10, 'P'}, {-1000, ' '}, {-1000, ' '}, {10, 'O'}, {-1000, ' '}, {14, 'O'}, {-1000, ' '}, {-1000, ' '}, {-13, 'N'}, {-14, 'N'}},
        {{-11, 'P'}, {-12, 'P'}, {-1000, ' '}, {-1000, ' '}, {11, 'O'}, {12, 'O'}, {13, 'O'}, {-1000, ' '}, {-1000, ' '}, {-15, 'N'}, {-16, 'N'}}
    };

int kocka()
{
    int n = rand() % 6 + 1;

    cout << "Tvoj broj je: "<<n;
    return n;

}


void igra()
{
    string zeleni, zuti, plavi, crveni;

    while(1)
    {
        cout<<"ZELENI NA POTEZU: "<<endl;
        int k = kocka();
        while(k==6)
        {
            cout<<"Pokani piuna(1) ili Izadi van(2): "<<endl;
            int odabir;
            cin>>odabir;
            if(odabir==1)
            {
                cout<<"Kojeg piuna zelis pomaknut: 1, 2, 3, 4: "<<endl;
                int odabirPiun;
                cin>>odabirPiun;
                //micemo piun sa polja
                ploca[zeleniPijuni[odabirPiun-1]] = 'O';
                //stavljamo ga na novo mjesto
                ploca[zeleniPijuni[odabirPiun-1]+k]='z';

            }
            else if(odabir==2)
            {

                brojPiunaZeleni++;

            }
        }

    }
}


void pause()
{
    cout << endl
         << " -- Pritisnite enter za povratak -- ";
    string dummy;
    cin.ignore();
    getline(cin, dummy);
}



int zasluge()
{

    cout << "Martin Gorisek i Jan Hrastnik";
    return 0;
}

void ispisPloce()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ploca[i*8 + j];
            cout << " ";
        }
        cout << endl;
    }
}

void ispisPloce2()
{
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            cout << ploca2[i][j].znak;
        }
        cout << endl;
    }
}

int main()
{
    srand (time(NULL));

    for (int i = 0; i < 40; i++){
        ploca += 'O';

    }

    //ispisPloce();

    int izbor;

        system("cls");



        cout << "COVJECE NE LJUTI SE" << endl;
        cout << " -- pritisnete 1 za pokretanje nove igre -- " << endl;
        cout << " -- pritisnete 2 za nastavak igre -- " << endl;
        cout << " -- pritisnite 3 kako bi vidjeli zaasluge -- " << endl;
        cout << " -- pritisnite 4 za izlaz iz programa -- " << endl;
        cin >> izbor;

        if (izbor == 1)
        {
            ispisPloce2();
         }

        else if (izbor == 2)
        {
            kocka();
        }

        else if (izbor == 3)
        {
            zasluge();
        }

        else if (izbor == 4)
        {
            cout << " -- izlaz iz programa -- ";

        }
        while(1){}
    return 0;
}
