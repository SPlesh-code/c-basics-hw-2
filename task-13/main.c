#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *nd, int *nu){
	int temp = *nd;
	*nd = *nu;
	*nu = temp;
}

int main(){
	int size;
	printf("Enter size: ");
	scanf("%d",&size);
	int *number = malloc(size * sizeof(int));
	if (number == NULL){
		printf("NO memory");
		return 0;
	}

	for(int i = 0;i < size;i++){
		printf("Enter %d number: ", i + 1);
		scanf("%d", &number[i]);
	}
	printf("numbers: ");
	for(int i = 0;i < size;i++){
		printf("%d ",number[i]);
	}
	printf("\n");
	printf("select sotr\n");
	printf("Enter 'U' if want min to max or enter 'D' if want max to min: ");
	char typesort;
	scanf(" %c",&typesort);

	for(int i = 0;i < size - 1;i++){
		for(int j = 0;j < size - 1;j++){
			if(typesort == 'U'){
				if(number[j] > number[j + 1]){
					swap(&number[j], &number[j + 1]);
				}
			}
			else if(typesort == 'D'){
				if(number[j] < number[j + 1]){
					swap(&number[j], &number[j + 1]);
				}
			}


		
		}
	}
	printf("number after sort: ");
	for(int i = 0;i < size;i++){
		printf("%d ", number[i]);
	}
	printf("\n");

	return 0;
}

