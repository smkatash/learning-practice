#include <stdio.h>
//---------Helper functions-----//
void	print_int_array(int *arr, int size);
void	swap(int *a, int *b);
//---------Helper functions-----//


//---------Bubble Sort-----//
void	bubble_sort(int *arr, int size)
{
	// initial position traverser over the array in a loop
	for (int i = 0; i < size - 1; i++)
	{
		// compares and swaps values : current and next on the right
		// if j reaches the end of presorted array it stops
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
	}
}
//---------Bubble Sort-----//


//---------Main Function-----//
// int	main(void)
// {
// 	int	arr[] = {21, -1, 5, 108, 46, 2, 3, 10, 0};
// 	int	size = sizeof(arr) / sizeof(arr[0]);

// 	bubble_sort(arr, size);
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
