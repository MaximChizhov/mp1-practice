#include <stdio.h>
#include <locale.h>
#include <math.h>


int main()
{
	setlocale(LC_CTYPE, "Rus");
	float x1, y1, r1, x2, y2, r2;
	printf("������� ���������� � ������ ������ ���������� ");
	scanf("%f%f%f", &x1, &y1, &r1);
	printf("������� ���������� � ������ ������ ���������� ");
	scanf("%f%f%f", &x2, &y2, &r2);


	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("���������� �����");
		return 1;
	}
	if (x1 == x2 && y1 == y2 && r1 > r2)
	{
		printf("������ ���������� ������� �������");
		return 1;
	}
	if (x1 == x2 && y1 == y2 && r1 < r2)
	{
		printf("������ ���������� ������� �� ������");
		return 1;
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r1 + r2))
	{
		printf("���������� ����� ���� ����� �����");
		return 1;
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) >= (r1 + r2))
	{
		printf("���������� �� ����� ����� �����");
		return 1;
	}
	else
	{
		printf("���������� ����������� � ���� ������");
		return 1;
	}
	return 0;
}