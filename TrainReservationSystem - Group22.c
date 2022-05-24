/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
    int num;
    int c=0;//used in main function
    int c2=0;// used in all function except displayError()
    int c3=0;// used in deleteReservation() and editReservation()
    int c4=0;// used in editReservation()
    int c5=0;//used in main function
    char id[2][100]={"tr2345","tr3452"};
    char name[1][100];
    char place[5][100]={"JohorBahru","Seremban","KualaLumpur","Ipoh","AlorSetar"};
    char departure[1][100];//store user depart place based on the number they chose. 
    char destination[1][100];//store user destination place based on the number they chose. 
    int dpplace[1];// user input depart place number.
    int dsplace[5];// user input destination place number.
    char date[1][100];
    char times[5][100]={"9.00am","12.00pm","3.00pm","6.00pm","8.00pm"};
    int time[1];// user input time number. 
    char timeChoose[1][100];//store user time based on the number they chose. 
    int totalSeat[1];
    double totalPrice[1];

void displayError(){
	printf("\nThe number you enter isn't in the option. Please try again\n");
}

void enterName(int c2){
	printf("\nEnter your first name only:\n");
	scanf("%s", name[c2]);
}

void chooseDepart(int c2){
	printf("\nChoose your departing station:\n");
    printf("\nEnter [0] for Johor Bahru\n");
	printf("\nEnter [1] for Seremban\n");
	printf("\nEnter [2] for Kuala Lumpur\n");
	printf("\nEnter [3] for Ipoh\n");
	printf("\nEnter [4] for Alor Setar\n");
	printf("\nEnter the number:\n");
    scanf("%d", &dpplace[c2]);
    if (dpplace[c2]==0||dpplace[c2]==1||dpplace[c2]==2||dpplace[c2]==3||dpplace[c2]==4){
        printf("\n");
    }
    else {
        displayError();
        chooseDepart(c2);
    }
}

void chooseDestination(int c2){
	printf("Choose your destination station:\n");
    printf("\nEnter [0] for Johor Bahru\n");
	printf("\nEnter [1] for Seremban\n");
	printf("\nEnter [2] for Kuala Lumpur\n");
	printf("\nEnter [3] for Ipoh\n");
	printf("\nEnter [4] for Alor Setar\n");
	printf("\nEnter the number:\n");
    scanf("%d", &dsplace[c2]);
    if (dsplace[c2]==0||dsplace[c2]==1||dsplace[c2]==2||dsplace[c2]==3||dsplace[c2]==4){
        printf("\n");
    }
    else {
        displayError();
        chooseDestination(c2);
    }
}

void departureDate(int c2){
	printf("\nEnter your departure date(example 13/5/2021):\n");
    scanf("%s", date[c2]);
}

void departureTime(int c2){
	printf("\nChoose your departure time:\n");
    printf("\nEnter [0] for 9.00am\n");
	printf("\nEnter [1] for 12.00pm\n");
	printf("\nEnter [2] for 3.00pm\n");
	printf("\nEnter [3] for 6.00pm\n");
	printf("\nEnter [4] for 8.00pm\n");
	printf("\nEnter the number:\n");
    scanf("%d", &time[c2]);
    strcpy(timeChoose[c2],times[time[c2]]);
    if (time[c2]==0||time[c2]==1||time[c2]==2||time[c2]==3||time[c2]==4){
        printf("\n");
    }
    else{
        displayError();
        departureTime(c2);
    }
}

void seatNumber(int c2){
	printf("\nNumber of seat:\n");
    scanf("%d", &totalSeat[c2]);
}

void sumPrice(int c2){
	if ((dpplace[c2]==0&&dsplace[c2]==1)||(dpplace[c2]==1&&dsplace[c2]==2)||(dpplace[c2]==2&&dsplace[c2]==3)||(dpplace[c2]==3&&dsplace[c2]==4)||(dpplace[c2]==4&&dsplace[c2]==3)||(dpplace[c2]==3&&dsplace[c2]==2)||(dpplace[c2]==2&&dsplace[c2]==1)||(dpplace[c2]==1&&dsplace[c2]==0)){
            	strcpy(departure[c2],place[dpplace[c2]]);
            	strcpy(destination[c2],place[dsplace[c2]]);
            	totalPrice[c2]=totalSeat[c2]*20;
        }
        else if ((dpplace[c2]==0&&dsplace[c2]==2)||(dpplace[c2]==1&&dsplace[c2]==3)||(dpplace[c2]==2&&dsplace[c2]==4)||(dpplace[c2]==4&&dsplace[c2]==2)||(dpplace[c2]==3&&dsplace[c2]==1)||(dpplace[c2]==2&&dsplace[c2]==0)){
        	    strcpy(departure[c2],place[dpplace[c2]]);
            	strcpy(destination[c2],place[dsplace[c2]]);
            	totalPrice[c2]=totalSeat[c2]*30;
        }
        else if ((dpplace[c2]==0&&dsplace[c2]==3)||(dpplace[c2]==1&&dsplace[c2]==4)||(dpplace[c2]==4&&dsplace[c2]==2)||(dpplace[c2]==3&&dsplace[c2]==0)){
        	    strcpy(departure[c2],place[dpplace[c2]]);
            	strcpy(destination[c2],place[dsplace[c2]]);
            	totalPrice[c2]=totalSeat[c2]*40;
        }
        else if ((dpplace[c2]==0&&dsplace[c2]==4)||(dpplace[c2]==4&&dsplace[c2]==0)){
        	    strcpy(departure[c2],place[dpplace[c2]]);
            	strcpy(destination[c2],place[dsplace[c2]]);
            	totalPrice[c2]=totalSeat[c2]*50;
        }
}

