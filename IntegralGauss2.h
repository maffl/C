#pragma once

class IntegralGauss2 :
	public Integral
{
private:
	BazisScal *bazis;
	double (*ClassFunc)(double x, double y, double z, int t);
	double funcForIntegral(double x, double y, double z, int t); 
	int lokNum, numElem;
public:
	IntegralGauss2(void){x1 = 0.5773503; q1 = 1;};
	~IntegralGauss2(void){};
	void initBazis(BazisScal *bazis);
	void initFun(double func(double x, double y, double z));
	void initFun(double func(double x, double y, double z, int i));
	double int3DBazis(int numElem, int lokNum, int t);
	virtual double int1D(double y = 0, double z = 0, int t = 0);
	virtual double int2D(double z = 0, int t = 0);
	virtual double int3D(int t = 0);
};
