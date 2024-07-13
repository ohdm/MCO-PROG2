#include<stdio.h>
#include<string.h>

#define MAXNUM 999

typedef char Str50[51]; //typedef for string MAX 50 characters

struct DATASET{  //will store the datasets

	Str50 TERRITORY;
	double baseline;
	double airpollution;
	double ambientpm;
	double ozone;
	double hap;
	double envir_occup;
	double occupational;
	double unsafewash;
	double metabolic;
	double dietary;
	double plasmaglucose;
	double tobacco;
	double smoking;
	double secondhandsmoke;
	double unsafesex;
	
};

typedef struct DATASET IDset; //alies for the struct DATAset
