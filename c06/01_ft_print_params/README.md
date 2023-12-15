## ft_print_params

|               ft_print_params        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_print_params.c |
| Allowed functions : write       |

- We’re dealing with a <u>program</u> here, you should therefore have a function <code>main</code> in your .c file.
- Create a program that displays its given arguments.
- One per line, in the same order as in the command line.
- It should display all arguments, except for <code>argv[0]</code>.
-Example :
<pre><code>$>./a.out test1 test2 test3 | cat -e
test1$
test2$
test3$
$></code></pre>

<details>

<summary><h3>Testing and Output</h3></summary>

<pre><code>$>./a.out test1 test2 test3 | cat -e
test1$
test2$
test3$
$>./a.out | cat -e
$
$>./a.out "." "a" "A" "0" | cat -e
.$
a$
A$
0$</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

In this <a href=ft_print_params.c>exercise</a>, both arguments defined for <code>main</code> are used:
- one <code>while</code> loop is used to go through the arguments passed via the command line (lines 22-34), starting <i>after</i> the program name in <code>argv</code>. To start after program name, the index variable <code>p</code> is initialised to <code>1</code> instead of <code>0</code>. 
- another <code>while</code> loop is used to go through the characters of each string in <code>argv</code>. 

Note that the code for the above is placed within an <code>if</code> statement - the code only runs when arguments are passed in the command line i.e., when <code>argc > 1</code>.

</details>

