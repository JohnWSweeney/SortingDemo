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

## ChangeLog
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