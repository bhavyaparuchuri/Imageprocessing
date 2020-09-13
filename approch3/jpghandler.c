/*This module takes care of jpg files*/

#include<stdio.h>
#include<string.h>
#include "handlers.h"

int jpg_canHandle(char *filename)
{
	int len;
	char *end;
	printf("Checking whether we can handle %s\n",filename);
	len = strlen(filename);
	end = filename + (len - 3);
	printf("end = %s\n",end);
	if(strcmp(end,"jpg")==0)
		return TRUE;
	else
		return FALSE;

}

int jpg_drawImage(char *filename)
{
			printf(" How is this image %s \n", filename);
			return TRUE;
}

int jpg_savefile(char *newfilename)
{
	printf("file saved by jpg handler \n");
        return TRUE;
}
imageHandler jpghandler ={
 	jpg_canHandle,
        jpg_drawImage,
        jpg_savefile,

};
int _init()
{
	 printf(" registering jpghandler \n"); 	
	 reg_handler(&jpghandler);
	 return 0;
}
int _fini()
{
	 printf(" un  registering jpghandler \n"); 	
	 return 0;
}
