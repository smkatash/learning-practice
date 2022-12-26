#include <stdio.h>
//---------Helper functions-----//
void	print_int_array(int *arr, int size);
void	split_recurs_merge(int *arr, int left, int right);
void	merge(int *arr, int left, int middle, int right);
//---------Helper functions-----//


//---------Merge Sort--------//
void	merge_sort(int *arr, int size)
{
	split_recurs_merge(arr, 0, size);
}
//---------Merge Sort--------//


//---------Main Function-----//
// int	main(void)
// {
// 	int	arr[] = {21, -1, 5, 108, 46, 2, 3, 10, 0};
// 	int	size = sizeof(arr) / sizeof(arr[0]);

// 	merge_sort(arr, size);
// 	print_int_array(arr, size);
// }
//---------Main Function-----//


// create temp left/ right arrays to store integers
// compare integer in left & right array and store it in the array the right in order
void	merge(int *arr, int left, int middle, int right)
{
	int	l = middle - left + 1;
	int	r = right - middle;
	int	left_arr[l];
	int	right_arr[r];
	int	i, j, c;

	for (i = 0; i < l; i++)
		left_arr[i] = arr[left + i];
	for (j = 0; j < r; j++)
		right_arr[j] = arr[middle + j + 1];
	i = 0;
	j = 0;
	c = left;
	// comparison left/right
	while (i < l && j < r)
	{
		if (left_arr[i] <= right_arr[j])
		{
			arr[c] = left_arr[i];
			i++;
		}
		else
		{
			arr[c] = right_arr[j];
			j++;
		}
		c++;
	}
	// store the rest of the array
	while (i < l)
		arr[c++] = left_arr[i++];
	while (j < r)
		arr[c++] = right_arr[j++];
}

// get the middle point and divide recursively an array
// divided integers are then merged
void	split_recurs_merge(int *arr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		split_recurs_merge(arr, left, middle);
		split_recurs_merge(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

void	print_int_array(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
}
