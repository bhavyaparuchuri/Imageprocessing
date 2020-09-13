/*This module takes care of gif files*/

#include<stdio.h>
#include<string.h>
#include "handlers.h"

int img_canHandle(char *filename)
{
	int len;
	char *end;
	printf("Checking whether we can handle %s\n",filename);
	len = strlen(filename);
	end = filename + (len - 3);
	printf("end = %s\n",end);
	if(strcmp(end,"img")==0)
		return TRUE;
	else
		return FALSE;

}

int img_drawImage(char *filename)
{
			printf(" How is this image %s \n", filename);
			return TRUE;
}

int img_savefile(char *newfilename)
{
	printf("file saved by img handler \n");
        return TRUE;
}
imageHandler imghandler ={
          img_canHandle,
	  img_drawImage,
	  img_savefile
};

int _init(){
 	printf(" registering imghandler \n");
	reg_handler(&imghandler);
	return 0;
}

int _fini(){
	printf(" Un registering imghandler \n");
	return 0;
}	
