#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <time.h>
using namespace std;

string ploca = "";

struct celija
{
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
    {{-11, 'P'}, {-12, 'P'}, {-1000, ' '}, {-1000, ' '}, {11, 'O'}, {12, 'O'}, {13, 'O'}, {-1000, ' '}, {-1000, ' '}, {-15, 'N'}, {-16, 'N'}}};

int kocka()
{
    int n = rand() % 6 + 1;

    cout << "Tvoj broj je: " << n << endl;
    return n;
}

bool findElement(int index, int &row, int &col) //trazi broj u dva d polju od 1 do 40
{
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if (ploca2[i][j].index == index)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

void ispisPloce2()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << ploca2[i][j].znak;
        }
        cout << endl;
    }
}

int pijuni[4][4] = {
    {-1, -2, -3, -4},
    {-5, -6, -7, -8},
    {-9, -10, -11, -12},
    {-13, -14, -15, -16}};

char znakovi[4] = {'Z', 'C', 'P', 'N'};
int brojPijuna[4] = {0, 0, 0, 0};
string nazivi[4] = {"Zeleni", "Crveni", "Plavi", "Narancasti"};
int igrac = 0;

void saveGame() //binarna datoteka
{
    fstream datoteka;
    datoteka.open("save.bin", ios::trunc);
    datoteka.close();
    datoteka.open("save.bin", ios::out | ios::binary);
    datoteka.write((char *)ploca2, sizeof(ploca2)); // od 1 elementa pise kak je izgledala ploca
    datoteka.write((char *)pijuni, sizeof(pijuni));
    datoteka.write((char *)brojPijuna, sizeof(brojPijuna));
    datoteka.write((char *)&igrac, sizeof(igrac));// sve do tud
    datoteka.close();
    fstream datoteka2;
    // name.txt
    datoteka2.open("name.txt", ios::out);
    for (int i = 0; i < 4; i++)
    {
        datoteka2 << nazivi[i] << endl; // nema cout jer ne pise tekst u konzolu nego u file
    }
    datoteka2.close();
}

