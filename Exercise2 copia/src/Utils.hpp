#pragma once
#include <iostream>

using namespace std;

// ImportVectors legge in input i vettori dal file
// S: somma totale investita
// n: numero di assets
// r: risultato del tasso di rendimento dell'i-esimo asset
// w: frazione di S investita nell'i-esimo asset
bool ImportVectors(const string& inputFilePath,
				   double& S,
				   size_t& n,
				   double*& w,
				   double*& r);
				   

// RateOfReturn restituisce il tasso di rendimento totale, che è uguale a S*r, cioè alla somma degli n valori di w moltiplicato per r
// S: somma totale investita
// n: numero di assets
// r: risultato del tasso di rendimento dell'i-esimo asset
// w: frazione di S investita nell'i-esimo asset	   
double RateOfReturn(const size_t& n,
					const double* const& w,
					const double* const& r);
							 
							 
// ExportResult esporta il risultato ottenuto in un file
// S: somma totale investita
// n: numero di assets
// r: risultato del tasso di rendimento dell'i-esimo asset
// w: frazione di S investita nell'i-esimo asset
// rateReturn: tasso di rendimento totale
// V: valore finale del portfolio, calcolato come (1+r)*S
bool ExportResult(const string& outputFilePath,
				  double& S,
				  const size_t& n,
				  const double* const& w,
				  const double* const& r,
				  const double& rateReturn,
				  const double& V);


// ArrayToString esporta un vettore in una stringa
// n: dimensione del vettore
// v: vettore
string ArrayToString(const size_t& n,
					 const double* const& v);
