/******************************************
* Liel Giat
* 313612095
* 83-120-09
* ex5
******************************************/

#include <stdio.h>
#include <string.h>

#define MAX 80

void program(int list[], int j, int size);// the menu
int scanArray(int list[], int j);// option 1
void sortArray(int list[], int j, int i); // option 2
void printArray(int list[], int j, int i);// option 3
void minTimes(int list[], int size, int i, int times, int min);// option 4
int is_power(int k, int n);// option 5
void reverseNumber(int num);// option 6

int main()
{
	int j = 0, size = 0;// we use j and size just in order to call prog function
	int list[MAX];
	program(list, j, size);
	return 0;
}
/***************************************************************************************
Function name: program
Input: the array, the number of the last place in the array and the size of the array.
Output: None.
The function operation: will get the option that the user pick, and according to the pick will call the right function 
until the user will pick 7 and shut the program.
****************************************************************************************/
void program(int list[], int j, int size)
{
	int option, i = 0, min, times = 0, k, n, num;
	printf("Choose an option\n");
	scanf("%d", &option);
	if (option == 7)
	{
		printf("Bye\n");//if the user enters 7, the program prints bye and finishes the recursion and the program
		return;
	}
	if (option == 1)
	{
		printf("Please enter numbers, -1 to finish\n");//if the user enters 1, the program prints this line, and inputs array
		size = scanArray(list, j);//we call the function which inputs array and returns its length
		j = size - 1;// the number of the last number in the array
	}
	if (option == 2)
	{
		sortArray(list, j, i);//if the user enters 2, the program calls a function which sort the array
		printf("Finished sorting\n");//then it prints this line
	}
	if (option == 3)
	{
		printArray(list, j, i);//if the user enters 3, the program prints the array by the function
	}
	if (option == 4)
	{
		/*if the user enters 4, the program finds by function how many times the minimum is found in the array,
		then prints this number(the number of times)*/
		min = list[0];// we will assume that the minimum number is in the first place and will check it
		minTimes(list, size, i, times, min);
	}
	if (option == 5)
	{
		printf("Please enter two numbers\n");//if the user enters 5, the program inputs 2 numbers
		scanf("%d%d", &k, &n);
		k = is_power(k, n);//the program checks by a function if the first is power of the second, and prints a suitable announcement
		if (k == 1)
			printf("power\n");
		else if (k == 0)
			printf("no power\n");
	}
	if (option == 6)
	{
		printf("Please enter a number\n");;//if the user enters 6, the function inputs a number
		scanf("%d", &num);
		reverseNumber(num);
	}
	program(list, j, size);//the function calls itself and sends the array and its 2 lengths so we can use them again
}
/***************************************************************************************
Function name: scanArray
Input: the array and the number of the last place in the array.
Output: the lenght of the array.
The function operation: will get the array from the user until -1.
****************************************************************************************/
int scanArray(int list[], int j)
{
	scanf("%d", &list[j]);//will get the array
	if (list[j] == -1)//when the function will get -1 , the function will stop
		return j;
	j++;//for the next place
	scanArray(list, j);// will call the function again
}
/***************************************************************************************
Function name: sortArray
Input: the array, the number of the last place in the array and int that will go all over the array.
Output: None.
The function operation: sort the array from the smallest number to the biggest number.
****************************************************************************************/
void sortArray(int list[], int j, int i)
{
	int temp;
	if (list[i] > list[i + 1])// if the next number is smaller
	{
		temp = list[i + 1];// so we won't lose the number
		list[i + 1] = list[i];// take the smallest to be before
		list[i] = temp;// and the bigger to be after
	}
	i++;// to the next number
	if (j != i)// will go over all the number with recursion 
		sortArray(list, j, i);
	i = 0;// for the second (and more) time that the function will go over the array
	j--;// there is in the last place the biggest number so we won't check him again
	if (j == 0)// when we will go over all the number the function will close
		return;
	sortArray(list, j, i);// will call the function again
}
/***************************************************************************************
Function name: printArray
Input: the array, the number of the last place in the array and int that will go all over the array.
Output: None.
The function operation: will print the array.
****************************************************************************************/
void printArray(int list[], int j, int i)
{
	if (i != j)// print every number except the lst one
		printf("%d ", list[i]);
	else// will print the last number
	{
		printf("%d\n", list[j]);
		return;
	}
	i++;// for the next number
	printArray(list, j, i);// will call the function again
}
/***************************************************************************************
Function name: minTimes
Input: the array, the size of the array ,int that will go all over the array, int that will count the times of the min
and int that is the first number of the array.
Output: None.
The function operation: will check how many times there is the smallest number.
****************************************************************************************/
void minTimes(int list[], int size, int i, int times, int min)
{
	if (min > list[i])//if the next number is smaller
	{
		times = 1;// he was only once
		min = list[i];// and he will ne the new min
	}
	else if (min == list[i])// if there is the same number
		times++;// will rise the count
	i++;// for the next number
	if (i == size)// if the function go over all the array
	{
		printf("%d\n", times);// print the number of times of the min
		return;
	}
	minTimes(list, size, i, times, min);// will call the function again
}
/***************************************************************************************
Function name: is_power
Input: the power and the number.
Output: 1 or 0, if it is power or not.
The function operation: will check if k is a power of n.
****************************************************************************************/
int is_power(int k, int n)
{
	if (k == 1)
		return 1;//if k is 1,he is always power of n
	if ((k%n != 0) || (k == 0) || (n == 0) || (n == 1))
		return 0;/*if there were specific incidents return 0,
		 or if k is not a multiple of n,it not its power and the function returns 0*/
	return is_power((k / n), n);/*the function checks if the quotient of k and n is also power of n
	and will call the function again*/
}
/***************************************************************************************
Function name: reverseNumber
Input: the number that we need to print him in reverse.
Output: None.
The function operation: will print the number that we get in reverse.
****************************************************************************************/
void reverseNumber(int num)
{
	int a;
	a = num % 10;//the last digit
	num = num / 10;//the new number without the last digit
	printf("%d", a);//print the last digit
	if (num == 0)// if we already go all over the the number
	{
		printf("\n");
		return;
	}
	reverseNumber(num);// will call the function again
}