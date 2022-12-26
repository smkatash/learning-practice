## Counting Sort
The counting sort algorithm works by first creating a list of the counts or occurrences of each unique value in the list. It then creates a final sorted list based on the list of counts. One important thing to remember is that counting sort is incapable of sorting negative numbers because it uses mapping array or intermediate array (which is used to map unsorted input array to sorted output array).

Original array:
```shell
{5, 6, 0, 1, 9, 5, 6, 2, 4}
```

> _Step 1: find the max number of the array._
```shell
{9}
```
> _Step 2: count occurence of each element of the array into the count array._
```shell
{1  1  1  0  1  2  2  0  0  1}
```
> _Step 3: sum each element with its predecessor. Cumulative count of each element:_
```shell
{1  2  3  3  4  6  8  8  8  9}
```
> _Step 4: find the index of each element of the original array in count array, and place the elements in output (sorted) array._

- Orig: {5, 6, 0, 1, 9, 5, 6, 2, 4}
- Count: {1  1  1  0  1  2  2  0  0  1} 
- Cumulative count: {1  2  3  3  4  6  8  8  8  9}
- Sorted: {0  1  2  4  5  5  6  6  9}

### for example: 
The last element of original array: 4 is mapped in the 4th index of count array. In the sorted array it is placed into the index 4 - 1, so 3rd index.
Sorted: 
```shell
{0  0  0  4  0  0  0  0  0}
```
Next,
The second last element of original array: 2 is mapped in the 2nd index of count array (with int 3). In the sorted array it is placed into the index 3 - 1, so 2nd index.
Sorted: 
```shell
{0  0  2  4  0  0  0  0  0}
```
Next,
The third last element of original array: 6 is mapped in the 6th index of count array (with int 8). In the sorted array it is placed into the index 8 - 1, so 7th index.
Sorted: 
```shell
{0  0  2  4  0  0  0  6  0}
```
etc.....until array is sorted as:
```shell
{0  1  2  4  5  5  6  6  9}
```