#include <stdio.h>
#include <stdlib.h>
//---------Helper functions-----//
int		find_max(int *arr, int size);
void	set_to_zero(int *count, int max);
void	count_each_element(int *arr, int *count, int size);
void	cumulative_count_of_elements(int *count, int max);
void	insert_sorted_into_output(int *arr, int *count,int *output, int size);
void	print_int_array(int *arr, int size);
//---------Helper functions-----//

//---------Counting Sort--------//
void	counting_sort(int *arr, int size)
{
	int output[size];
	int	max;
	max = find_max(arr, size);
	int count[max + 1];
	int	i;
	
	set_to_zero(count, max);
	count_each_element(arr, count, size);
	cumulative_count_of_elements(count, max);
	insert_sorted_into_output(arr, count, output, size);
	i = -1;
	while (i++ < size)
		arr[i] = output[i];
}
//---------Counting Sort--------//


//---------Main Function-----//
// int	main(void)
// {
// 	int arr[] = {5, 6, 0, 1, 9, 5, 6, 2, 4};
// 	int	size = sizeof(arr) / sizeof(arr[0]);
// 	counting_sort(arr, size);
// 	print_int_array(arr, size);

// 	int arr2[] = {1, 5, 2, 6, 9, 7, 1, 1, 0};
// 	int	size2 = sizeof(arr2) / sizeof(arr2[0]);
// 	counting_sort(arr2, size2);
// 	print_int_array(arr2, size2);
// 	return (0);
// }
//---------Main Function-----//



 // Find the max element of the array
int	find_max(int *arr, int size)
{
	int	max;
	int	i;
	
	max = arr[0];
	i = 0;
	while (i++ < size - 1)
	{ 
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

 // Initialize count array with all zeros.
void	set_to_zero(int *count, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		count[i++] = 0;
}

// Store the count of each element
void	count_each_element(int *arr, int *count, int size)
{
	int	i;

	i = 0;
	while (i < size)
		count[arr[i++]]++;
}

// Store the cummulative count of each array
void	cumulative_count_of_elements(int *count, int max)
{
	int	i;

	i = 0;
	while (i++ <= max)
		count[i] += count[i - 1];
}

//Place count elements into sorted output array
void	insert_sorted_into_output(int *arr, int *count,int *output, int size)
{
	int	i;

	i = size;
	while (i-- >= 0)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
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
