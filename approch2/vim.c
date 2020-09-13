#include<stdio.h>
#include<stdlib.h>
#include"handlers.h"
extern imageHandler jpghandler;
extern imageHandler gifhandler;
extern imageHandler tifhandler;



imageHandler *imagehandlers[]={
             &tifhandler,
             &gifhandler,
             &jpghandler,
    	     NULL
};
/*this routine implements request switching logic, it attempts to locate suitable handler to process user request.

suitable handler is located by traversing through each of the registered handler objects in the array(imageHandle[] array) until compatible object is found.

On success it returns offset position of handler in the array,else -1 on failure.

*/
             
int find_handler(char *filename)
{
	imageHandler *ih;
	int handleno = 0;
	ih = imagehandlers[0];
      
      /* 
       code to traverse through all of object: implemented with funtion pointer defer ops for polymorphic behavior.
  	*/

   while(ih !=NULL){
		printf("%s: Handle no =%d ptr =%p\n", __func__,handleno,ih);  
                if(ih ->canHandle(filename))
			return handleno;
		handleno++;
		ih = imagehandlers[handleno];
		}
 return -1;


}
int vdrawimage(char *filename)
{
     imageHandler *ih;
      int handleno = 0;
     handleno =find_handler(filename);
     printf("%s:handle no =%d\n",__func__,handleno);
    
    if(handleno== -1){
 		printf("we cannot handle this file\n");
		return FALSE;
       }
    ih =imagehandlers[handleno];
    ih ->drawImage(filename);
    return TRUE;

}


int vsavefile(char *newfile)
{
  
     imageHandler *ih;
     int handleno = 0;
     handleno =find_handler(newfile);
     printf("%s:handle no =%d\n",__func__,handleno);
    
    if(handleno== -1){
 		printf("we rcannot handle this file\n");
		return FALSE;
       }
    ih =imagehandlers[handleno];
    ih ->saveImage(newfile);
    return TRUE;

}




