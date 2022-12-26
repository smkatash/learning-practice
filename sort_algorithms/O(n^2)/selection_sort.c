#include <stdio.h>
//---------Helper functions-----//
void	print_int_array(int *arr, int size);
void	swap(int *a, int *b);
//---------Helper functions-----//


//---------Selection Sort-----//
void	selection_sort(int *arr, int size)
{
	int	temp;

	for (int i = 0; i < size - 1; i++)
	{
		// store current position 
		temp = i;
		for (int j = i + 1 ; j < size; j++)
		{
			// if int at counter position on the right is smaller than at current position
			// store counter position as current position and continue searching for int which is smaller
			// on the right of curr position
			if (arr[j] < arr[temp])
				temp = j;
		}
		// if initial current position is not the same as new found curr position, swap values
		// since there is value which is smaller on the right of the array
		if (temp != i)
			swap(&arr[i], &arr[temp]);
	}
}
//---------Selection Sort-----//

//---------Main Function-----//
// int	main(void)
// {
// 	int	arr[] = {21, -1, 5, 108, 46, 2, 3, 10, 0};
// 	int	size = sizeof(arr) / sizeof(arr[0]);

// 	selection_sort(arr, size);
// 	print_int_array(arr, size);
// }
//---------Main Function-----//



// swap values
void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

// print whole int array
void	print_int_array(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
}