void deleteReservation(){
		    	printf("\n<== DELETE RESERVATION ==>\n");

        	    	printf("\nConfirm to delete? [0 for NO / 1 for YES]\n");
        	    	scanf("%d", &c3);
    			if (c3==1){
    				strcpy(name[c2],"");
    				strcpy(departure[c2],"");
    				strcpy(destination[c2],"");
    				strcpy(date[c2],"");
    				strcpy(timeChoose[c2],"");
    				totalSeat[c2]=0;
    				totalPrice[c2]=0;
    				c+=1;
    				c5=0;
    				printf("\nDelete Successful\n");
    			}
    			else if(c3==0){
    				deleteReservation();
    			}
    			else{
    				displayError();
            			deleteReservation();
    			}

        	
}

void editReservation(){
			printf("\n<== EDIT RESERVATION ==>\n");       	
        		printf("\nID: %s", id[c]); 
    			printf("\nNAME: %s", name[c2]);
    			printf("\nDEPARTURE PLACE: %s", departure[c2]);
    			printf("\nDESTINATION PLACE: %s", destination[c2]);
    			printf("\nDATE: %s", date[c2]);
    			printf("\nTIME: %s", timeChoose[c2]);
    			printf("\nTOTAL SEAT: %d", totalSeat[c2]);
    			printf("\nTOTAL PRICE(RM): %.2lf", totalPrice[c2]);
    			printf("\nChoose which one to edit:\n");
    			printf("\nEnter [0] for name");
    			printf("\nEnter [1] for departure place");
    			printf("\nEnter [2] for destination place");
    			printf("\nEnter [3] for departure date");
    			printf("\nEnter [4] for departure time");
    			printf("\nEnter [5] for total seat");
    			printf("\nEnter [6] for done edit");
    			printf("\nEnter the number:\n");
    			scanf("%d", &c3);
    			while (c3!=6){
        			if (c3==0){
        				enterName(c2);
        			}
        			else if (c3==1){
        				chooseDepart(c2);
        				sumPrice(c2);
        			}
        			else if (c3==2){
        				chooseDestination(c2);
        				sumPrice(c2);
        			}
        			else if (c3==3){
        				departureDate(c2);
        			}    
        			else if (c3==4){
        				departureTime(c2);
        			}    
        			else if (c3==5){
        				seatNumber(c2);
        			    	sumPrice(c2);
        			}
        			else if (c3<0||c3>6){
    					displayError();
    			    	}
    			    	printf("\nID: %s", id[c2]); 
        			printf("\nNAME: %s", name[c2]);
        			printf("\nDEPARTURE PLACE: %s", departure[c2]);
        			printf("\nDESTINATION PLACE: %s", destination[c2]);
        			printf("\nDATE: %s", date[c2]);
        			printf("\nTIME: %s", timeChoose[c2]);
        			printf("\nTOTAL SEAT: %d", totalSeat[c2]);
        			printf("\nTOTAL PRICE(RM): %.2lf", totalPrice[c2]);
    			    	printf("\nChoose which one to edit:\n");
		    		printf("\nEnter [0] for name");
		    		printf("\nEnter [1] for departure place");
		    		printf("\nEnter [2] for destination place");
		    		printf("\nEnter [3] for departure date");
		    		printf("\nEnter [4] for departure time");
		    		printf("\nEnter [5] for total seat");
		    		printf("\nEnter [6] for done edit");
		    		printf("\nEnter the number:\n");
		    		scanf("%d", &c3);
	    		}
	    		printf("\nConfirm to save the edit? [0 for NO / 1 for YES]\n");
	    		scanf("%d", &c4);
	    		if (c4==1){
	    			printf("\nEdit Successful\n");
	    		}
	    		else if(c4==0){
	    			editReservation();//you need to start from choosing the id
	    		}
	    		else {
	    			displayError();
		    		editReservation();//you need to start from choosing the id
	    		}
    			 

}

int main()
{
    while (num!=4){
        printf("\n<============================>\n");
        printf("<==TRAIN RESERVATION SYSTEM==>\n");
        printf("<============================>\n");
        printf("\nEnter [1] for New Reservation\n");
        printf("Enter [2] for Delete Reservation\n");
        printf("Enter [3] for Edit Reservation\n");
        printf("Enter [4] for Exit the System\n");
        printf("\nEnter the number:\n");
        scanf("%d", &num);
        if (num==1){
        	c2=c;
        	if (c>1){
        	    c=0;
        	}
        	if (c5<1){
        	    
        	    printf("\n<== NEW RESERVATION ==>\n");
    		    printf("Reservation ID:%s\n", id[c]);
    		    enterName(c2);
    		    chooseDepart(c2);
    		    chooseDestination(c2);
    		    departureDate(c2);
    		    departureTime(c2);
    		    seatNumber(c2);
    		    sumPrice(c2);
    		    printf("\nTotal price(RM): %.2lf\n", totalPrice[c]);
    		    c5+=1;
        	}
        	else{
        		printf("\nReservation is full. Please delete first.\n");
        		c2=0;
        	}
        }
        else if(num==2){
        	deleteReservation();
        }
        else if (num==3){
        	editReservation();	
        }
        else if(num>4||num<1){
        	displayError();
        }
    }
    printf("\n=====================================");
    printf("\nThanks For Using Our Services\n");
    printf("=====================================\n");

    return 0;
}
