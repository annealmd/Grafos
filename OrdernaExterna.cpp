//Anne Almeida
// Ordenação Externa g++ ./a.out dados.txt 1024
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct bufferBloco
{
    int ini; //(i*N)
    int pos; // file.tellg () posição atual
    int fim; //(((i+1)*N)-11)
    int buffer_pos;
    int buffer_tam;
    int *buffer;
};

void preencheBuffer(ifstream &file, struct bufferBloco* bloco, int T){
    int i;
    string line;
    file.seekg(bloco->pos);
    bloco->buffer_tam = 0;
    for(i=0; i<T; i++)
    {
        if(bloco->pos>=bloco->fim)
        {
            break;            
        }
        else
        {
            getline(file,line);
            bloco->pos = file.tellg();
            int x;
            sscanf(line.c_str(),"%d",&x);
            (bloco->buffer[i])=x;
            bloco->buffer_tam++;
        }
    }
    bloco->buffer_pos=0;
}

int procuraMenor(ifstream &file, struct bufferBloco* bloco, int K, int T, int *menor)
{
    int i, idx = -1;
    for(i=0; i<K; i++)
    {
        if(bloco[i].buffer_pos < bloco[i].buffer_tam){
            if(idx < 0)
                idx = i;
            else
                idx = bloco[i].buffer[ bloco[i].buffer_pos ] < bloco[idx].buffer[ bloco[idx].buffer_pos ] ? i : idx;
        }
    }

    if(idx != -1)
    {
        *menor = bloco[idx].buffer[bloco[idx].buffer_pos];
        bloco[idx].buffer_pos++;
        if(bloco[idx].buffer_pos == bloco[idx].buffer_tam)
        {
            preencheBuffer(file, &bloco[idx],T);
        }
        return 1;
    }else
    {
        return 0;
    }
}
    
void merge(ifstream &file, int K, int N, int T)
{
    ofstream temp("final.ordenado");
    int i;
    int *bufferSaida = new int [T];
    struct bufferBloco *bloco = new struct bufferBloco[K];

    for(i=0; i < K; i++)
    {
        bloco[i].ini = ((i*11)*N);
        bloco[i].pos = bloco[i].ini;
        if(i < K - 1)
            bloco[i].fim = ((((i+1)*11)*N));
        bloco[i].buffer = new int [T];
        file.seekg((i*11)*N);
        if(i < K - 1)
            preencheBuffer(file, &bloco[i],T);
    }
    file.seekg(0,ios::end);
    bloco[--i].fim = file.tellg();
    preencheBuffer(file, &bloco[i],T);

    //enquanto houver arquivos para processar
    int menor;
    int  qtdBuffer = 0;
    while(procuraMenor(file,bloco,K,T,&menor) == 1)
    {
        bufferSaida[qtdBuffer] = menor;
        qtdBuffer++;
        if(qtdBuffer == T)
        {
            for(i=0; i<T; i++)
            {
                temp.width(10);
                temp.fill('0');
                temp<<bufferSaida[i]<<endl;
            }
            qtdBuffer = 0;
        }
    }

    if(qtdBuffer != 0)
    { 
        for(i=0; i<qtdBuffer; i++)
        {
            temp.width(10);
            temp.fill('0');
            temp<<bufferSaida[i]<<endl;
        }
    }
    free(bloco);
    free(bufferSaida);
    temp.close();
}

int ordBlocos (ifstream &file, int tamBuffer)
{
    ofstream temp("temp1.txt");
    vector <int> blocos; // vetor com os elementos
    int i, n, k=0;
    while(!file.eof()) 
    {
        for ( i=0; i<(tamBuffer); i++) // cada bloco tem o tamanho do buffer
        { 
            file >> n;
            if (file.eof())break;
            blocos.push_back(n);      
        }
        if(i == 0)k--;
        make_heap(blocos.begin(),blocos.end());
        sort_heap(blocos.begin(),blocos.end());
    
        for (i=0; i<blocos.size(); i++) // imprime os ele do bloco no file
        {
            temp.width(10);
            temp.fill('0');
            temp<<blocos[i]<< endl;
        }
        blocos.clear();
        k++;  
    }
    temp.close();

    return k;
}

int main(int argc, char** argv) //argv[1] nome arquivo e argv[2] tamanho da RAM
{
    ifstream file (argv[1], ios::in | ios:: out);
    if(!file.is_open())
    {
        cerr<<"\nNão foi prossivel abrir o arquivo de entrada "<<argv[1]<<" ...\n";
        abort();
    }

    int N = atoi(argv[2]) / sizeof(int);
    cout<<"quantidade de elementos no Buffer: " << N << endl;
    int K = ordBlocos(file,N);
    int T = N / (K + 1);
    if(N < K + 1)
    {
        printf("Pouca memoria\n");
        return 0;
    }
    cout<< "Numero de Blocos Ordenados:"<< K <<endl; 
    cout<<"Tamanho dos buffers(k+1), numero de elementos: "<< T <<endl; 
    ifstream file1("temp1.txt");
    merge(file1, K, N, T);
    file.close();
    remove("temp1.txt"); 
    
    return 0;
}
