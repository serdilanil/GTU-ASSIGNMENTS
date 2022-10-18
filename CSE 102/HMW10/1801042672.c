#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct Point{  //I created a point structure for x and y values of a point.

	char Pname[20]; //I created a name array for the point structure.
	float point_x;   //I would create these float values for the x and y coordinates of the point.
	float point_y;
};

struct Lines{  //I created a line structure to find the line between two points.

	char Lname[20];  //I created a array for the line.
	struct Point* p1;  //here I defined two points using nested structure
	struct Point* p2;

};

struct Poly{   //I created a polygon structure here.

	char Poname[20]; //I created a array for the polygon.
	int corners[20];  // I created a 20-point array for the corners of the polygon to have a maximum of 20 particles.

};


int main(){
	char buf[100];		 //I created 100 character array for the file.					
	int counter=0,i,k=2,x=1,y=2,count,j;
	
		FILE *fptr;

		fptr = fopen("outputs.txt","w");   //I open for the write the file that I will process here.


	FILE *fp;
	fp = fopen("commands.txt","r");  //I open for the read the file that I will process here.
	char buffer[100],*token,Pname[20],Lname[20];
	double point1,point2,point_x,point_y;
	struct Point s[50];
	struct Lines s2[50];
	struct Poly corners[20];
	char point3[50],point4[50],point5[50],point6[50],point7[50],point8[50],distance[50],p_1[20],p_2[20],angle[20],l_1[20],l_2[20],length[20],pol[20];
		
		while(fgets(buffer,sizeof(buffer),fp) != NULL){  //here I use the fgets function to read line by line to the end of the file.
		
			token = strtok(buffer,"//");  //here i use strtok function to ignore comment lines and after.


				if(strncmp(buffer,"data",4) == 0 ){  //if i see the word data I stop then i will print the number value.

					fgets(buffer,sizeof(buffer),fp); //I go down one line and get the number value.
						
						counter = atoi(buffer);		//I convert the int value.		
					
						for(i=0;i<counter;i++){  //I perform as many numerical values as I translate.


						if(buffer[0] == 'P' || buffer[6] == 'L' && buffer[9] == '\0'){  //here, when reading the lines one by one, I distinguish whether they are dots, lines or polygons according to their initials.
						
							fgets(buffer,sizeof(buffer),fp);  //I go down one line and get the number value.

							sscanf(buffer,"%s %s %s",point3,point4,s2[0].Lname);  //here I take the values in the line separately.
							
									

						}	
							
							else if(buffer[0] == 'L' && buffer[0] == 'L' || buffer[13] == 'G'){	 //here, when reading the lines one by one, I distinguish whether they are dots, lines or polygons according to their initials.
						
 
								fgets(buffer,sizeof(buffer),fp);   //I go down one line and get the number value.

								sscanf(buffer,"%s %s %s %s",point5,point6,point7,point8);  //here, when reading the lines one by one, I distinguish whether they are dots, lines or polygons according to their initials.
							
							}	
								
								else{
									
									fgets(buffer,sizeof(buffer),fp);  //If the lines do not start with letters, it means that the dots have coordinate values.
									
									sscanf(buffer,"%lf %lf %s",&point1,&point2,s[0].Pname);
									
									s[0].point_x = point1;  //here I save the coordinates of the points to the arrays.
									s[0].point_y = point2;

									s2[0].p1 = s;

									s[1].point_x = point1;
									s[1].point_y = point2;

									s2[0].p2 = s; 

									//printf("\n\nname:%s %.1lf %.1lf\n",s->Pname,s2->p1->point_x,s2->p1->point_y);
								}

					}
				}
		
									if(strncmp(buffer,"actions",7) == 0 ){   //If I see the word actions here, I switch to the numerical value below it.

										fgets(buffer,sizeof(buffer),fp);
										fgets(buffer,sizeof(buffer),fp);

										count = atoi(buffer);

										for(j=0;j<count;j++){

											if(buffer[0] == 'D'){  //if the line starts with the letter 'D' means the distance between the two points will be found.

												fgets(buffer,sizeof(buffer),fp);

												sscanf(buffer,"%s %s %s",distance,p_1,p_2);
											

											}

												else if(buffer[0] == 'A'){  //If the initial letter starts with the letter 'A', it means that the Angle will be found.

													fgets(buffer,sizeof(buffer),fp);

													sscanf(buffer,"%s %s %s",angle,l_1,l_2);

												}

													else if(buffer[0] == 'L'){   //if the initial letter starts with the letter 'L', it will find length

														fgets(buffer,sizeof(buffer),fp);

														sscanf(buffer,"%s %s",length,pol);
													}

										
														else if(buffer[1] == 'r'){  //If the second letter will start with the letter 'r', it means that the area will be found.

															fgets(buffer,sizeof(buffer),fp);

															sscanf(buffer,"%s %s",length,pol);

														}

										}

									}


		}
		
		fclose(fp);
							
								//fprintf(fptr,"asfas");

								fclose(fptr);


	return 0;
}


