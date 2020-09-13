/*2. This module implement ui related */

#include<stdio.h>
#include<stdlib.h>
#include "handlers.h"

char filename[100];

void handleMenuEvent(int choice)
{
  	printf("Enter the file name");
        scanf("%s",filename);
        switch (choice) {
        case 1:vdrawimage(filename);
		break;
	case 2:vsavefile(filename);
		break;
			}
		printf(" ------------------------------\n");
}

void displayMenu()
{
    	int choice;
	while(1){
		printf(" 1 : Show Image \n");
		printf(" 2 : Save Image \n");
   		printf(" 3 : Exit \n");
		printf(" choice: ");
 		scanf("%d",&choice);
		if(choice == 3)
			exit(0);
		handleMenuEvent(choice);		
		}

}
int main()
{
  displayMenu();
  return 0;
}
