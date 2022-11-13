#include <stdio.h>
#include <string.h>

#define N 10

char* codes[N] = { "1452", "6254", "3365", "4789", "9933", "1238", "8456", "3495", "0237", "5638" };
char* products[N] = {
	"Milk",
	"Chicken",
	"Tomato",
	"Potato",
	"Eggs",
	"Apples",
	"Onion",
	"Cheese",
	"Bread",
	"Water" };
float price[N] = { 62.00, 100.00, 50.00, 35.00, 80.00, 73.00, 27.00, 94.00, 15.00, 30.00 };
int discount[N] = { 10, 25, 15, 5, 0, 5, 10, 20, 0, 0, };


void Input(int* c, char* b[50])
 {
	
	int num_basket = 0, i;
	char code[5];

	printf("Enter the product code or 'exit' to generate a receipt\n");
	while (strcmp(code, "exit"))
	{
		gets(code);
		if (strcmp(code, "exit"))
		{
			for (i = 0; i < N; i++)
			{
				if (strcmp(code, codes[i]) == 0)
				{
					printf("%s %.2f %d%%\n", products[i], price[i], discount[i]);
					b[num_basket] = codes[i];
					printf("Enter the quantity: ");
					scanf("%d", &(c[num_basket]));
					num_basket++;
				}
			}
		}
	}
}

int Print(int* c, char* b[50])
{
	int i, j;
	int num_basket = 0;
	float price_disc, s = 0;

	printf("\nYour receipt\n");
	for (i = 0; i < num_basket; i++)
	{
		for (j = 0; j < N; j++)
			if (strcmp(b[i], codes[j]) == 0)
			{
				price_disc = (price[j] - (price[j] / 100) * discount[j]) * c[i];
				printf("*%s\nprice - %.2f, discount - %d%%, discount price %.2f, count - %d\n", products[j], price[j], discount[j], price_disc, c[i]);
				s += price_disc;
			}
	}
	return s;
}

int main()
{
	int counts[100] = { 0 };
	char* basket[50];
	float sum;

	Input(counts, basket);
	sum = Print(counts, basket);

	
	printf("For payment:\n%.2f", sum);
	return 0;

}
