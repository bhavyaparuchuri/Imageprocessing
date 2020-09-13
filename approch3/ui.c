/*2. This module implement ui related */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "handlers.h"

char filename[100];

void handleMenuEvent(int choice)
{
  	printf("Enter the file name");
        scanf("%s",filename);
        switch (choice) {
        case 1:vdrawImage(filename);
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
int init_handlers(){
 	FILE *fp;
        void *soptr;
 	char so_name[300];
	fp=fopen("./config.txt","r");
	if(fp==NULL){
		printf(" config.txt not found \n");
		return FALSE;
	}
	fgets(so_name,300,fp);
	while(!feof(fp)){
		so_name[strlen(so_name) -1] = '\0';
		printf(" Loading .. %s\n",so_name);
		soptr = dlopen(so_name,RTLD_NOW);
		if(soptr == NULL){
			printf("Failed to load library\n");
			return FALSE;
		}
		fgets(so_name,300,fp);
	}
		return TRUE;
}
int main()
{
  init_handlers();
  displayMenu();
  return 0;
}
