# sortingDemo

A console app exploring sorting algorithms.

## Functions
The app opens a console window on startup. Enter the `command` keywords separated by a space. Commands are case-sensitive.

## Custom Data
### User Data
> `data user x0 x1 x2 ...`

## Exchange Sorts
### Bubble Sort
> `bubble variableType direction`

## Selection Sorts
### Selection Sort
> `selection variableType direction`

## ChangeLog
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