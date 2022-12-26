#include <stdio.h>
//---------Helper functions-----//
void	set_to_zero(int *bucket, int max);
void	count_each_element(int *arr, int *bucket, int size);
int		find_max(int *arr, int size);
void	print_int_array(int *arr, int size);
void	insert_sorted_into_bucket(int *arr, int *bucket, int size);
//---------Helper functions-----//


//---------Bucket Sort-----//
void	bucket(int *arr, int size)
{
	int	max = find_max(arr, size);
	int	bucket[max];

	set_to_zero(bucket, max);
	count_each_element(arr, bucket, size);
	insert_sorted_into_bucket(arr, bucket, max);
}
//---------Bucket Sort-----//

//---------Main Function-----//
// int main(void)
// {
// 	int arr[] = {30, 1, 64, 18, 13, 11, 5, 9, 2, 25};  
// 	int size = sizeof(arr) / sizeof(arr[0]);
// 	bucket(arr, size);  
// 	print_int_array(arr, size);
// }
//---------Main Function-----//



 // Initialize bucket array with all zeros.
void	set_to_zero(int *bucket, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		bucket[i++] = 0;
}

// Store the count of each element
void	count_each_element(int *arr, int *bucket, int size)
{
	int	i;

	i = 0;
	while (i < size)
		bucket[arr[i++]]++;
}

//Place count elements into sorted output array
void	insert_sorted_into_bucket(int *arr, int *bucket, int size)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i <= size)
	{
		while (bucket[i] > 0)
		{
			arr[j++] = i;
			bucket[i]--;
		}
		i++;
	}
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

void	print_int_array(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
	printf("\n");
}
