# sortingDemo

A console app exploring sorting algorithms.

## Functions
The app opens a console window on startup. Enter the `command` keywords separated by a space. Commands are case-sensitive.

## Data
Data to sort.
### Default Data

### User Data
> `data user x0 x1 x2 ...`

### Random Data
> `data random numInt minInt maxInt`

## Exchange Sorts
### Bubble Sort
> `bubble variableType direction`

### Cocktail Shaker Sort
> `cocktail variableType direction`

### Even-Odd Sort
> `evenOdd variableType direction`

### Comb Sort
> `comb variableType direction`

## Selection Sorts
### Selection Sort
> `selection variableType direction`

## Insertion Sorts
### Insertion Sort
> `insertion variableType direction`

## ChangeLog
0.0.8
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