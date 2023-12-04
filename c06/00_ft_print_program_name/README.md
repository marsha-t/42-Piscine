## ft_print_program_name

|               ft_print_program_name        |
|---------------------------------|
| Turn-in directory : ex00/       |
| Files to turn in : ft_print_program_name.c |
| Allowed functions : write       |

- We’re dealing with a <u>program</u> here, you should therefore have a function <code>main</code> in your .c file.
- Create a program that displays its own name followed by a new line.
- Example :

<pre><code>$>./a.out | cat -e
./a.out$
$></code></pre>

<details>

<summary><h3>Testing</h3></summary>

<pre><code>$>./a.out | cat -e</code></pre>

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>./a.out$</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

In this <a href=ft_print_program_name.c>exercise</a>, we start using command line arguments and writing <i>programs</i> which will include the <code>main</code> function. To pass command line arguments, <code>main</code> is defined with two arguments: 
- <code>argc</code> refers to the number of command line arguments passed. However, bear in mind that the program name is a default command line argument that is passed. As a result, if we type in one command line argument, <code>argc</code> will be 2: 1 for the program name and 1 for the argument we'd passed. 
- <code>argv</code> is an array of character pointers - each pointing to an argument (expressed as a null-terminated string).

With this, we have everything we need to print the program name, which is the first element of <code>argv</code>. Since it is a null-terminated string, we can use the usual <code>while</code> loop to loop through every character in the string and display it:

<pre><code>19	i = 0;
20	while (argv[0][i] != '\0')
21	{
22		write(1, &argv[0][i], 1);
23		i++;
24	}</code></pre>

The notation is a bit more involved but it works just as <code>str[i]</code> did in previous exercises. 

So far, we've only made use of <code>argv</code> and it is all that we need. However, the compiler (when run with the usual <code>-Wall -Wextra -Werror</code> flags) will warn that an argument was not used i.e., <code>argc</code>. Now, we just have to trick the compiler into thinking that this argument was used. One often-used solution is to cast it to <code>void</code> and discard the argument.  This seems to be preferred in order to signal to others that you are aware that the function has an argument and that you have chosen to ignore it. 

Alternatively, you can always define <code>main</code> without a name for the argument - this way, the compiler knows that the argument is there but it is not used.

<pre><code>int main(int, char **argv)</code></pre>

</details>

