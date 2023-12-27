## libft

|               libft        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : libft_creator.sh, ft_putchar.c, ft_swap.c, ft_putstr.c, ft_strlen.c, ft_strcmp.c |
| Allowed functions : write       |

- Create your <code>ft</code> library. It’ll be called <code>libft.a</code>.
- A shell script called <code>libft_creator.sh</code> will compile source files appropriately and will create your library.
- This library should contain all of the following functions :
```
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
```
- We’ll launch the following command-line :
<code>sh libft_creator.sh</code>

<details>

<summary><h3>Testing</h3></summary>

- Run <code>sh libft_creator.sh</code> in the terminal. 
- It should have created a <code>libft.a</code> file. 
- Check that the functions can be accessed via <code>libft.a</code> by first compiling a test program: <code>gcc main.c libft.a</code>
	- <a href=main.c>main.c</a> contains code to use all five functions. 
- Execute the program using <code>./a.out</code>

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>a
abc
3
2
1
0</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

The <code>.c</code> files are simply taken from the previous exercises:
- <a href=../../c00/00_ft_putchar>ft_putchar</a>
- <a href=../../c01/02_ft_swap>ft_swap</a>
- <a href=../../c01/05_ft_putstr>ft_putstr</a>
- <a href=../../c01/06_ft_strlen>ft_strlen</a>
- <a href=../../c03/00_ft_strcmp>ft_strcmp</a>

The last <a href=libft_creator.sh>file</a> required <a href=.sh></a> contains the commands to create a static library called <code>libft</code>. 

<code>#!/bin/sh</code> is used at the start to ensure that bash is used to execute the script. 

Now, if the <code>libft</code> library already exist, we will remove it before we recreate it: 
<pre><code>rm -f libft.a</code></pre>

Next, we compile the <code>.c</code> files containing the functions we want in our library. We use the usual flags with <code>gcc</code> to compile. This step will produce the object files (<code>.o</code>) from all the <code>.c</code> files. This compiling step is different to the one we'd previously done because we want the <code>.c</code> files to be compiled but not linked: this is indicated with the <code>-c</code> flag.
<pre><code>gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c</code></pre>

After that, the static library <code>libft.a</code> is created using the object files:
<code>ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o</code>

<code>ar</code> creates, modifies or extracts from archives. In this case, a library is essentially a collection/archive of <code>.o</code> files but organised in a specific way. <code>rc</code> are additional flags:
- <code>c</code> creates the archive if it does not already exist. Without this flag, the archive would still be created but a warning would be issued as well.
- <code>r</code> inserts the object files into the archive (with replacement). By doing this with replacement, any older object files in the library are updated with new object files, though this is not critical here since we'd earlier deleted <code>libft.a</code> if it existed and contained older object files.
- <code>s</code> creates a sorted index for the library. This is not strictly required but it will make it faster to access the functions in the library

Finally, we tidy up the workspace by deleting the intermediate/temporary files i.e., the object files:
<code>rm -f ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o</code>

</details>

