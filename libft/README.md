# LIBFT LIBRARY | S. Lucas Serrano
In 42 we dont have access to a lot of highly useful standard functions. But this project ask us to create our own library of them by replicating some of those basic ones and adding our own.
If you are a 42 student, know that this includes all the mandatory and extra funcions of the exercise. As well as some extra functions that I've found useful to add in next projects. And that it was graded with a 115 by the moulinette.
All of the code is normalize according to _"The norm"_. Including rules like _Only 25 lines per function_, _Only 5 functions per file_, _All usable functinos starting with ft__, etc.

#### How to use it
Clone this libft directory to your project.
Add to the scripts you wont to use it in: _#include "PATH/libft/libft.h"_.  PATH been how to get to the lift directory from  your script.
Finally, when you compile make sure to also compile the libft.a included whitin this same directory.

It also includes a Makefile that generates the libft.a file, in case you want to add or modify some of this functions.
The make file includes the following tules:
- _make_: Generates object files for all the .c scripts
- _make clean_: Deletes the object files
- _make fclean_: Makes _clean_ and deletes the libft.a
- _make re_: Makes _fclean_ and _make_ again

To see all the functinos that this library includes, see the libf.h file.