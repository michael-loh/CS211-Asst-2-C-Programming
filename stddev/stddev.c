#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMean(double* list, int size){
	
	double sum = 0;
	int i = 0;
	for(i = 0; i < size; i++){
		sum += list[i];
	}
	
	double mean = sum/i;
	int flr = floor(mean); 
	int cl = ceil(mean);
	if(mean - flr < 0.5){
		return flr;
	}
	return cl;
}

int getStddev(double* list, int mean, int size){

	double* list2;
	list2 = (double*)malloc(20000*sizeof(double));
	
	int i = 0;
	int temp;
	double stdMean = 0;
	for(i = 0; i < size; i++){
		temp = list[i]-mean;
		list2[i] = temp * temp;
		temp = 0;
		
		stdMean += list2[i];
	}
	stdMean = stdMean/i;
	double stddev = sqrt(stdMean);
	int flr = floor(stddev);
	int cl = ceil(stddev);
	
	if(stddev - flr < 0.5){
		return flr;
	}
	return cl;	

}



int main(){

	double d;
	double* list;
	list = (double*)malloc(20000*sizeof(double));
	int i = 0;
	while(1){
		if(scanf("%lf", &d) == 0){
			break;
		} 
		if(d == -909){
			break;
		}	
		list[i] = d;
		i++;
		d = -909;
	}

	if(i == 0){
		printf("no data\n");
		return 0;
	}
	
	int mean;
	mean =  getMean(list, i);
	int stddev = getStddev(list, mean, i);
	
	printf("mean: %d\n", mean);
	printf("stddev: %d\n", stddev);

	return 0;

}













