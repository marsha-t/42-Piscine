## ft_boolean.h

|               ft_boolean.h        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : ft_boolean.h |
| Allowed functions : None       |

- Create a <code>ft_boolean.h</code> file. It’ll compile and run the following <code>main</code> appropriately:
```
#include "ft_boolean.h"
void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}
int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}
```
- This program should display
```
I have an even number of arguments.
```
- or
```
I have an odd number of arguments.
```
- followed by a line break when adequate.

<details>

<summary><h3>Testing and Output</h3></summary>

<pre><code>$>./a.out | cat -e
I have an even number of arguments$
$>./a.out 1 | cat -e
I have an odd number of arguments$
$>./a.out 1 2 | cat -e
I have an even number of arguments$</code></pre>

<code>ft_boolean.h</code> should be compiled together with <code>main.c</code> to generate this output. 

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_boolean.h>header file</a> is generated by scrutinising the <a href=main.c>main.c</a> code. Essentially anything that you don't recognise or seems odd, you probably have to define it in the header file. 

The lines that will rely on the header file are:

<pre><code>18		write(1, str++, 1);
...
21	t_bool	ft_is_even(int nbr)
22	{
23		return ((EVEN(nbr)) ? TRUE : FALSE);
24	}
...
29	if (ft_is_even(argc - 1) == TRUE)
30		ft_putstr(EVEN_MSG);
...
32		ft_putstr(ODD_MSG);
33	return (SUCCESS);</code></pre>

Line 18 uses the <code>write</code> function from the <code>unistd.h</code> library, even though <code>main.c</code> didn't include this library. This library will then be included from <code>ft_boolean.h</code> instead (line 17 in <code>ft_boolean.h</code>).

Let's tackle <code>ft_is_even</code> next and what it returns. The <code>return</code> statement uses a ternary condition: 
- If <code>EVEN(nbr)</code> is true (i.e., outputs a value greater than <code>0</code>), <code>TRUE</code> is returned; 
- Otherwise if <code>EVEN(nbr)</code> is false (i.e., outputs <code>0</code>), <code>FALSE</code> is returned. 

So <code>EVEN</code> takes <code>nbr</code> as an input and outputs either <code>0</code> or a value greater than <code>1</code>. This looks like a function called <code>EVEN</code> but no such function has been defined in <code>main.c</code>. Instead, must be an expression. Specifically, it takes <code>nbr</code> and checks whether it is even: <code>(nbr % 2 == 0)</code> (line 20 in <code>ft_boolean.h</code>). This is wrapped in brackets so that it evaluates to <code>1</code> if <code>nbr</code> is even and <code>0</code> otherwise.

Since C treats <code>0</code> as false and a value greater than <code>0</code> as true in the evaluation of expressions, let's define <code>TRUE</code> as <code>1</code> and <code>FALSE</code> as <code>0</code> (lines 21-22 in <code>ft_boolean.h</code>). Since the return value of <code>ft_is_even</code> is either <code>1</code> or <code>0</code>, the return type is an <code>int</code>. This implies that <code>t_bool</code> in line 21 is an alias for <code>int</code>. We use <code>typedef</code> to create this (line 19 in <code>ft_boolean.h</code>).

In the <code>main</code> function, <code>ft_putstr</code> is called to display an <code>EVEN_MSG</code> when the number is even or an <code>ODD_MSG</code> when the number is odd. These messages were provided in the assignment. We simply need to define them in the header file (lines 23-24 in <code>ft_boolean.h</code>).

Finally, following usual convention, we will define <code>SUCCESS</code> as <code>0</code>, to indicate that the code executed with no error (i.e., successfully).

</details>

