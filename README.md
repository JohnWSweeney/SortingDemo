# sortingDemo

A console app exploring sorting algorithms, including bubble, cocktail, even-odd, comb, insertion, and quicksort algorithms.

## Functions
The app opens a console window on startup. Enter the `command` keywords separated by a space. Commands are case-sensitive.

## Data
You can apply sorting algorithms to three types of data vectors: `default`, `user`, and `random`.

The `default` data is a static integer vector containing 1, 7, 3, 9, 2, 4, 6, 8, 5, and 0. You can also input your own data into the `user` vector by entering:
> `data user x0 x1 x2 ...`

where `x` is an integer. 

Finally, you can populate the `random` vector with an indefinite number of random integers by entering:
> `data random numInt minInt maxInt`

where `numInt` is the number of integers you wish to populate the vector with, and `minInt` and `maxInt` are the lower and upper bounds, respectively, from which the random numbers will be selected.

## Using the App
Apply a sorting algorthm to your chosen data type by entering:
>`sortName dataType direction`

where `direction`  selects the direction to sort the data: `asc` for ascending or `desc` for descending.

## Exchange Sorts
### Bubble Sort
Bubble sort is perhaps the simplest 
> `bubble dataType direction`

### Cocktail Shaker Sort
> `cocktail dataType direction`

### Even-Odd Sort
> `evenOdd dataType direction`

### Comb Sort
> `comb dataType direction`

### Quick Sort
> `quickSort dataType direction`

## Selection Sorts
### Selection Sort
> `selection dataType direction`

## Insertion Sorts
### Insertion Sort
> `insertion dataType direction`

## Download
[sortingDemo v1.0.0](https://github.com/JohnWSweeney/sortingDemo/releases/download/v1.0.0/sortingDemo_v1_0_0.exe) [50 kB]

## ChangeLog
v1.0.0
- Added quickSort to exchangeSorts.

v0.0.8
- Added evenOdd algorithmn function to exchangeSorts.h/cpp. 

v0.0.7
- Added insertionSorts.h/cpp.
	- Added insertionSort algorithmn function.

v0.0.6
- Added combSort algorithmn function to exchangeSorts.h/cpp. 
- Renamed printData to printVector in data.h/cpp.

v0.0.5
- Added cocktailShakerSort algorithmn function to exchangeSorts.h/cpp.

v0.0.4
- Added selectionSorts.h/cpp.
	- Added selectionSort algorithmn function.
- Global access to printData function in data.h/cpp.
	- printData called by all functions when complete.

v0.0.3
- Added random class.
	- Generates random numbers with 32-bit Mersenne Twister within user specified distribution.
- Merged variables.h/cpp with data.h/cpp.
	- Added getRandomData to populate a vector with	
	- Added checkCopyVariable to prevent calls to sort function on empty vector.

v0.0.2
- Added commands.h/cpp and supporting functions to sort user input commands.
	- Resulting command struct (cmd) is used to call functions, passes parameters via startMenu function.
- Added getUserData function to data.h/.cpp to accept unsorted user data.
- Updated README.

v0.0.1
- Added console interface.
- Added README.

v0.0.0
- Initial commit.