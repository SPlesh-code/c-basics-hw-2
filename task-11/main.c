#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{

    char *text;
    text = malloc(SIZE * sizeof(char));
    if (text == NULL){
	    printf("NO memory");
	    return 0;
    }
    printf("Enter text: ");
    scanf(" %[^\n]", text);
    char *read = text;
    char *write = text;
    while (*read != '\0'){
	    if (*read != ' '){
		    *write = *read;
		    write++;
	    }
	    else{
		    if(write != text && *(write - 1) != ' '){
				    *write = *read;
				    write++;
				    }
	    }
	    read++;
    }
    *write = '\0';
    if(write > text && *(write - 1) == ' '){
	    *(write - 1) = '\0';
    }
    printf("Resul:%s\n", text);
    free(text);


    return 0;
}
