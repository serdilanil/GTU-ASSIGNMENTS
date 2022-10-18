#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Hospital{   // I create the struct.

	char *name;     // Hospital name.
	char citiesServed[3];  //I record the cities served in this series.
};


int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,struct Hospital results[4]); //My purpose in this function is that the scope of service of the hospitals covers all the cities.

int main(){
	int i,j;
	char _cities[6] ={'A','B','C','D','E','F'};  // I assigning the cities.
	char _locations[4][3] =	{{"ACD"},{"BF"},{"CEF"},{"ABC"}};   // I assigning the hospital location.
	int _numHospitals;
	struct Hospital results[4]; // I record the cities that serve this series.



		printf("Enter the maximum number of hospitals that can be constructed:"); 
		scanf("%d",&_numHospitals);



			if(canOfferCovidCoverage(_cities,_locations,_numHospitals,results) == 1){  //I return 0 and 1 with recursion so I can find out if hospitals cover all cities.

				printf("\nYes, can offer health care to all!\n");  //If hospitals cover all cities, the function will return 1, if not, it will return 0.

					for(i=0;_locations[i][j] != '\0' && i<3;i++){   //here if the function returns 1, I print the regions to cover the whole city from the location array.
			
					printf("\nhospital-%d",i);
					
						printf("\nhospital locations:");

							for(j=0;_locations[i][j] != '\0' && j<3;j++){

								printf("%c",_locations[i][j]);

							}
				
								printf("\n");
						}
			
				}
		
						else{   // if hospitals don't cover the cities.

							printf("\nNo,some cities are not covered.\n");
						}					

			return 0;
}


int i=0;
int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,struct Hospital results[4]){


		if(_numHospitals == 0 || _numHospitals == 1 || _numHospitals == 2){  // base cases
			
			return 0;  					// if user 1,2 or 0 function will return 0.
		}
			
				else if(_numHospitals >= 3){ // If the user enters a number greater than 3, the function will return 1.

					strcpy(results[i].citiesServed,_locations[i]); // In this function I am throwing elements to the struct array.
					
					i++;
				
						if(i == 4){  //I kept the counter up to 4 since the most elements would be 3 and the probe would have a null character.
						
							return 1;
						}

								else{
									
									canOfferCovidCoverage(_cities,_locations,_numHospitals,results);   // recursive function
								}
	
				}

}