#include <stdio.h> 
#include <stdlib.h> 
int main(){ 
	int min, first = 0, second = 1, max, next, swap; 
	printf("Enter first number: "); 
	scanf("%d", &min);
	printf("Enter second number: ");
	scanf("%d", &max);
	if(min > max){
		swap = min;
		min = max;
		max = swap; 
	}
	printf("Fibonacci numbers: ");
	while(first <= max){
		 if (first >= min) {
            printf("%d ", first);
        }

        next = first + second;
        first = second;
        second = next;
	}
	printf("\n");
	return 0;
}
	


