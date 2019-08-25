#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_vector(char* tab, int size);


int main()
{
    int i;
    int size = 50/(sizeof(char));
    int err =0;
    char *ptr;
    ptr = realloc(NULL, size*(sizeof(char)));
    if (!ptr)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj tekst: ");


    for (i=0; ; i++)
    {

        if (i%size==0&&i>0)
        {
            char *temp = realloc(ptr, size*(i/size+1)*(sizeof(char)));
            if(temp) ptr = temp;
            else
            {
               // printf("Failed to allocate memory\n");
                free(ptr);
                err = 1;
                break;
            }
        }
        *(ptr+i) = getchar();
       if(*(ptr+i)==10){
        break;
       }


    }
    if(err==0)*(ptr+i)='\0';
    if(err==1)*(ptr+i-1)='\0';

    display_vector(ptr,i);
    if(err==0){
    free(ptr);
    }
    return 0;
}



void display_vector(char* tab, int size)
{
        if (tab==NULL) return;
       printf("%s",tab);
}
