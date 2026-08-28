#include <stdio.h>
#include <stdlib.h>
void matrix(int height, int width,char  symbol){
	for(int i = 0;i < height;i++){
		for(int j = 0;j < width;j++){
			printf("%c",symbol);
		}
		printf("\n");
	}
}
int main(){
	int hei, wid;
	char sym;
	printf("Enter height: ");
	scanf("%d", &hei);
	printf("Enter width: ");
	scanf("%d", &wid);
	printf("Enter symbol: ");
	scanf(" %c", &sym);
	matrix(hei, wid, sym);
	return 0;
}


