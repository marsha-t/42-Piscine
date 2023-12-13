## The Ten Queens

|               The Ten Queens        |
|---------------------------------|
| Turn-in directory : ex08/       |
| Files to turn in : ft_ten_queens_puzzle.c |
| Allowed functions : write       |

- Create a function that displays all possible placements of the ten queens on a chessboard which would contain ten columns and ten lines, without them being able to reach each other in a single move, and returns the number of possibilities.
- Recursivity is required to solve this problem.
- Here’s how it should be prototyped :
```
int ft_ten_queens_puzzle(void);
```
- Here’s how it’ll be displayed :

<pre><code>$&gt./a.out | cat -e
0257948136$
0258693147$
...
4605713829$
4609582731$
...
9742051863$
$&gt</code></pre>

- The sequence goes from left to right. The first digit represents the first Queen’s position in the first column (the index starting from 0). The Nth digit represents the Nth Queen’s position in the Nth column.
- The return value must be the total number of displayed solutions.


<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include &ltstdio.h&gt
int main(void)
{
	printf("count: %d\n", ft_ten_queens_puzzle());
	return (0);
}</code></pre>

See [testing file](main.c)

</details>

<details>
<summary><h3>Output</h3></summary>

As there are 725 lines of output, I've shortened it to show only the first and last 5 solutions. 

<pre><code>0257948136
0258693147
0258693174
0286931475
0358297146
...
9641702853
9713068524
9741306825
9741306852
9742051863
count: 724</code></pre>

</details>

<details>
<summary><h3>Approach 1: Identify solutions iteratively</h3></summary>

This <a href=ft_ten_queens_puzzle_v1.c>approach</a> identifies the various (724 to be exact) solutions to the Ten Queens Puzzle iteratively, without the use of recursion. The assignment specified the use of recursion but I found this solution to be more intuitive (at least for now). From this solution, I built the next solution (<a href=ft_ten_queens_puzzle_v2>Approach 2</a>) based on recursion. 

</details>

<details>
<summary><h3>Approach 2: Identify solutions recursively</h3></summary>

This <a href=ft_ten_queens_puzzle_v2.c>approach</a> 

</details>

<details>
<summary><h3>Other Links</h3></summary>
- Solutions to the more general N-Queens puzzle can be found <a href="https://github.com/marsha-t/Misc-Projects/tree/main/N%20Queens%20Puzzle"/>here</a>. These solutions were actually created before the solutions for the Ten Queens Puzzle since I found it easier to build for the Four Queens and the Five Queens Puzzles first. 

</details>

