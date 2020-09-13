
#define TRUE 1
#define FALSE 0

int vdrawImage(char *);
int vsavefile(char *);


typedef struct {
           int (*canHandle) (char *);
           int (*drawImage) (char *);
           int (*saveImage) (char *);
}imageHandler;
