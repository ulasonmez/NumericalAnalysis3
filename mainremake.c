#include <stdio.h>
#include<math.h>
double fonksiyon(double x){
	double e = exp(1);
	return	((pow(e,(-0.5*x))) - (x) - 0.2);
}
double sonrakiadim(double ilk,double iki){
	return (ilk - ((fonksiyon(ilk)*(iki-ilk))/(fonksiyon(iki)-fonksiyon(ilk))));
}
int main(int argc, char *argv[]) {
	int iterasyon=1;
	float iki=2,ilk=1.8,gecicideger,durmanoktasi = 5* pow(10,-3);
	printf("#(iterasyon)\t\t\tkok\t\t\t\te\n");
	while(fabs(iki-ilk)>=durmanoktasi){
		gecicideger = iki;
		iki = sonrakiadim(iki,ilk);
		ilk = gecicideger;
		printf("\t%d\t\t\t%f\t\t\t%f\n",iterasyon,iki,fabs(iki-ilk));
		iterasyon++;
	}
	return 0;
}
