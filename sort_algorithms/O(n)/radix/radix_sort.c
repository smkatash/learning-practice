#include <stdio.h>
#include <stdlib.h>
//---------Helper functions-----//
int		find_max(int *arr, int size);
void	counting_sort(int *arr, int size, int i);
void	print_int_array(int *arr, int size);
//---------Helper functions-----//


//---------Radix Sort--------//
void	radix_sort(int *arr, int size)
{
	// By each base iteration applies counting sort to sort the elements
	int	max = find_max(arr, size);
	int	base;

	base = 1;
	while (max / base > 0)
	{
		counting_sort(arr, size, base);
		base *= 10;
	}
}
//---------Radix Sort--------//


//---------Main Function-----//
// int	main(void)
// {
// 	int arr[] = {562, 671, 0, 12, 945, 789, 45, 54, 8};
// 	int	size = sizeof(arr) / sizeof(arr[0]);
// 	radix_sort(arr, size);
// 	print_int_array(arr, size);
// }
//---------Main Function-----//



// Print an array
void	print_int_array(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
}

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

 // Find the max element of the array divided by base and % 10
static int	find_max_counting(int *arr, int size, int base)
{
	int	i;
	int	max;
	
	max = (arr[0] / base) % 10;
	i = 0;
	while (i++ < size + 2)
	{ 
		if ((arr[i] / base) % 10 > max)
			max = arr[i];
	}
	return (max);
}


 // Initialize count array with all zeros.
static void	set_to_zero(int *count, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		count[i++] = 0;
}

// Store the count of each element divided by base and % 10
static void	count_each_element(int *arr, int *count, int size, int base)
{
	int	i;

	i = 0;
	while (i < size)
		count[(arr[i++] / base) % 10]++;
}

// Store the cummulative count of each array
static void	cumulative_count_of_elements(int *count)
{
	int	i;

	i = 0;
	while (i++ <= 10)
		count[i] += count[i - 1];
}

// Place count elements into sorted output array divided by base and % 10
static void	insert_sorted_into_output(int *arr, int *count, int *output, int base, int size)
{
	int	i;

	i = size;
	while (i-- > 0)
	{
		output[count[(arr[i] / base) % 10] - 1] = arr[i];
		count[(arr[i] / base) % 10]--;
	}
}

void	counting_sort(int *arr, int size, int base)
{
	int	max;
	max = find_max_counting(arr, size, base);
	int count[max + 1];
	int output[size + 1];
	int	i;
	
	set_to_zero(count, max);
	count_each_element(arr, count, size, base);
	cumulative_count_of_elements(count);
	insert_sorted_into_output(arr, count, output, base, size);
	i = -1;
	while (i++ < size)
		arr[i] = output[i];
}