void igra()
{
    // int igrac=0; //Varijabla koja odrađuje tko je na potezu
    while (1)
    {
        cout << " klikni 7 za izlaz iz igre: "<<endl<<endl;
        cout << nazivi[igrac % 4] << " klikni 0 da bacite kocku: " << endl;
        int baciKocku;
        cin >> baciKocku;
        if (true)
        {
            int pomak;       // Za kolko se pijun treba pomaknut
            int pijun;       // Indeks pijuna koji se mice
            int razlika = 0; // Gdje piuni izlaze
            bool prviPotez = false;
            bool zeleniVani = false;
            pomak = kocka();
            if (baciKocku == 7) // izlaz
            {
                break;
            }
            else if (baciKocku != 0) // varanje
                pomak = baciKocku;
            while (1) // potez, bacanje kocke, ako nije 6 ide dalje(na pocetku)
            {
                if (brojPijuna[igrac] == 0 && pomak != 6)
                { // brojPiuna[igraca] je kolko piuna ima
                    system("cls");
                    ispisPloce2();
                    break;
                }

                cout << "Kojeg pijuna zelite pomaknuti: " << endl;
                cin >> pijun;

                if (pijuni[igrac][pijun] < 0 && pomak != 6 || pijuni[igrac][pijun] == -100) // polje sa pozicijama pijuna(pijuni[igrac][pijun]), iligalni potez
                {
                    cout << "Ilegalan potez " << endl;
                    continue;
                }

                if (pijuni[igrac % 4][pijun] < 0) // gleda dal je izaso iz kucice,
                {
                    razlika = 11 * igrac + abs(pijuni[igrac][pijun]) - pomak + 1;
                    prviPotez = true;
                    brojPijuna[igrac]++;
                }

                int i, j;
                findElement(pijuni[igrac % 4][pijun], i, j);
                ploca2[i][j].znak = 'O';                     // na staru poziciju stavlja prazno polje (O)
                pijuni[igrac % 4][pijun] += pomak + razlika; // racuna novu poziciju
                if (pijuni[igrac][pijun] > 40)
                { // gledamo dal izlazi iz polja
                    pijuni[igrac][pijun] -= 40;
                    if (igrac == 0)
                        zeleniVani = true;
                }

                findElement(pijuni[igrac % 4][pijun], i, j);
                if (ploca2[i][j].znak == znakovi[igrac]) // ako samog sebe probas pojest
                {
                    cout << "Ilegalan potez" << endl;
                    continue;
                }

                else if (ploca2[i][j].znak != 'O')
                {                     // cijeli els if je jedenje
                    int kucaI, kucaJ; // kordinate kucice
                    cout << "jedenje \n";
                    int znakZaPojest = (find(znakovi, znakovi + 4, ploca2[i][j].znak) - znakovi); // kog si pojeo
                    for (int k = -1; k > -5; k--)                                                 // trazi prvo slobodno mjesto u kucici
                    {
                        findElement(-4 * znakZaPojest + k, kucaI, kucaJ);
                        if (ploca2[kucaI][kucaJ].znak == 'O')
                        {
                            cout << kucaI << " " << kucaJ << "\n";
                            break;
                        }
                    }

                    int idx = find(pijuni[znakZaPojest], pijuni[znakZaPojest] + 4, ploca2[i][j].index) - pijuni[znakZaPojest]; // trazi u polju gdje su pijuni u kojem je polju bio pijun
                    pijuni[znakZaPojest][idx] = ploca2[kucaI][kucaJ].index;                                                    // stavlja ga u polje gdje su ostali pijun iste boje
                    brojPijuna[znakZaPojest]--;
                    ploca2[kucaI][kucaJ].znak = ploca2[i][j].znak; // zamjeni krug i znak
                }

                ploca2[i][j].znak = znakovi[igrac]; // gleda di treba ic pijun i stavlja ga na to mjesto

                if (pijuni[igrac][pijun] >= (11 * igrac + 1) && ((pijuni[igrac][pijun] - pomak) < (11 * igrac) || zeleniVani) && prviPotez == false) // mice piuna kad prode cijelo polje
                {
                    
                    ploca2[i][j].znak = 'O';
                    pijuni[igrac][pijun] = -100;
                    brojPijuna[igrac]--;
                }

                if (pomak == 6)
                { // ponovno bacanje
                    igrac--;
                }
                system("cls");
                ispisPloce2();
                razlika = 0;
                prviPotez = false;
                zeleniVani = false;
                break;
            }
        }
        igrac++;
        igrac = igrac % 4; // limitira na 4 igraca
        saveGame();
    }
}

void loadGame()
{
    fstream datoteka;
    datoteka.open("save.bin", ios::in | ios::binary);
    datoteka.read((char *)ploca2, sizeof(ploca2)); //kopira iz file u memoriju, onaj prvi je obrnut save game
    datoteka.read((char *)pijuni, sizeof(pijuni));
    datoteka.read((char *)brojPijuna, sizeof(brojPijuna));
    datoteka.read((char *)&igrac, sizeof(igrac));
    datoteka.close();

    fstream datoteka2;
    datoteka2.open("name.txt", ios::in);
    for (int i = 0; i < 4; i++)
    {
        datoteka2 >> nazivi[i]; //isto kao i kod save game
    }
    datoteka2.close();

    ispisPloce2();
    igra();
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
            cout << ploca[i * 8 + j];
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 40; i++)
    {
        ploca += 'O';
    }

    // ispisPloce();

    int izbor;
    skok:
        while (1)
        {
            system("cls");

            cout << "COVJECE NE LJUTI SE" << endl;
            cout << " -- pritisnete 1 za pokretanje nove igre -- " << endl;
            cout << " -- pritisnete 2 za nastavak igre -- " << endl;
            cout << " -- pritisnite 3 kako bi vidjeli zasluge -- " << endl;
            cout << " -- pritisnite 4 kako bi unljeli imena igraca -- " << endl;
            cout << " -- pritisnite 5 za izlaz iz programa -- " << endl;
            cin >> izbor;

            if (izbor == 1)
            {
                ispisPloce2();
                igra();
            }

            else if (izbor == 2)
            {
                loadGame();
            }

            else if (izbor == 3)
            {
                zasluge();
            }

            else if (izbor == 4)
            {
                cout << "Unesite imena igraca: " << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << "Unesite ime igraca " << i + 1 << ": ";
                    cin >> nazivi[i];
                }
            }

            else if (izbor == 5)
            {
                cout << " -- izlaz iz programa -- ";
                return 0;
            }
        }
    return 0;
}
