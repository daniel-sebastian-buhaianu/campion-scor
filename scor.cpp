#include <fstream>
#include <cstring>
#define MAXCIF 101
using namespace std;
ifstream fin("scor.in");
ofstream fout("scor.out");
struct NrMare
{
	int nrcif;
	char cif[MAXCIF];
};
void citesteNrMare(NrMare &);
int comparaNrMari(NrMare, NrMare);
void scadeNrMari(NrMare, NrMare, NrMare &);
void imparteNrMareLaNrMic(NrMare, int, NrMare &, int &);
void adunaNrMari(NrMare, NrMare, NrMare &);
void afiseazaNrMare(NrMare);
int main()
{
	int T, i, rest;
	NrMare s, d, dif, a, b;
	fin >> T;
	for (i = 0; i < T; i++)
	{
		citesteNrMare(s);
		citesteNrMare(d);
		if (comparaNrMari(s, d) < 0)
		{
			fout << "impossible\n";
		}
		else
		{
			scadeNrMari(s, d, dif);
			imparteNrMareLaNrMic(dif, 2, a, rest);
			if (rest)
			{
				fout << "impossible\n";
			}
			else
			{
				adunaNrMari(a, d, b);
				afiseazaNrMare(b);
				fout << ' ';
				afiseazaNrMare(a);
				fout << '\n';
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}
void adunaNrMari(NrMare a, NrMare b, NrMare & s)
{
	int i, t, val;
	if (a.nrcif < b.nrcif)
	{
		for (i = a.nrcif; i < b.nrcif; i++)
		{
			a.cif[i] = 0;
		}
		s.nrcif = b.nrcif;
	}
	else
	{
		for (i = b.nrcif; i < a.nrcif; i++)
		{
			b.cif[i] = 0;
		}
		s.nrcif = a.nrcif;
	}
	for (t = i = 0; i < s.nrcif; i++)
	{
		val = a.cif[i] + b.cif[i] + t;
		s.cif[i] = val%10;
		t = val/10;
	}
	if (t)
	{
		s.cif[s.nrcif++] = t;
	}
}
void imparteNrMareLaNrMic(NrMare a, int b, NrMare & nr, int & r)
{
	if (a.nrcif == 1 && a.cif[0] == 0)
	{
		r = nr.cif[0] = 0;
		nr.nrcif = 1;
		return;
	}
	r = 0;
	for (int i = a.nrcif-1; i >= 0; i--)
	{
		int val = r*10 + a.cif[i];
		nr.cif[i] = val/b;
		r = val%b;
	}
	for (nr.nrcif = a.nrcif;
	     nr.cif[nr.nrcif-1] == 0 && nr.nrcif > 1;
	     nr.nrcif--);
}
void scadeNrMari(NrMare a, NrMare b, NrMare & d)
{
	int i, t, val;
	for (i = b.nrcif; i < a.nrcif; i++)
	{
		b.cif[i] = 0;
	}
	for (t = i = 0; i < a.nrcif; i++)
	{
		val = a.cif[i] - b.cif[i] + t;
		if (val < 0)
		{
			d.cif[i] = val + 10;
			t = -1;
		}
		else
		{
			d.cif[i] = val;
			t = 0;
		}
	}
	for (d.nrcif = a.nrcif;
	     d.cif[d.nrcif-1] == 0 && d.nrcif > 1;
	     d.nrcif--);
}
int comparaNrMari(NrMare a, NrMare b)
{
	if (a.nrcif > b.nrcif) return 1;
	if (a.nrcif < b.nrcif) return -1;
	int i;
	for (i = 0; i < a.nrcif && a.cif[i] == b.cif[i]; i++);
	if (i == a.nrcif) return 0;
	if (a.cif[i] > b.cif[i]) return 1;
	return -1;
}
void afiseazaNrMare(NrMare nr)
{
	for (int i = nr.nrcif-1; i >= 0; i--)
	{
		fout << (int)nr.cif[i];
	}
}
void citesteNrMare(NrMare & nr)
{
	int lg, i;
	char s[MAXCIF+1];
	fin >> s;
	nr.nrcif = lg = strlen(s);
	for (i = lg-1; i >= 0; i--)
	{
		nr.cif[lg-i-1] = s[i]-'0';
	}
	for (i = lg; i < MAXCIF; i++)
	{
		nr.cif[i] = 0;
	}
}
// scor 10
