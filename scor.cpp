#include <fstream>
#include <cstring>
#define LGMAX 102
using namespace std;
ifstream fin("scor.in");
ofstream fout("scor.out");
struct NrMare { int nrCifre, cifre[LGMAX]; };
void citesteNrMare(NrMare&);
void afiseazaNrMare(NrMare);
int ultimaCifra(NrMare);
int comparaNrMari(NrMare, NrMare);
void scadeNrMari(NrMare, NrMare, NrMare&);
void imparteNrMareLaNrMic(NrMare, int, NrMare&);
void adunaNrMari(NrMare, NrMare, NrMare&);
int main()
{
    int n;
    NrMare s, d, aux, b, a;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        citesteNrMare(s);
        citesteNrMare(d);
        if (ultimaCifra(s)%2 || comparaNrMari(s, d) < 0)
            fout << "impossible";
        else
        {
            scadeNrMari(s, d, aux);
            imparteNrMareLaNrMic(aux, 2, b);
            adunaNrMari(b, d, a);
            afiseazaNrMare(a);
            fout << ' ';
            afiseazaNrMare(b);
        }
        fout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
void adunaNrMari(NrMare a, NrMare b, NrMare& c)
{
    int i, t, val;
    c.nrCifre = a.nrCifre > b.nrCifre ? a.nrCifre : b.nrCifre;
    if (a.nrCifre < b.nrCifre)
        for (i = a.nrCifre; i < b.nrCifre; i++)
            a.cifre[i] = 0;
    else if (b.nrCifre < a.nrCifre)
        for (i = b.nrCifre; i < a.nrCifre; i++)
            b.cifre[i] = 0;
    for (t = i = 0; i < c.nrCifre; i++)
    {
        val = a.cifre[i]+b.cifre[i]+t;
        c.cifre[i] = val%10;
        t = val/10;
    }
    if (t)
        c.cifre[i] = t, c.nrCifre++;
}
void imparteNrMareLaNrMic(NrMare a, int b, NrMare& c)
{
    if (ultimaCifra(a) == 0 && a.nrCifre == 1)
        c.cifre[0] = 0, c.nrCifre = 1;
    else
    {
        int r, i, val;
        for (r = 0, i = a.nrCifre-1; i >= 0; i--)
        {
            val = r*10 + a.cifre[i];
            c.cifre[i] = val/b;
            r = val%b;
        }
        for (i = a.nrCifre-1; c.cifre[i] == 0 && i > 0; i--);
        c.nrCifre = i+1;
    }
}
void scadeNrMari(NrMare a, NrMare b, NrMare& c)
{
    int i, t, val;
    for (i = 0; i < LGMAX; i++)
        c.cifre[i] = 0;
    for (i = b.nrCifre; i < a.nrCifre; i++)
        b.cifre[i] = 0;
    for (t = i = 0; i < a.nrCifre; i++)
    {
        val = a.cifre[i]-b.cifre[i]-t;
        if (val < 0)
            val += 10, t=1;
        else
            t = 0;
        c.cifre[i] = val;
    }
    for (i = a.nrCifre-1; c.cifre[i] == 0 && i > 0; i--);
    c.nrCifre = i+1;
}
int comparaNrMari(NrMare a, NrMare b)
{
    if (a.nrCifre < b.nrCifre)
        return -1;
    if (a.nrCifre > b.nrCifre)
        return 1;
    int i;
    for (i = a.nrCifre-1; a.cifre[i] == b.cifre[i] && i >= 0; i--);
    if (i < 0)
        return 0;
    if (a.cifre[i] < b.cifre[i])
        return -1;
    return 1;
}
int ultimaCifra(NrMare a)
{
    return a.cifre[0];
}
void afiseazaNrMare(NrMare a)
{
    for (int i = a.nrCifre-1; i >=0; i--)
        fout << a.cifre[i];
}
void citesteNrMare(NrMare& a)
{
    char s[LGMAX];
    fin >> s;
    a.nrCifre = strlen(s);
    int i;
    for (i = 0; i < a.nrCifre; i++)
        a.cifre[i] = s[a.nrCifre-i-1]-'0';
    for (i = a.nrCifre; i < LGMAX; i++)
        a.cifre[i] = 0;
}
