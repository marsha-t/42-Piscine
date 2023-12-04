## ft_sort_params

|               ft_sort_params        |
|---------------------------------|
| Turn-in directory : ex03/       |
| Files to turn in : ft_sort_params.c |
| Allowed functions : write       |

- We’re dealing with a <u>program</u> here, you should therefore have a function <code>main</code> in your .c file.
- Create a program that displays its given arguments sorted by ascii order.
- It should display all arguments, except for <code>argv[0]</code>.
- One argument per line.

<details>

<summary><h3>Testing</h3></summary>

<pre><code>$>./a.out a ab 34 C Z | cat -e</code></pre>

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>34$
C$
Z$
a$
ab$</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This <a href=ft_sort_params.c>exercise</a> sorts the strings in <code>argv</code> in place (except for the program name in <code>argv[0]</code>) before displaying the program names. 

Two while loops are used to compare one string with all the strings that come after it. The first <code>while</code> loop goes through the strings starting from the 2nd element (<code>i = 1</code>) (lines 50-65). The second <code>while</code> loop goes through all the strings that come after the string in question. To compare strings, <code>ft_strcmp</code> is used. This function returns a positive value when the first string passed is greater than the second. In this case, this function will alert us to cases where the strings are not in order. In such cases, we swap the strings (lines 58-61).

To be precise, in lines 58-61, addresses are swapped. Technically, <code>argv</code> holds character pointers rather than strings so <code>argv[i]</code> contains a pointer to a string for the <code>i</code>th argument passed into the command line. Hence, in line 58, <code>temp</code> is assigned the <code>i</code>th character pointer in <code>argv</code>. The <code>i</code>th character pointer in <code>argv</code> is replaced with the <code>j</code>th character pointer in line 59. Finally in line 60, we replace the <code>j</code>th character pointer with the character pointer that was saved in <code>temp</code>. 

Note that swap or no swap, the second <code>while</code> loop goes through all the character pointers that come after the <code>i</code>th character pointer.

After sorting, we simply display the parameters using <code>ft_write_arg</code>. This is relatively straightforward and reuses code from <a href=../01_ft_print_params>ft_print_params</a>.

</details>

