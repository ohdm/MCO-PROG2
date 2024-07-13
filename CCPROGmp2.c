#include "CUBARRUBIAS.h"

int init(IDset ID[]){ //initializes the SOGA dataset
	int ctr=0;
	IDset temp;
	
	while(scanf("%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
				temp.TERRITORY, &temp.baseline, &temp.airpollution, &temp.ambientpm, &temp.ozone,
				&temp.hap, &temp.envir_occup, &temp.occupational, &temp.unsafewash, &temp.metabolic, &temp.dietary, 
				&temp.plasmaglucose, &temp.tobacco, &temp.smoking, &temp.secondhandsmoke, &temp.unsafesex) ==16)
				{	
				ID[ctr] = temp;
				ctr++;
			}
		return ctr;		//ran with IO redirection
}	




void copyArr(IDset ID[], IDset tempstruct[],  int ctr){
	int i;
	
		for(i = 0; i < ctr ; i++){
		tempstruct[i] = ID[i];
	}
	
}


/*Q1 Which territory has the highest reduction in life expectancy due to
air pollution? Display the name of the territory and the corresponding
reduction in life expectancy.[Maximum]*/
int airPol(IDset ID[], int ctr){
	int i;
	int index =-1; //initialize
	double temp = 0; //assume 0 as smallest val
	 
	
	
		for(i = 1; i < ctr ; i++){
			if(temp<ID[i].airpollution){
			temp = ID[i].airpollution;
			index = i;
			}
		}
	return index;
};

/*Q2: What is the average baseline life expectancy across all territories?
Display the average.[Average]*/
double avgBaseline(IDset ID[], int ctr){
	int i;
	double acc = 0;
	
		for(i = 1; i < ctr-1; i++){ //starts at 1 as to not include global
			acc = acc + ID[i].baseline;
		}
		acc = acc/ctr-1;
		return acc;
};

/*Q3: Which are the top <parameter_number> territories with the highest
reduction in life expectancy due to Occupational Hazards? List the names
of the territories with the corresponding life expectancy reduction, starting from the
highest reduction value.[Sort]*/
void sortOcc(IDset tempstruct[], int ctr)
{
		int i,j;
	int min; double temp;
	Str50 tempstr;
	
		for(i=1; i < 202; i++){
			min = i;
			
			for(j = i + 1; j < 203; j++)
				if(tempstruct[min].occupational<tempstruct[j].occupational)
					min = j;
					
			if(i != min) {
				strcpy(tempstr, tempstruct[i].TERRITORY);
				strcpy(tempstruct[i].TERRITORY, tempstruct[min].TERRITORY);
				strcpy(tempstruct[min].TERRITORY, tempstr);
				
				temp = tempstruct[i].occupational;
				tempstruct[i].occupational = tempstruct[min].occupational;
				tempstruct[min].occupational = temp;
			}
		}
}

/*Q4: With basis from category LE due to Ambient PM, is there any country
that has a Life Expectancy of exactly <param-years>? [Binary]*/

int findAmbientPM(double key, IDset tempstruct[], int ctr){
	
int low = 0, high = ctr - 1, mid;
int found = 0;


while (!found && low <= high) {

	mid = low + (high - low)/2;
	
		if (key == tempstruct[mid].ambientpm) 
			found = 1;
			
		else if (key < tempstruct[mid].ambientpm) 
		high = mid - 1;
		
		else 
		low = mid + 1; 
		}
		if (found)
		return mid;
		
		
		else
		return mid;
	
	
	
	
}

void minambientsort(IDset tempstruct[], int ctr){
	
	int i,j;
	int min; double temp;
	Str50 tempstr;
	
		for(i=0; i < 202; i++){ //0 since global is included in sort
			min = i;
			
			for(j = i + 1; j < 203; j++)
				if(tempstruct[min].ambientpm>tempstruct[j].ambientpm)
					min = j;
					
			if(i != min) {
				strcpy(tempstr, tempstruct[i].TERRITORY);
				strcpy(tempstruct[i].TERRITORY, tempstruct[min].TERRITORY);
				strcpy(tempstruct[min].TERRITORY, tempstr);
				
				temp = tempstruct[i].ambientpm;
				tempstruct[i].ambientpm = tempstruct[min].ambientpm;
				tempstruct[min].ambientpm = temp;
			}
		}
}

/*Q5: Which are the top <param-num> territories with the lowest reduction in life
expectancy due to Second Hand Smoke? List the names of the territories with the 
corresponding life expectancy reduction starting from the lowest reduction
value. [minimum --> sort]*/
void minsortSmoke(IDset tempstruct[], int ctr){
	
	int i,j;
	int min; double temp;
	Str50 tempstr;
	
		for(i=1; i < 202; i++){
			min = i;
			
			for(j = i + 1; j < 203; j++)
				if(tempstruct[min].secondhandsmoke>tempstruct[j].secondhandsmoke)
					min = j;
					
			if(i != min) {
				strcpy(tempstr, tempstruct[i].TERRITORY);
				strcpy(tempstruct[i].TERRITORY, tempstruct[min].TERRITORY);
				strcpy(tempstruct[min].TERRITORY, tempstr);
				
				temp = tempstruct[i].secondhandsmoke;
				tempstruct[i].secondhandsmoke = tempstruct[min].secondhandsmoke;
				tempstruct[min].secondhandsmoke = temp;
			}
		}
}



int main(){
	
	int ctr=0;
	IDset ID[MAXNUM]; 
	IDset tempstruct[MAXNUM]; //stores values of ID
	IDset tempstruct2[MAXNUM]; //stores values of ID
	IDset tempstruct3[MAXNUM];
	int avgBout=-1; //intialize, assume -1 for error
	int indexambient = -1;
	double inputpm = 1.008760;
	double avgLE = 0;
	int i;

	
		ctr=init(ID);
		
		copyArr(ID, tempstruct, ctr); //stores values of initialized struct ID[]
		copyArr(ID, tempstruct2, ctr); //stores values of initialized struct ID[]
		copyArr(ID, tempstruct3, ctr); //stores the values of initialized struct ID[]
		//these will store sorted values 


	
	avgBout=airPol(tempstruct, ctr); //returns the index of of ID.TERRITORY for HIGHEST LE due to air pollution
	printf("%s    %lf \n\n", tempstruct[avgBout].TERRITORY, tempstruct[avgBout].airpollution); //prints result
	
	
	
	avgLE = avgBaseline(ID, ctr);
	printf("%lf\n\n", avgLE); // print test
	
	sortOcc(tempstruct, ctr);
	
	for(i = 1; i < 4; i ++){
		printf("%s    %lf\n",tempstruct[i].TERRITORY, tempstruct[i].occupational);
	}
	
	printf("\n\n\n");

minambientsort(tempstruct3, ctr); //sorts ambient for binary search
indexambient = findAmbientPM( inputpm,  tempstruct3, ctr); //will get the index 
printf("%lf  %s\n\n", tempstruct3[indexambient].ambientpm , tempstruct3[indexambient].TERRITORY);
	
	minsortSmoke(tempstruct2, ctr);
	
	for(i = 1; i < 5; i ++){ 
		printf("TOP %d %s    %lf\n",i ,tempstruct2[i].TERRITORY, tempstruct2[i].secondhandsmoke);
	}
	
	return 0;
}
