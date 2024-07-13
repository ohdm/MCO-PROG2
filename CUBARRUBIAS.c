/*
	CCPROG2 MP3 SOURCE CODE

    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1: CUBARRUBIAS, DION MEL                            SECTION1: S13
    
    
    DATE SUBMITTED     : 25/11/2023
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	DO NOT run your a.exe with input/output redirection anymore because MP3 is
   already supposed to be on text file processing.
   
   You should run your a.exe file simply as follows:
      Example: a 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include your own header file
#include "CUBARRUBIAS.h"   

/* Do NOT include other header files. */ 

/* 
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
	1. You must apply struct data type, and text file processing MP Part 3 (MP3).
       a. Re-use the contents of your header file LASTNAME1_LASTNAME2.h.
       b. Follow the same hard requirements in MP2 on struct data type, and structure access using 
          * and ., and -> operators.
   2. Data should be read from SoGA_DATASET.txt using fscanf().
   3. The main() function should call the appropriate C function, and then call fprintf() to 
      write the answer to each question onto the OUTPUT_LASTNAME1_LASTNAME2.txt file. Numeric 
      answers with double data type must be written with 6 digits after the decimal point.  
   4. There should NOT be any printf() and scanf() statement in the entire source code, 
      not even in main(), and in the function that reads the SoGA data text file.  
   5. Document your codes with SENSIBLE comments.
   6.Use double data type (not float) for all floating point values/variables/functions/return type.
   7. Do NOT use any global variables.
   8. Do NOT use library functions that were NOT discussed in our class.
*/



/*
    ALL typedef declarations must be encoded in your header file.  
    All #define must be encoded in your header file.
    Do NOT place them in this file.
*/

int init(ID DATASET[]){
	ID temp; //temp val for scanf
	int ctr;
	FILE *fp; //file pointer declaration
	
	fp = fopen(FILE_DATA,  "r"); // read mode opening of data directed to the file pointer declaration
	if ( fp != NULL ) { //null points to 0 pointer 
 	
 	
   	while ( fscanf(fp, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
				temp.TERRITORY, &temp.baseline, &temp.airpollution, &temp.ambientpm, &temp.ozone,
				&temp.hap, &temp.envir_occup, &temp.occupational, &temp.unsafewash, &temp.metabolic, &temp.dietary, 
				&temp.plasmaglucose, &temp.tobacco, &temp.smoking, &temp.secondhandsmoke, &temp.unsafesex) ==  16) {
						
         		DATASET[ctr] = temp; // structure to structure assignment
      	        ctr++; //inputs for SOGA DATASET
        }
        fclose(fp); //close filepointer
   }
   
   else { // false: file does NOT exist
       fprintf(stderr, "### Fatal Error: file %s does not exist! Terminating...\n", 
               FILE_DATA);
       exit(1); 
   }
   

   return ctr; // number of rows of student data	
}

/*
    Define any function that you need below this comment.  

    For functions that serve as answers to the questions, include the following as comments
    BEFORE the function definition itself:
       a. Question number, and the actual question.
       b. Thereafter, type the answer number, and the corresponding expected answer.
    
    For example: 
      Q1:  Which country has the lowest baseline life expectancy?
      A1:  Lesotho

    The following should be included as comments and appear BEFORE each function definition:
       a. Purpose: describe succintly what the function is supposed to accomplish.
       b. Parameters: describe succintly the nature/purpose of each parameter.
       c. Return type: if the function is not void, describe succintly what it will return as a result.          
       
    Document the body of the function by including comments alongside codes that you think
    may not be easy to understand to the person reading the codes. 
*/

void copyArr(ID PASTE[], ID COPY[],  int ctr){
	int i;
	
		for(i = 0; i < ctr ; i++){
		PASTE[i] = COPY[i];
	}
}


      
     //Q1. How many territories have a baseline life expectancy of atleast <parameter_number>? display the total amount. [count]
	//A1.  inp>69.384500 ...  out>142 

int findBaseline(double BASE, ID DATA[], int ctr){  //this works dont change anything
	int i; 
	int VAL = 0;
	
	for( i= 1 ; i < ctr ; i++ ){ //  i = 1 since 0 contains the values of GLOBAL
			if(DATA[i].baseline>=BASE)
			VAL++;
	}
	return VAL;
}

//Q2. Which territory has the highest average loss of life expectancy do to air pollution, display the territory, and the corresponding value. [maximum]
//A2. The highest loss of life average because of air pollution is Solomon_Islands with an value of 3.493186
int findAirpol(ID DATA[], int ctr){
	int i;
	double temp = 0; //initialize first term
	int tempname; //stores index
	
	for(i = 1; i < 203; i++){
			if(temp< DATA[i].airpollution){
			temp = DATA[i].airpollution;
			tempname = i; //stores index of highest avg airpol
			}
		}
	return tempname;
}

