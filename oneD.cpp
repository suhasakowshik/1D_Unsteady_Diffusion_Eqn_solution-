/*
The program solves 1D unsteady heat conduction equation. It uses Forward time and Central Space differencing i e., FTCS method.
FDM solution.

x are grid length of 1.28 units.

d= (alpha * deltat)/(deltaX^2) 

alpha = 1 (given)

N is grid length

Nt time length

output data is for the cases 0, 100, 500 and 1000 seconds

imort data in matlab, code is given to plot (file name PlotsGraph.m)
*/

#include<iostream>
#include<math.h>
#include<fstream>
#include <cstdlib>
using std::ofstream;
using std::endl;
using namespace std;
int main()
{
	double x, d, time, u[128] , pi, delE, sum, sumo, sumi,suml, l, b;
	double delta, deltat, deltax, delt;
	ofstream outdata;
	int N, Nt, i, alphaa, n , j;
	i = 0;
	x = 1;
	N = 127;
	Nt = 15005;
	double avgE[15006];
	time = 0.01;
	alphaa = 1;
	pi = 3.1416;
	sum = 0;
	delta = x / (N+1);
	deltat = 0.00001;
	deltax = delta;
	delt = deltat;
	double T[128];
	d = (alphaa * deltat) / (deltax * deltax);
	/* u[0] = 0; */
	sumi = 0;
	/*Initial Conditions*/
	outdata.open("data0.dat");
	for (int i = 0; i <= N; i++)
	{
		T[i] = sin(2 * pi * deltax);

		for (int n = 1; n <= 1; n++)
		{
			l = ((sin(2 * pi - n * pi) / (2 * pi - n * pi)) - (sin(2 * pi + n * pi) / (2 * pi + n * pi))) * sin(n * pi * deltax);
			sumi = sumi + l;
		}
		 /*cout << l << ""; */ 
		deltax = deltax + delta;
		u[i] = sumi;
		outdata << T[i] << " ";
	}
	outdata.close();
    sumo = 0;
	for (int i = 0; i <= (N - 1); i++)
	{
		sumo = sumo + (u[i] - T[i]);
	}
	avgE[0] = sumo / (N + 1);

	/* FDM and analytical equation solution*/
	suml = 0;
	for (int t = 1; t <= Nt; t ++)
	{ 
		
		for (int i = 1; i <= (N - 1); i = i + 1)
		{   
			/* analytical */
			for (int n = 1; n <= 1; n++)
			{
				l = ((sin(2 * pi - n * pi) / (2 * pi - n * pi)) - (sin(2 * pi + n * pi) / (2 * pi + n * pi))) * sin(n * pi * deltax) * exp(-1 * n *n * pi * pi * delt);
				suml = suml + l;
			} 
			deltax = deltax + delta;
			/* cout << suml << " "; */
			u[i] = suml;
			/* FDM */
			T[i] = T[i] + d * (T[i+1]-2*T[i]+T[i-1]);
		}
		/* periodic boundary condition */
		T[0] = T[N];

		delt = delt + deltat;

		/* average error calculation */
		sum = 0;
		for (int i = 0; i <= (N-1); i++)
		{
			sum = sum + (u[i] - T[i]);
		}
		delE = sum / (N + 1);
		avgE[t] = delE;

		/* Writing output file in the format .dat */

		if (t == 100)
		{
			outdata.open("data100.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i]<< " ";
			}
			outdata.close();
		}
		else if (t == 500)
		{
			outdata.open("data500.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i] << " ";
			}
			outdata.close();

		}
		else if (t == 1000)
		{
			outdata.open("data1000.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i]<<" ";
			}
			outdata.close();

		}

	}

	outdata.open("avgError.dat");
	for (int i = 0; i <= Nt; i = i + 1)
	{
		outdata << avgE[i] << " ";
	}
	outdata.close();
   
	
};