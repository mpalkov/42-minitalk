# 42_Libft
Your very first own library

**Summary:**
This project is about coding a C library.
It will contain a lot of general purpose functions your programs will rely upon.

C programming can be very tedious when one doesn’t have access to the highly useful standard functions. This project is about understanding the way these functions work, implementing and learning to use them. Your will create your own library. It will be helpful since you will use it in your next C school assignments. Take the time to expand your libft throughout the year. However, when working on a new project, don’t forget to ensure the functions used in your library are allowedin the project guidelines.

# Personal comments
- the root directory contains the **mandatory** AND the **bonus** required files.
- the TESTS_etc/ directory contains all my personal files used to test functions or certain behaviour in certain cases. Might be a bit messy.

# Versions

#### Git Push 20-Feb-2023 (V03) ####
	- added my ft_printf
	- added my ft_getnextline
	- added ft_ptr_freenull (Performs free and sets to NULL pointer of any type).
	- Modified Makefile to compile objects with symbols for debugging with `-g3` flag.


#### Git Push 01-Sept-2022 ####
	- added ft_putchar.c to Makefile
	- ft_putendl corrected arguments
	- corrected - use ft_putchar_fd

#### Git Push 29-Aug-2022 ####
	- removed &. - ncompatible pointer types passing 'char **' to parameter of type 'char *';

#### Git Push 23-Aug-2022 (V02) ####
	- modified ft_put* fuctions to return int and return -1 on error.
	- functions ft_put* write directly to STDOUT_FILENO fd. 
	- Functions ft_put*_fd take file descriptor as arguent.
	
#### Git Push 22-Aug-2022 (V01) ####
	- version submitted for evaluation and validated. Everything works correctly according to my peer and moulinette tests.
	- passed all Francinette STRICT tests too.
