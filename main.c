#include <stdio.h>
#include <stdlib.h>
#include<math.h>
float hata = 0.005;
double f(double x);
double hataDegeri(double a, double b);
double kokBulucu(double a,double b);
int main(int argc, char *argv[]) {
	int i=0;
	float ust=2,alt=1.8,kok;
	float temp;
	printf("#(iterasoyn)               kok                       e\n");
	while(1){
		temp = ust;
		ust = kokBulucu(ust,alt);
		alt = temp;
		printf("%d                        %f                 %f\n",i+1,ust,hataDegeri(ust,alt));
		i++;
		if(hataDegeri(ust,alt)<hata){
			break;
		}
	}
	return 0;
}
//fonksiyon degerini donduruyor
double f(double x){
	return	(exp(-0.5*(x)) - (x) - 0.2);
}
//a = n+1  b = n
//hata degerini ( e ) donduruyor
double hataDegeri(double a, double b){
	return fabs(a-b);
}
//a = n+1  b = n
//kiris metodu formulune gore yeni koku donduruyor
double kokBulucu(double a,double b){
	double yeniKok;
	yeniKok = a - ((f(a)*(b-a))/(f(b)-f(a)));
	return yeniKok;
}
