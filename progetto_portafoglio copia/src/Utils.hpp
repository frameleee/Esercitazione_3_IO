#pragma once
#include <string>

bool ImportVectors(const std::string& inputFilePath,
                   double& S,
                   size_t& n,
                   double*& w,
                   double*& r);

double RateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);

bool ExportResult(const std::string& outputFilePath,
                  double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateReturn,
                  const double& V);

std::string ArrayToString(const size_t& n,
                          const double* const& v);
