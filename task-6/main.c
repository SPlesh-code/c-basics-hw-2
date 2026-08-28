#include <stdio.h>
#define limit 7
int main(){
	int number;
	printf("Enter number: ");
	scanf("%d", &number);
	for(int i = 0;i <= limit; i++){
		printf("%d ", number);
		number++;
	}
	printf("\n");
	return 0;
}
