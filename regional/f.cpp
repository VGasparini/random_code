#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

#define ESQ 0
#define DIR 1

int gl = 0, pl = 0;
int gr = 0, pr = 0;

int vez = ESQ;

void pontoEsq()
{
    pl++;
    if (pl == 10 || (pl >= 5 and pl > pr and pl - 2 >= pr))
    {
        gl++;
        pl = 0;
        pr = 0;
    }
    vez = ESQ;
}

void pontoDir()
{
    pr++;
    if (pr == 10 || (pr >= 5 and pr > pl and pr - 2 >= pl))
    {
        gr++;
        pr = 0;
        pl = 0;
    }
    vez = DIR;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    for (char c : s)
    {
        if (c == 'R')
        {
            if (vez == ESQ)
            {
                pontoDir();
            }
            else
            {
                pontoEsq();
            }
        }
        else if (c == 'S')
        {
            if (vez == DIR)
            {
                pontoDir();
            }
            else
            {
                pontoEsq();
            }
        }
        else
        {
            if (gr >= 2)
            {
                cout << gl << " - " << gr << " (winner)" << endl;
            }
            else if (gl >= 2)
            {
                cout << gl << " (winner) - " << gr << endl;
            }
            else
                cout << gl << " (" << pl << (vez == ESQ ? "*" : "") << ") - " << gr << " (" << pr << (vez == DIR ? "*" : "") << ")" << endl;
        }
    }
}

/*
S -> ponto de quem sacou
R -> ponto de quem recebeu
Q -> anuncio placar
--
GL -> games ganhos pela esquerda
GR -> games ganhos pela direita
PL -> pontos da esquerda
PR -> pontos da direita

*/