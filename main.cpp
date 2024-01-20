#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyswietl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden wiêkszej ni¿ poprzednia)
                if(p != NULL) //je¿eli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartoœæ poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuñ poprzedni¹ tablicê
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw now¹ wartoœæ do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaŸnika p
                n++; //zwiêksz iloœæ elementów tablicy o 1
                break;
            }
        case 2:
            {
                //wstawienie elementu w dowolne miejsce
                int * tmp = NULL;
                tmp = new int[n+1];
                int x = 0;
                if(p!= NULL)
                {
                    cout << "Pod jaki indeks wstawic element?";
                    cin >> x;

                    for(int i=0; i<x; i++)
                    {
                        tmp[i] = p[i];
                    }
                    cout << "Jaka liczbe wstawic?";
                    cin >> tmp[x];

                    for(int i=x+1; i<n; i++)
                    {
                        tmp[i] = p[i-1];
                    }
                    delete[] p;

                    p = tmp;
                    n++;
                }
                break;
            }
        case 3:
            {
                int * tmp = NULL;
                tmp = new int[n-1];

                if(p!= NULL)
                {
                    cout << "Z ktorego indeksu usunac?";
                    int x = 0;
                    cin >> x;

                    for(int i=0; i<x; i++)
                    {
                        tmp[i] = p[i];
                    }

                    for(int i=x; i<n; i++)
                    {
                        tmp[i] = p[i+1];

                    }
                    delete[] p;

                    p = tmp;
                    n--;
                }
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
                //zapis danych do pliku
                fstream plik;
                plik.open("plik.txt", ios::out|ios::trunc);
                if(!plik.is_open())
                {
                    return -1;
                }

                for(int i=0; i<n; i++)
                {
                    plik << p[i] << endl;
                }
                plik.close();
            }
        case 6:
            {
                //wczytanie danych z pliku
                fstream plik;
                plik.open("plik.txt", ios::in);
                if(!plik.is_open())
                {
                    return -1;
                }
                string line;
                while(!plik.eof())
                {
                    getline(plik, line);
                    if(line == "")
                    {
                        break;
                    }
                    int x = atoi(line.c_str());
                    cout << x << endl;
                    int * tmp = NULL;
                    tmp = new int[n+1];
                    if(p != NULL)
                    {
                        for(int i=0;i<n;i++)
                        {
                            tmp[i] = p[i];
                        }

                        delete[] p;

                    }
                    tmp[n] = x;
                    p = tmp;
                    n++;
                }
                plik.close();
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }

        }
    }

    return 0;
}
