#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

bool ImportVectors(const string& inputFilePath,
				   double& S,
				   size_t& n,
				   double*& w,
				   double*& r)
{
	ifstream file;
	file.open(inputFilePath);
	
	if(file.fail())
	{
		cerr << "Errore nell'apertura del file in lettura" << endl;
		return false;
	}
	
	string tmp;
	string line;
	
	// Lettura di S
	getline(file, line);
	stringstream ss1(line);
	getline(ss1, tmp, ';');
	ss1 >> S;
	
	// Lettura di n
	getline(file, line);
	stringstream ss2(line);
	getline(ss2, tmp, ';');
	ss2 >> n;
	
	getline(file, line);
	
	// Lettura di w e r
	w = new double[n];
	r = new double[n];
	
	
	for(unsigned int i = 0; i < n; i++)
	{
		getline(file, line);
		stringstream ss(line);
		string tmp;
		getline(ss, tmp, ';');
		w[i] = stod(tmp);
		getline(ss, tmp, ';');
		r[i] = stod(tmp);
	}

	
	file.close();
	
	return true;
}


double RateOfReturn(const size_t& n,
					const double* const& w,
					const double* const& r)
{
	double rateReturn = 0.0;
	for(unsigned int i = 0; i < n; i++)
	{	
		rateReturn += w[i] * r[i];
	}
	
	return rateReturn;
}


bool ExportResult(const string& outputFilePath,
				  double& S,
				  const size_t& n,
				  const double* const& w,
				  const double* const& r,
				  const double& rateReturn,
				  const double& V)
{
	ofstream file;
	file.open(outputFilePath);
	
	if(file.fail())
	{
		cerr << "Errore nell'apertura del file in scrittura" << endl;
		return false;
	}
	
	file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
	
	file << "w = [ ";
	for(unsigned int i = 0; i < n; i++)
	{
		file << fixed << setprecision(2) << w[i] << " ";
	}
	file << "]" << endl;
	
	file << "r = [ ";
	for(unsigned int i = 0; i < n; i++)
		file << fixed << setprecision(2) << r[i] << " ";
	file << "]" << endl;
	
	file << "Rate of return of the portfolio: " << setprecision(4) << rateReturn << endl;
	
	file << "V: " << fixed << setprecision(2) << V << endl;
	
	file.close();
	
	return true;
}


string ArrayToString(const size_t& n,
					 const double* const& v)
{
	string str;
    ostringstream toString;
    toString << fixed << setprecision(2) << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";
	
	return toString.str();
}