//
// Created by gueas on 24/02/2023.
//


// file matricole.txt
//  11485 Marius
//  11486 Serge
//  11487 Marco
// file straordinari
//  11485 10
//  11486 20
//  11487 30
// file stipendi
//  11485 1000
//  11486 2000
//  11487 3000

#include <iostream>
#include <fstream>

using namespace std;

//=====================================================================================================================================>
//findSalaryAndStraordinaryByCod                              3                                                                       ||
//======================================================================================================================================>

string cerca(string nomefile, string cod)
{
    string risultato = "";

    ifstream fileAperto(nomefile);
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {

            for (int i = 0; i < 6; i++)
            {
                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4) // ultimo carattere della matricola
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        cout << line[j] << endl;
                        risultato += line[j];
                    }
                }
            }
        }
    }
    else
    {
        cout << "2 Impossibile aprire il file .txt" << endl;
    }
    return risultato;
}

void findNameByCod(string cod)
{
    string risultato = cerca("matricola.txt", cod);
    cout << "La matricola: " << cod << " corrisponde al nome: " << risultato << endl;
}

void findSalaryByCod(string cod)
{
    cout << "matricola: " << cod << " stipendio: " << cerca("stipendio.txt", cod) << endl;
}

void findStraordinaryByCod(string cod)
{
    cout << "matricola: " << cod << " straordinario: " << cerca("straordinari.txt", cod) << endl;
}

void findSalaryByName(string nome)
{
    ifstream fileAperto("matricola.txt");
    string cod = "";
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {
            int k = 0;
            for (int i = 6; i < line.length(); i++)
            {

                // 11855 Marcella
                // 0123456789
                // Marcella

                if (line[i] != nome[k])
                {
                    break;
                }
                else if (k == nome.length() - 1) // ultimo carattere del nome
                {
                    for (int j = 0; j < 5; j++)
                    {
                        cod += line[j];
                    }
                }

                k++;
            }
        }

        fileAperto.close();
    }
    else
    {
        cout << "1 Impossibile aprire il file .txt" << endl;
    }

    string stipendioValore = cerca("stipendio.txt", cod);

    cout << "Il nome: " << nome << " corrisponde alla matricola: " << cod << " e al stipendio: " << stipendioValore << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalita'  che vuoi attivare" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Matricola -> Straordinari" << endl;
        cout << "4. Nome -> Stipendio" << endl;
        cout << "5. Matricola -> Stipendio + straordinari (35h)" << endl;
        cout << "0. EXIT" << endl;
        int scelta;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare";
        string input;
        cin >> input;

        if (scelta < 0 || scelta > 5) // DA MODIFICARE IN CASO DI AGGIUNTE NEL MENU
        {
            cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
            }
            else if (scelta == 3)
            {
                findStraordinaryByCod(input);
            }
            else if (scelta == 4)
            {
                findSalaryByName(input);
            }
            else if (scelta == 5)
            {
                // findSalaryAndStraordinaryByCod(input);
            }
            else if (scelta == 0)
            {
                flag = false;
            }
            else
            {
                cout << "Scelta non valida" << endl;
            }
        }
    }

    cout << "Fine" << endl;
}



//================================================================================================================================================>
  //Implementa la funzione di interfaccia utente      1                                                                                          ||
 //===============================================================================================================================================>

/*void findNameByCod(string cod)
{
    string nome = "serge";
    // file matricola.txt
    //  11485 Marius
    //  11486 Serge
    //  11487 Marco

    ifstream fileMatricola("matricola.txt");
    if (fileMatricola.is_open())
    {
        cout << "File matricole.txt aperto correttamente" << endl;
        string line;
        while (getline(fileMatricola, line))
        {
            for (int i = 0; i < 6; i++)
            {
                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4)
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        nome+=line[j];
                    }

                }
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file matricole.txt" << endl;
    }

    cout << "La matricola: " << cod << " corrisponde al nome: " << nome << endl;
}

void findSalaryByCod(string cod)
{
    cout << "sono findSalaryByCod" << endl;
}

void findSalaryByName(string name)
{
    cout << "sono findSalaryByName" << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalità che vuoi attivare" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Nome -> Stipendio" << endl;
        int scelta;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare" << endl;
        string input;
        cin >> input;

        if (scelta < 1 || scelta > 3)
        {
            cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
                flag = false;
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
                flag = false;
            }
            else if (scelta == 3)
            {
                findSalaryByName(input);
                flag = false;
            }
            else
            {
                cout << "Scelta non valida" << endl;
            }
        }
    }

    cout << "Fine" << endl;
}*/

//=================================================================================================================================================================>
//                                                                                  2
//=================================================================================================================================================================>





/*string cerca(string nomefile, string cod)
{
    string risultato = "";

    ifstream fileAperto(nomefile);
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {

            for (int i = 0; i < 6; i++)
            {
                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4) // ultimo carattere della matricola
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        risultato += line[j];
                    }
                }
                else
                {
                }
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file .txt" << endl;
    }

    return risultato;
}

void findNameByCod(string cod)
{
    string risultato = cerca("matricola.txt", cod);
    cout << "La matricola: " << cod << " corrisponde al nome: " << risultato << endl;
}

void findSalaryByCod(string cod)
{
    cout << "matricola: " << cod << " stipendio: " << cerca("stipendio.txt", cod) << endl;
}

void findStraordinaryByCod(string cod)
{
    cout << "matricola: " << cod << " straordinario: " << cerca("straordinari.txt", cod) << endl;
}

void findSalaryByName(string nome)
{
    ifstream fileAperto("matricola.txt");
    string cod = "";
    if (fileAperto.is_open())
    {
        string line;
        while (getline(fileAperto, line))
        {

            for (int i = 6; i < line.length(); i++)
            {
                if (line[i] != nome[i])
                {
                    break;
                }
                else if (i == 4) // ultimo carattere della matricola
                {
                    for (int j = 0; j < 5; j++)
                    {
                        cod += line[j];
                    }
                }
                else
                {
                }
            }
        }
    }
    else
    {
        cout << "Impossibile aprire il file .txt" << endl;
    }

    int stipendioValore = stoi(cerca("stipendio", cod));

    cout << "Il nome: " << nome << " corrisponde alla matricola: " << cod << " e al stipendio: " << stipendioValore << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalita' che vuoi attivare" << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Matricola -> Straordinari" << endl;
        cout << "4. Nome -> Stipendio" << endl;
        cout << "5. Matricola -> Stipendio + straordinari (35h)" << endl;
        cout << "0. EXIT" << endl;
        int scelta;
        cin >> scelta;
        cout << "Inserisci quello che vuoi cercare";
        string input;
        cin >> input;

        if (scelta < 0 || scelta > 5) // DA MODIFICARE IN CASO DI AGGIUNTE NEL MENU
        {
            cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
            }
            else if (scelta == 3)
            {
                findStraordinaryByCod(input);
            }
            else if (scelta == 4)
            {
                findSalaryByName(input);
            }
            else if (scelta == 5)
            {
                // findSalaryAndStraordinaryByCod(input);
            }
            else if (scelta == 0)
            {
                flag = false;
            }
            else
            {
                cout << "Scelta non valida" << endl;
            }
        }
    }

    cout << "Fine" << endl;
}*/

