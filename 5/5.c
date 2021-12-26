///@file 5_1.c
#include <stdio.h>
typedef struct 
{
	char name[10];
	int weight;
}dog;
//Swaps dog pointers
void Swap(dog* dog1, dog* dog2) 
{
	dog temp = *dog1;
	*dog1 = *dog2;
	*dog2 = temp;
}
//Bubble sorts dogs by name
void SortDogsByName(dog* dogs,int n) 
{
	int i, j;
	for (i = 0; i < n - 1; i++) 
{
		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++) 
		{
			if (strcmp(dogs[j+1].name,dogs[j].name) > 0) 
			{
				Swap(&dogs[j], &dogs[j + 1]);
			}
		}
	}
}
//Sorts dogs by weight
void SortDogsByWeight(dog* dogs, int n) 
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
{
			if (dogs[j].weight > dogs[j+1].weight)
			{
				Swap(&dogs[j], &dogs[j + 1]);
			}
		}
	}
}
//Constructs and returns a "dog" type
dog CreateDog(char name[10], int weight) {
	dog doge;
	strcpy(doge.name, name);
	doge.weight = weight;
	return doge;
}
//Prints dog type
void PrintDog(dog doge) {
	printf("Name: %s Weight: %dkg", doge.name, doge.weight);
}
int main() {
	dog dogs[10] = { CreateDog("chuck",10),CreateDog("doc",15),CreateDog("Howler",6) };
	SortDogsByName(dogs, 3);
	SortDogsByWeight(dogs, 3);
	PrintDog(dogs[2]);
}