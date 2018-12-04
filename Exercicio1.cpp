#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;

void selectionSort(vector<int> &v)
{
    unsigned menorPos;
    int aux;

    //Loop em todo vetor
    for(unsigned i = 0; i < v.size(); ++i)
    {
        //Pega a posicao atual
        menorPos = i;

        //Loop a partir da proxima posicao depois da atual
        for(unsigned j = i + 1; j < v.size(); ++j)
        {
            //Testa s as posicoes subsequentes sao menores q a posição atual
            if(v[j] < v[menorPos])
                menorPos = j;
        }

        //Se encontrou uma posicao menor q a posicao atual troca de lugar
        if(menorPos != i)
        {
            aux = v[i];
            v[i] = v[menorPos];
            v[menorPos] = aux;
        }
    }
}

void insertionSort(vector<int> &v)
{
    int valorEscolhido;

    //Asuminindo que a posição 0 ja esta ordenada
    for(int i = 1; i < v.size(); ++i)
    {
        //Pega a posicao atual
        valorEscolhido = v[i];

        //Pula para proxima posicao
        int j = i - 1;

        //Loop para procurar valores maiores do q o valor atual
        while((j >= 0) && v[j] > valorEscolhido)
        {
            //Se encontrar joga os valores para direita
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = valorEscolhido;
    }
}

void splitString(const string &str, char delimitador, vector<int> &v)
{
    stringstream ss(str);
    string token;
    int valor = 0;

    v.clear();

    while (getline(ss, token, delimitador))
    {
        valor = stoi(token);
        v.push_back(valor);
    }

    cout << "Tamanho do vetor = " << v.size() << endl;
}

int main()
{
    cout << "Inicio do teste" << endl;

    bool sair = false;
    unsigned op;
    string vetor;
    vector<int> vetorNum;

    while(!sair)
    {
        cout << endl << "0) Selection Sort" << endl;
        cout << "1) Insertion Sort" << endl;
        cout << "2) Sair" << endl;

        cin >> op;

        switch (op)
        {
            case 0:
                cout << endl << "Selection Sort" << endl << endl;
                cout << "Digite o vetor separado por virgula: " << endl;
                cin >> vetor;
                splitString(vetor, ',', vetorNum);

                selectionSort(vetorNum);

                for(int s : vetorNum)
                    cout << s << " ";

                break;
            case 1:
                cout << endl << "Insertion Sort" << endl << endl;
                cout << "Digite o vetor separado por virgula: " << endl;
                cin >> vetor;
                splitString(vetor, ',', vetorNum);

                insertionSort(vetorNum);

                for(int s : vetorNum)
                    cout << s << " ";

                break;
            case 2:
                sair = true;
                continue;
            default:
                continue;
        }
    }

    return 0;
}
