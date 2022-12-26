#include <stdio.h>
//---------Helper functions-----//
void	print_int_array(int *arr, int size);
//---------Helper functions-----//


//---------Insertion Sort--------//
void	insertion_sort(int *arr, int size)
{
	int	j;
	int	temp;

	for (int i = 1; i < size; i++)
	{
		// storing current element
		temp = arr[i];
		j = i;
		// check if left element is smaller than current element
		while (j > 0 && temp < arr[j - 1])
		{
			// move left element forward and decrement counter
			arr[j] = arr[j - 1];
			j--;
		}
		// store current element at correct position
		arr[j] = temp;
	}
}
//---------Insertion Sort--------//


//---------Main Function-----//
// int	main(void)
// {
// 	int	arr[] = {21, -1, 5, 108, 46, 2, 3, 10, 0};
// 	int	size = sizeof(arr) / sizeof(arr[0]);

// 	insertion_sort(arr, size);
// 	print_int_array(arr, size);
// }
//---------Main Function-----//


void	print_int_array(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
}
