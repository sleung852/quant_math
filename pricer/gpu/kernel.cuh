//
// Created by Leung See Ho on 14/10/2023.
//

#ifndef QUANT_MATH_KERNEL_CUH
#define QUANT_MATH_KERNEL_CUH


void run_mc_cuda(double* ST, double S, double sigma, double rate, double T, int n,
                 int m, double* Zs);

void run_mc_cuda(double* ST, double S, double sigma, double rate, double T, int n,
                 int m);


#endif //QUANT_MATH_KERNEL_CUH