//Q3. Which are the territories with the highest base line life expectancy, list the top 10, in highest to lowest order basing from the data. [ sort ]
/*A3.
84.565300       Singapore
84.557851       Japan
83.891722       Iceland
83.863622       Switzerland
83.032133       Italy
83.012277       Spain
82.902047       Israel
82.829180       Norway
82.826250       South_Korea
82.798953       Luxembourg 
*/
void findHighest(ID temp[], int ctr ){ //sorting function
	int i, j;
	int min; double tempdbl;
	str50 tempstr;
	
		for(i=1; i < ctr-1; i++){
			min = i;
			
			for(j = i + 1; j < ctr; j++)
				if(temp[min].baseline<temp[j].baseline)
					min = j;
					
			if(i != min) {
				strcpy(tempstr, temp[i].TERRITORY);
				strcpy(temp[i].TERRITORY, temp[min].TERRITORY);
				strcpy(temp[min].TERRITORY, tempstr);
				
				tempdbl = temp[i].baseline;
				temp[i].baseline = temp[min].baseline;
				temp[min].baseline = tempdbl;
			}
		}	
}
//Q4. Which are the top <parameter_number> territories with lowest loss of life expectancy due to their dietary lifestyle. [minimum]
/* A4 inp> 15
0.658272        Lesotho
0.835782        Central_African_Republic
0.860514        Equatorial_Guinea
0.869998        South_Sudan
0.871374        Nigeria
0.872697        Kenya
0.874694        Uganda
0.882492        Cameroon
0.891131        Rwanda
0.909270        Guinea
0.949050        Israel
0.965778        Spain
0.967169        Eswatini
0.967674        Niger
0.974864        Malawi
*/
void findDietary(ID DATA[], int ctr){ //sorting function
	int i, j;
	int min; double temp;
	str50 tempstr;
	
		for(i=1; i < ctr - 1; i++){
			min = i;
			
			for(j = i + 1; j < ctr; j++)
				if(DATA[min].dietary>DATA[j].dietary)
					min = j;
					
			if(i != min) {
				strcpy(tempstr, DATA[i].TERRITORY);
				strcpy(DATA[i].TERRITORY, DATA[min].TERRITORY);
				strcpy(DATA[min].TERRITORY, tempstr);
				
				temp = DATA[i].dietary;
				DATA[i].dietary = DATA[min].dietary;
				DATA[min].dietary = temp;
			}
		}	
}

//Q5. What is the top <parameter_number> territories in terms of loss of life expectancy due to smoking, and what the order is and loss of life for
// <parameter_territory_name>. 
/*A5 inp 15 && strinp Montenegro
3.533249        Kiribati
3.449449        Greenland
3.295599        Montenegro
2.995377        Lebanon
2.770872        Hungary
2.770141        Bosnia_and_Herzegovina
2.700904        Nauru
2.696803        Greece
2.665907        Bulgaria
2.629568        Solomon_Islands
2.602971        Serbia
2.570818        Micronesia
2.565326        Denmark

The country Montenegro is number 3 on the top 13 countries, and has an average LE of 3.295599.
*/
void sortSmoke(ID DATA[], int ctr){ //Sorting function, 
		int i, j;
	int min; double temp;
	str50 tempstr;
	
		for(i=1; i < 202; i++){
			min = i;
			
			for(j = i + 1; j < 203; j++)
				if(DATA[min].smoking<DATA[j].smoking)
					min = j;
					
			if(i != min) {
				strcpy(tempstr, DATA[i].TERRITORY);
				strcpy(DATA[i].TERRITORY, DATA[min].TERRITORY);
				strcpy(DATA[min].TERRITORY, tempstr);
				
				temp = DATA[i].smoking;
				DATA[i].smoking = DATA[min].smoking;
				DATA[min].smoking = temp;
			}
		}
}

int search(ID DATA[], str50 input_Q5, int ctr) //search function for Q5
{
	
	int i;
	for(i = 1; i < ctr; i++){
		if(strcmp(input_Q5, DATA[i].TERRITORY ) == 0)
		return i; //returns the index value from strcmp between userinp and the sorted data
	}
	return i; //returns i for no errors :)
} 



int
main()
{
    /* Declare your own local variables. Describe the purpose of your local variables. */
    ID DATASET[MAX]; //these will store the main DATA
    ID temp[MAX]; // used to alter data for sorting
    strcpy(DATASET[0].TERRITORY, "TEST");
    int ctr; // counter
    int rtrnVal_int;
    double rtrnVal_dbl;
    double BASE_LE = 69.384500;
    int param_numQ4 = 15;
    int param_numQ5 = 20;
    int i;
    str50 input_Q5 = "Kiribati";
    
    FILE *file_output; //declaring file pointer file_output
    
    file_output = fopen(OUTPUT, "w" ); //opening file_output, and creating a .txt file named "OUTPUT_CUBARRUBIAS.txt"
    
   ctr = init(DATASET); //initializing the dataset with fscanf, and returning ctr
    
    copyArr(temp, DATASET, ctr);

rtrnVal_int = findBaseline(BASE_LE, temp, ctr);
fprintf(file_output, "%d\n", rtrnVal_int);
   
rtrnVal_int = findAirpol(temp, ctr);
fprintf(file_output, "\nThe highest loss of life average because of air pollution is %s with an value of %lf\n\n", temp[rtrnVal_int].TERRITORY, temp[rtrnVal_int].airpollution);
   
findHighest(temp, ctr);

for(i = 1; i < 11; i++){
	fprintf(file_output, "%lf        %s\n", temp[i].baseline, temp[i].TERRITORY);
}

	copyArr(temp, DATASET, ctr);//reset values of temp
	findDietary(temp, ctr);
	
	fprintf(file_output, "\n\n\n");
	
	
for(i = 1; i < param_numQ4+1; i++){
	fprintf(file_output, "%lf        %s\n", temp[i].dietary, temp[i].TERRITORY);
}	
	
	copyArr(temp, DATASET, ctr);//reset values of temp
	sortSmoke(temp, ctr);
	
	fprintf(file_output, "\n\n\n");
	
for(i = 1; i < param_numQ5+1; i++){
	fprintf(file_output, "%lf        %s\n", temp[i].smoking, temp[i].TERRITORY);
}
	
rtrnVal_int = search(temp, input_Q5, ctr);

	fprintf(file_output, "\n\nThe country %s is number %d on the top %d countries, and has an average LE of %lf.",
	 temp[rtrnVal_int].TERRITORY, rtrnVal_int , param_numQ5 ,  temp[rtrnVal_int].smoking); //prints output for Q5
	
	fclose(file_output);
	return 0;
}
