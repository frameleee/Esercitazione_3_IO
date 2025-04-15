#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
	// Lettura dati dal file data.txt
	string inputFileName = "./data.txt";
	double S;
	size_t n;
	double* w;
	double* r;
	
	if(!ImportVectors(inputFileName, S, n, w, r))
	{
		cerr << "Qualcosa è andato storto con l'importazione" << endl;
		return -1;
	}
	else
	{
		cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
		cout << "w = " << ArrayToString(n, w) << endl;
		cout << "r = " << ArrayToString(n, r) << endl;
	}

	// Calcolo del tasso di rendimento
	double rateReturn = RateOfReturn(n, w, r);
	cout << "Rate of return of the portfolio: " << setprecision(4) << rateReturn << endl;
	
	// Calcolo del valore finale
	double V = (1 + rateReturn) * S;
	cout << "V: " << fixed << setprecision(2) << V << endl;
	
	// Stampa sul file result.txt
	string outputFileName = "./result.txt";
	if(!ExportResult(outputFileName, S, n, w, r, rateReturn, V))
	{
		cerr << "Qualcosa è andato storto nell'esportazione" << endl;
		return -1;
	}
	
	delete[] w;
	delete[] r;

    return 0;
}

