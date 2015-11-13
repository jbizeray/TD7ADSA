#include "Algo.h"

Algo::Algo()
{
    //ctor
}

void Algo::min_heapify(int *b, int i, int n)
{
    int j, temp;
    temp = b[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && b[j + 1] < b[j])
        {
            j = j + 1;
        }
        if (temp < b[j])
        {
            break;
        }
        else if (temp >= b[j])
        {
            b[j / 2] = b[j];
            j = 2 * j;
        }
    }
    b[j / 2] = temp;
    return;
}
void Algo::build_minheap(int *b, int n)
{
    int i;
    for(i = n / 2; i >= 1; i--)
    {
        min_heapify(b, i, n);
    }
}
void Algo::addEdge(vector<vector<int>> am, int src, int dest, int cost)
{
     am[src][dest] = cost;
     return;
}
void Algo::bell(vector<vector<int>> am)
{
    int i, j, k, c = 0, temp;
    a[0].cost = 0;
    a[0].from = 0;
    a[0].value = 0;
    for (i = 1; i < 7; i++)
    {
        a[i].from = 0;
        a[i].cost = INFINITY;
        a[i].value = 0;
    }
    while (c < 7)
    {
        int min = 999;
        for (i = 0; i < 7; i++)
        {
            if (min > a[i].cost && a[i].value == 0)
            {
                min = a[i].cost;
            }
            else
            {
                continue;
            }
        }
        for (i = 0; i < 7; i++)
        {
            if (min == a[i].cost && a[i].value == 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        temp = i;
        for (k = 0; k < 7; k++)
        {
            if (am[temp][k] + a[temp].cost < a[k].cost)
            {
                a[k].cost = am[temp][k] + a[temp].cost;
                a[k].from = temp;
            }
            else
            {
                continue;
            }
        }
        a[temp].value = 1;
        c++;
    }
    cout<<"Cost"<<"\t"<<"Source Node"<<endl;
    for (j = 0; j < 7; j++)
    {
        cout<<a[j].cost<<"\t"<<a[j].from<<endl;
    }

}


vector<string> Algo::split(string string, char delimiter)
{
    std::vector<std::string> internal;
    std::stringstream ss(string); // Turn the string into a stream.
    std::string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}


vector<vector<int>> Algo::LireTXT(string _nomFichier)
{
    ifstream file(_nomFichier);
    string line;
    vector<vector<int>> am;
    int z =0;
    if (file.is_open())
    {
        while(getline(file,line))
              {
                    z++;
              }
        for (int i = 0; i < z/3; i++)
        {
            for (int j = 0; j < z/3; j++)
            {
                am[i][j] = INFINITY;
            }
        }

        while (getline(file,line))
        {


            vector<string> linevector = split(line, ';');
            addEdge(am,string2real(*(linevector.begin())),string2real(*(linevector.begin()+1)),string2real(*(linevector.begin()+2)));
         }
            file.close();
    }
    else
        cout<<"Erreur lors de l'ouverture du fichier";

    return am;
}

int Algo::string2real(std::string const & s)
{
	return atof(s.c_str());
}

Algo::~Algo()
{
    //dtor
}
