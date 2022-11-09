/*
* File: 05554_75554_22607_PAC4_PEC4_CAA4_20211_main.c
* Author: UOC
* Course: 20211
* Description: PAC4-PEC4-CAA4
*/

/* System header files */
#include <stdio.h>
#include <stdbool.h>

/* Global constants */
#define MIN_COWORKCENTERS 1        //Min. cowork centers
#define MAX_COWORKCENTERS 5        //Max. cowork centers

#define MAX_DISTANCE 5.0           //Max. acceptable distance

#define MAX_PRICE 100.0            //Max. acceptable price

/* User defined types */
typedef enum { STARTUPS = 1, FREELANCERS, RURAL, SPECIALIZED, GENERALIST } tCoworkingType;

/* Main function */
int main(int argc, char **argv) {
    /* Variable definition */
    int coworkCenterIdVector[MAX_COWORKCENTERS];               //vector of cowork centers id's
    tCoworkingType coworkTypeVector[MAX_COWORKCENTERS];        //vector of cowork centers types
    float priceVector[MAX_COWORKCENTERS];                      //vector of cowork centers prices
    float distanceFromCityCenterVector[MAX_COWORKCENTERS];     //vector of cowork centers distances from city center
    bool hasKitchenVector[MAX_COWORKCENTERS];                  //vector of cowork centers has kitchen property
        
    int numCoworkCenters;                                      //num of cowork centers
    tCoworkingType coworkType;                                 //center cowork type
    bool isAcceptable;                                         //aux. boolean variable
    int acceptableCoworkCentersVector[MAX_COWORKCENTERS];    //vector of acceptable cowork centers
    int numAcceptableCoworkCenters;                            //num of acceptable cowork centers
    
    int i;                                                     //aux. idex variable
    int intToBool;                                             //aux. cast variable
    
    /* Data Input */
    /* Exercise 2.1 */
    printf("INPUT DATA\n");
    printf("NUMBER OF COWORK CENTERS ? (1-5) >>\n");
    scanf("%d", &numCoworkCenters);
    while(numCoworkCenters < MIN_COWORKCENTERS || numCoworkCenters > MAX_COWORKCENTERS){
        printf("INVALID DATA, TRY AGAIN!\n");
        printf("NUMBER OF COWORK CENTERS ? (1-5) >>\n");
		scanf("%d", &numCoworkCenters);
	}    
	
    /* Data Input */
	/* Exercise 2.2 */
	for(i = 0; i < numCoworkCenters; i++){
	    printf("CENTER #%d\n", i+1);
        printf("ID? (AN INTEGER) >>\n");
        scanf("%d", &coworkCenterIdVector[i]);
        printf("TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
        scanf("%u", &coworkTypeVector[i]);
        printf("PRICE [EUR]? (A REAL) >>\n");
        scanf("%f", &priceVector[i]);
        printf("DISTANCE FROM CITY CENTER [KM]? (A REAL) >>\n");
        scanf("%f", &distanceFromCityCenterVector[i]);
        printf("HAS KITCHEN? (0-FALSE, 1-TRUE) >>\n");
        scanf("%d", &intToBool);
        hasKitchenVector[i] = intToBool;      
	}
    
	/* Data Input */
    /* Exercise 2.3 */
    printf("LOOKING FOR CENTERS\n");
    printf("TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
    scanf("%u", &coworkType);
     
    /* Data Processing */
    /* Exercise 2.4 */
	isAcceptable = false;
	numAcceptableCoworkCenters = 0;
	for(i = 0; i < numCoworkCenters; i++){
        isAcceptable = coworkTypeVector[i] == coworkType && distanceFromCityCenterVector[i] < MAX_DISTANCE && priceVector[i] <= MAX_PRICE && hasKitchenVector[i];
        if (isAcceptable){
            acceptableCoworkCentersVector[numAcceptableCoworkCenters] = coworkCenterIdVector[i];
		    numAcceptableCoworkCenters = numAcceptableCoworkCenters + 1;
		}
	}

    /* Data Output */
    /* Exercise 2.5 */
	printf("RESULTS\n");
	if (numAcceptableCoworkCenters > 0){
		 printf("NUMBER OF ACCEPTABLE CENTERS: %d\n", numAcceptableCoworkCenters);
		 for(i = 0; i < numAcceptableCoworkCenters; i++){
		 	printf("CENTER ID: %d\n", acceptableCoworkCentersVector[i]);
		 }
	} else {
	    printf("THERE ARE NO ACCEPTABLE CENTERS.\n");	
	}

return 0;
}
