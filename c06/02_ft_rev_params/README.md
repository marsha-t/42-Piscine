## ft_rev_params

|               ft_rev_params        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_rev_params.c |
| Allowed functions : write       |

- We’re dealing with a <u>program</u> here, you should therefore have a function <code>main</code> in your .c file.
- Create a program that displays its given arguments.
- One per line, in the reverse order of the command line.
- It should display all arguments, except for <code>argv[0]</code>.

<details>

<summary><h3>Testing and Output</h3></summary>

<pre><code>$>./a.out test1 test2 test3 | cat -e
test3$
test2$
test1$
$>./a.out | cat -e
$
$>./a.out "." "a" "A" "0" | cat -e
0$
A$
a%
.$
</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_rev_params.c>exercise</a> reuses code from the previous exercise. To print in reverse, <code>p</code> is initialised to the last element in <code>argv</code> and decremented in the loop until it reaches the 2nd element (index of <code>1</code>). Other than that, everything remains the same!

</details>

