## Radix Sort
Radix sort algorithm is a non-comparative sorting algorithm in computer science. It avoids comparison by creating and categorizing elements based on their radix. For elements with more than one significant digit, it repeats the bucketing process for each digit while preserving the previous step's ordering until all digits have been considered.

- The Radix sort algorithm works by ordering each digit from least significant to most significant. 
- In base 10, radix sort would sort by the digits in the one's place, then the ten's place, and so on.
- To sort the values in each digit place, Radix sort employs counting sort as a subroutine. This means that for a three-digit number in base 10, counting sort will be used to sort the 1st, 10th, and 100th places, resulting in a completely sorted list. Here's a rundown of the counting sort algorithm.

### for example: 
Original array:
```shell
{562, 671, 0, 12, 945, 789, 45, 54, 8}
```

> _Step 1: find the max number of the array._
```shell
{945}
```
> _Step 2: apply Counting sort by looping over it while the max number / base is bigger than zero._

#### First Iteration through Counting sort
> _Step 1: find the max number of the array._
```shell
{945}
```
> _Step 2: count occurence of each element of the array into the count array._
```shell
{1  1  2  0  1  2  0  0  1}
```

> _Step 3: sum each element with its predecessor. Cumulative count of each element:_
```shell
{1  2  4  4  5  7  7  7  8}
```
> _Step 4: find the index of each element of the original array in count array, and place the elements in output (sorted) array._
```shell
{0  671  562  12  54  945  45  8  789}
```
##### base_value = 1
- Orig: {562  671  0  12  945  789  45  54  8}
- Count: {1  1  2  0  1  2  0  0  1} 
- Cumulative count: {1  2  4  4  5  7  7  7  8}
- Sorted: {0  671  562  12  54  945  45  8  789} 

##### base_value = 10
- Pre-sorted: {0  671  562  12  54  945  45  8  789}
- Count: {2  1  0  0  2  1  1  1  1} 
- Cumulative count: {2  3  3  3  5  6  7  8  9}
- Sorted: {0  8  12  45  54  562  671  789  945} 

##### base_value = 100
- Pre-sorted: {0  8  12  45  54  562  671  789  945} 
- Count: {5  0  0  0  0  1  1  1  0} 
- Cumulative count: {5  5  5  5  5  6  7  8  8}
- Final Sorted: {0  8  12  45  54  562  671  789  945}

Referring to https://en.wikipedia.org/wiki/Sorting_algorithm
https://www.freecodecamp.org/news/sorting-algorithms-explained-with-examples-in-python-java-and-c/