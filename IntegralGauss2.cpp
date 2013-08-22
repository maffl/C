#include "StdAfx.h"


void IntegralGauss2 :: initBazis(BazisScal *$bazis)
{
	bazis = $bazis;
}
void IntegralGauss2::initFun(double (*func)(double x, double y, double z))
{
	//ClassFunc = func;
}
void IntegralGauss2::initFun(double (*func)(double x, double y, double z, int i))
{
	ClassFunc = func;
}
double IntegralGauss2::funcForIntegral(double x, double y, double z, int t)
{
	double f = ClassFunc(x, y, z, t);
	f *= bazis->psi(lokNum, numElem, x, y, z);
	return f;
}
double IntegralGauss2::int3DBazis(int $numElem, int $lokNum, int $t)
{
	lokNum = $lokNum;
	numElem = $numElem;

	double x0 = bazis->getXbeg(numElem);
	double x1 = bazis->getXend(numElem);
	double y0 = bazis->getYbeg(numElem);
	double y1 = bazis->getYend(numElem);
	double z0 = bazis->getZbeg(numElem);
	double z1 = bazis->getZend(numElem);


	init(x0, x1, y0, y1, z0, z1);
	
	return int3D($t);}
double IntegralGauss2::int1D(double y, double z, int t)
{
	return hx / 2. * (q1 * (funcForIntegral(X[0], y, z, t) + funcForIntegral(X[2], y, z, t))); 
}
double IntegralGauss2::int2D(double z, int t)
{
	return hy / 2. * (q1 * (int1D(Y[0], z, t) + int1D(Y[2], z, t))); 
}

double IntegralGauss2::int3D(int t)
{
	return hz / 2. * (q1 * (int2D(Z[0], t) + int2D(Z[2], t)));
}