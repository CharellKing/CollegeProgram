#ifndef _MyStat_H_
#define _MyStat_H_

const int M = 100;

void Input(double *p, int &n);//input an array of real number;

void Output(const double *p, int n);//output an array of real number;

void  Round(double &anumber, char afterpoint); // Resever the real number

void Stat(const double *p, int n, double &sum, double &max, double &min, double &avg);//stat number

int Find(const double *p, int n, double x);//search for a number

void Sort(double *p, int n);//sort from min to max

void Swap(double &x, double &y);// exchange

#endif