~ include approach 1.1 and describe how to make code more succinct~
~ include approach 1.2 and describe how to outsource into 2nd function~
~ include approach 2 and describe how to use arrays~


## ft_print_comb2

|               ft_print_comb2        |
|---------------------------------|
| Turn-in directory : ex06/       |
| Files to turn in : ft_print_comb2.c |
| Allowed functions : write       |
- Create a function that displays all different combination of two two digits numbers
(XX XX) between 00 and 99, listed by ascending order.
- Here’s the expected output :
```
$>./a.out | cat -e
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>
```
- Here’s how it should be prototyped:
```
void ft_print_comb2(void);
```

<details>
<summary><h3>Testing</h3></summary>
<pre><code> int	main(void)
{
	ft_print_comb2();
	return (0);
}

 </code></pre>

See [testing file](main.c)
</details>

<details>
<summary><h3>Output</h3></summary>

This is a shortened version of the output (The full output is about 35,000 characters)
<pre><code>00 01, 00 02, 00 03, 00 04, 00 05, 00 06, 00 07, 00 08, 00 09, 00 10, 00 11, 00 12, 00 13, 00 14, 00 15, 00 16, 00 17, 00 18, 00 19, 00 20, 00 21, 00 22, 00 23, 00 24, 00 25, 00 26, 00 27, 00 28, 00 29, 00 30, 00 31, 00 32, 00 33, 00 34, 00 35, 00 36, 00 37, 00 38, 00 39, 00 40, 00 41, 00 42, 00 43, 00 44, 00 45, 00 46, 00 47, 00 48, 00 49, 00 50, 00 51, 00 52, 00 53, 00 54, 00 55, 00 56, 00 57, 00 58, 00 59, 00 60, 00 61, 00 62, 00 63, 00 64, 00 65, 00 66, 00 67, 00 68, 00 69, 00 70, 00 71, 00 72, 00 73, 00 74, 00 75, 00 76, 00 77, 00 78, 00 79, 00 80, 00 81, 00 82, 00 83, 00 84, 00 85, 00 86, 00 87, 00 88, 00 89, 00 90, 00 91, 00 92, 00 93, 00 94, 00 95, 00 96, 00 97, 00 98, 00 99, 01 02, 01 03, 01 04, 01 05, 01 06, ... , 95 96, 95 97, 95 98, 95 99, 96 97, 96 98, 96 99, 97 98, 97 99, 98 99</code></pre>

Note that <code>00 99</code> is followed by <code>01 02</code>. In other words, <code>01 00</code> is skipped because <code>00</code> is less than <code>01</code> and <code>01 01</code> is skipped since the 2-digit combinations are the same. As the first 2-digit combination 'increases', there will be fewer possible combinations for the second 2-digit combination, such that by the time the first 2-digit combination is <code>98</code>, there is only one possible combination for the second 2-digit combination (i.e., <code>99</code> to make <code>98 99</code>)
</details>

<details>
<summary><h3><b>Approach 1.1: Use 1 function and 4 variables to represent the 4 digits</b></h3></summary>
This <a href=ft_print_comb2_v1_1.c>answer</a> uses the same approach as was used for <a href=../05_ft_print_comb/ft_print_comb.c>answer</a>. In other words, it uses 4 variables to represent each of the 4 digits and then 4 <code>while</code> loops to go through each of their values. 


To try and keep this code succinct, a few tricks were used: 

However, the function remains over 25 lines long and thus not in line with The Norme. <a href=ft_print_comb2_v1_2.c>Approach 1.2</a> uses 2 functions to overcome this issue. 

</details>

<details>
<summary><h3><b>Approach 1.2: Use 2 functions and 4 variables to represent the 4 digits</b></h3></summary>
This <a href=ft_print_comb2_v1_2.c>answer</a> splits the code in <a href=ft_print_comb2_v1_1.c>Approach 1.1</a> into two functions. 


</details>
