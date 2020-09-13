/*This module takes care of gif files*/

#include<stdio.h>
#include<string.h>
#include "handlers.h"

int gif_canHandle(char *filename)
{
	int len;
	char *end;
	printf("Checking whether we can handle %s\n",filename);
	len = strlen(filename);
	end = filename + (len - 3);
	printf("end = %s\n",end);
	if(strcmp(end,"gif")==0)
		return TRUE;
	else
		return FALSE;

}

int gif_drawImage(char *filename)
{
			printf(" How is this image %s \n", filename);
			return TRUE;
}

int gif_savefile(char *newfilename)
{
	printf("file saved by gif handler \n");
        return TRUE;
}
imageHandler gifhandler ={
          gif_canHandle,
	  gif_drawImage,
	  gif_savefile
};

int _init(){
 	printf(" registering gifhandler \n");
	reg_handler(&gifhandler);
	return 0;
}

int _fini(){
	printf(" Un registering gifhandler \n");
	return 0;
}	
