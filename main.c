/* Assignment 3, Covid-19 social distancing effect simulation
 * The main aim of this assigment is getting familiar with dynamic arrays and heap management. 
 *  
 *  Please write your name and Student ID as comment below.
 *  Name and Surname: Tuna Onal            Student ID: 72024
 */

#include <stdio.h>
#include <stdlib.h>

//These are global variables which will be printed at the end of the project
int total_infection = 0;
int total_death = 0;
int total_recover = 0;
int max_active = 0;

//This is the struct for patients s = status:healthy,covid,dead
//x,y = coordinates
//sd = sick day
typedef struct {

int x;
int y;
int s;
int sd;

} Patient;

//This function creates a dynamic grid world by setting coordinates
//and at the beggining no one has covid
Patient** startWorld(int size) {
	int i;
	int j;
	int a;
	int b;
	Patient **world = (Patient**)malloc(size*sizeof(Patient*));

	for(i = 0; i < size; i++) {
		world[i] = (Patient*)malloc(sizeof(Patient)*size);
	}

	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			world[j][i].sd = 0;	
			world[j][i].s = 0;
			world[j][i].x = j;
			world[j][i].y = i;
	
		}	
	}

	return world;
}
//This function sets %5 of the people (randomly) as infected
void initialize(Patient** array, int size, int seed) {

	int i;
	int j;
	int a;
	int b;
	int num;	
	num = ((size*size)*5)/100;
	int arr[num];
	int arr2[num];
	
	srand(seed);	

	for(i = 0; i < num; i++) {
		arr[i] = (rand() % size);
	
	}
	for(i = 0; i < num; i ++) {
		arr2[i] =  rand() % size;
	}
	
	for(i = 0; i < num;  i++) {
		
		a = arr[i];
		b = arr2[i];	
		array[a][b].s = 1;

	}	
}
//This function is implemented in order to find the maximum number of active cases
//This function will be called after every change in the grid world
int maxCase(Patient** array,int size) {
	int i;
	int j;
	int max;
	max = 0;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			if(array[j][i].s == 1) {
				max++;
			}
		}
	}
	return max;
}
//This function iterates over the grid world for simulatin length and makes operations which are needen 
void cycle(int length, Patient** array,int infection, int size, int seed ){
	int i;
	int j;
	int k;
	int maxx;
	FILE *f;
	char name[150];
	
	char a = (char)'1';
	char b = (char)'0';
	char c = (char)'*';
	char d = (char)' ';
	char e = (char)'\n';
	

	srand(seed);

	maxx = maxCase(array,size);
	max_active = maxx;
	

	for(i = 0; i < length; i++) {
		for(j = 0; j < size; j++){
			for(k = 0; k < size; k++){
			
			if(array[k][j].sd == 4 && (rand() % 100) < 3) {
				array[k][j].s = 2;
				array[k][j].sd = 0;
				total_death++;
				maxx = maxCase(array,size);
				if(maxx > max_active) {
					max_active = maxx;
				}
				
			}
			if(array[k][j].sd == 4 && (rand() % 100) >= 3) {
				array[k][j].s = 0;
				array[k][j].sd = 0;
				total_recover++;
				maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
			}
			//right up
			if(array[k][j].s == 1 && array[k][j].x != size-1 && array[k][j].y != 0 && (rand() % 100) < infection){
				if(array[k+1][j-1].s == 0){
					array[k+1][j-1].s = 1;
                                        total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
                                }	
			}
			//left down
			if(array[k][j].s == 1 && array[k][j].x != 0 && array[k][j].y != size-1 && (rand() % 100) < infection) {
				if(array[k-1][j+1].s == 0){
					array[k-1][j+1].s = 1;
					total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
				}
			}
			//right down
			if(array[k][j].s == 1 && array[k][j].x != size-1 && array[j][k].y != size-1 && (rand() % 100) < infection){
		
			if(array[k+1][j+1].s == 0){
					array[k+1][j+1].s = 1;
                                        total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
                                }	
			}
			//left up
			if(array[k][j].s == 1 && array[k][j].x != 0 && array[k][j].y != 0 && (rand() % 100) < infection) {
				if(array[k-1][j-1].s == 0){
					array[k-1][j-1].s = 1;
                                        total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
                                }
				
			}
			//right
			if(array[k][j].s == 1 && array[k][j].x != size-1 && (rand() % 100) < infection) {
				if(array[k+1][j].s == 0){
                                        array[k+1][j].s = 1;
					total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
                                }
			}
			//left
			if(array[k][j].s == 1 && array[k][j].x != 0  && (rand() % 100) < infection) {
				
				if(array[k-1][j].s == 0){
					array[k-1][j].s =1;
                                        total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
                                }
			}
			//up
			if(array[k][j].s == 1 && array[k][j].y != 0 && (rand() % 100) < infection) {
				
				if(array[k][j-1].s == 0){
                                        array[k][j-1].s = 1;
					total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
                                }
			}
			//down
			if(array[k][j].s == 1 && array[k][j].y != size-1 && (rand() % 100) < infection) {
				if(array[k][j+1].s == 0) {
					array[k][j+1].s = 1;
					total_infection++;
					maxx = maxCase(array,size);
                                if(maxx > max_active) {
                                        max_active = maxx;
                                }
				}
			} 
		}
	}
		snprintf(name,sizeof(name),"CYCLENUM%d.txt",i);
                f = fopen(name,"w");
                for(j = 0; j < size; j++) {
                        for(k = 0; k < size; k++) {
                                if(array[k][j].s == 1) {
                                        fputc(a,f);
                                        fputc(d,f);


                                } else if(array[k][j].s == 0) {
                                        fputc(b,f);
                                        fputc(d,f);

                                } else if(array[k][j].s == 2) {
                                        fputc(c,f);
                                        fputc(d,f);
                                }
                        }

                        fputc(e,f);
                }
                fclose(f);
		

		for(j = 0; j < size; j++){
                for(k = 0; k < size; k++) {
                        if(array[k][j].s == 1) {
                                array[k][j].sd++;
                        }
                }
  	}      
                      


    }
	
}

int main( int argc, char *argv[] )  {
	int size = atoi(argv[1]);
	int iac = ((size*size)*5)/100;
	int infection_chance = 100 - atoi(argv[2]);
	int length = atoi(argv[3]);
	int seed = atoi(argv[4]);
	int i;
	int j;

	Patient **grid = startWorld(size);
	initialize(grid,size,seed);
	cycle(length,grid,infection_chance,size,seed);
	
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++){
			printf("%d ",grid[j][i].s);
			//printf("(%d,%d)",grid[j][i].x,grid[j][i].y);
			
		}	
		printf("\n");
	}

	printf("total infection: %d \n",total_infection);
	printf("total deaths: %d \n",total_death);
	printf("total recovery: %d \n",total_recover);
	printf("maximum active cases: %d \n", max_active);

	for(i = 0; i < size; i++) {
		free(grid[i]);
	}
	free(grid);

   /*printf("Program name %s\n", argv[0]);
 
   if( argc == 5 ) {
	printf("The first argument supplied is %d\n", atoi(argv[1]));
	printf("The second argument supplied is %d\n", atoi(argv[2]));
  	printf("The third argument supplied is %d\n", atoi(argv[3]));
	printf("The forth argument supplied is %d\n", atoi(argv[4]));
   }
   else if( argc > 5 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("Expected 4 arguments but only %d argument passed.\n", argc-1);
   }
     */
       return 0;	
}
