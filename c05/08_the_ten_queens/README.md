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

This solution:

- declares <code>arr</code>, an array of 10 <code>int</code>, to hold candidate solutions (line 95). This is initialised to an array of 0's (obviously a wrong solution) but we'll use <code>ft_check_print</code> to cycle through other candidate solutions (line 99-101).
- uses <code>count</code> to keep track of the number of correct solutions. This is initialised to <code>0</code> (line 102). 
- uses <code>i</code> to index <code>arr</code> so that each <code>int</code> in <code>arr</code> will be incremented from <code>0</code> to <code>9</code>, to cover the possible rows a queen can be in. 
- <code>ft_check_print</code> is used to check that the values in <code>arr</code> are correct (using helper functions <code>ft_samerow</code> and <code>ft_diag</code>) (line 68). 
- <code>ft_check_print</code> also iterates through candidate solutions (line 66-90).
- When a correct solution is found (and stored in <code>arr</code>), <code>ft_print_array</code> is called to display the <code>int</code> values in <code>arr</code> (line 74). 
- Finally, <code>ft_ten_queens_puzzle</code> returns the updated value of <code>count</code>, after <code>ft_check_print</code> has finished iterating through the candidate solutions. 

<h4>Checks of <code>arr[i]</code> using <code>ft_samerow</code> and <code>ft_diag</code></h4>

Let's first talk through the helper functions to <code>ft_check_print</code>, starting with <code>ft_samerow</code> and <code>ft_diag</code>. After <code>arr[i]</code> is assigned a certain <code>int</code> (from <code>0</code> to <code>9</code>) (in essence, placing a queen in a given row in column <code>i</code>), these two functions check that this queen is not on the same row (<code>ft_samerow</code>) nor at the same diagonal (<code>ft_diag</code>) as a previously placed queen. 

<code>ft_samerow</code> uses <code>j</code> and a <code>while</code> loop to index <code>arr</code> (starting from the first element, <code>j = 0</code>, and ending before <code>i</code>, <code>j = i - 1</code>) (line 22-23). <code>arr[j]</code> is then compared to <code>arr[i]</code> (line 24): 
- where they are the same, <code>ft_samerow</code> returns 0 (line 25).
- If the function finishes the iteration of <code>j</code> until <code>j = i - 1</code>, it means that <code>arr</code> did not contain a queen in the same row as the newly placed queen in column <code>i</code>. At this point, <code>ft_samerow</code> returns <code>1</code> (line 28). 

Note as well that if <code>i == 0</code>, <code>ft_samerow</code> returns <code>1</code> immediately (line 19-20) - this is the case where we are placing the very first queen on the board (in the very first column, <code>i == 0</code>) and there is no way that this queen could conflict with the other (non-existent) queens. 

<code>ft_diag</code> uses a similar logic to return <code>1</code> when <code>i == 0</code>. It also uses a <code>while</code> loop and <code>j</code> in a similar way. The key difference is that the comparison between <code>arr[j]</code> and <code>arr[i]</code> is slightly more involved in <code>ft_diag</code>:
- <code>arr[i] == arr[j] + i - j</code> checks whether the newly placed queen (<code>arr[i]</code>) has another queen diagonally from it, specifically one that is top-left of <code>arr[i]</code>. 
- <code>arr[i] == arr[j] + j - i</code> also checks whether the newly placed queen has another queen diagonally from it but this time one whether there is one that is bottom-right to <code>arr[i]</code>.
If either of the above conditions hold true, <code>ft_diag</code> returns <code>0</code>. If not, the function eventually returns <code>1</code>.

<h4>Printing correct solutions using <code>ft_print_array</code></h4>
When a candidate solution turns out to be correct, <code>ft_print_array</code> is called to display the <code>int</code> in <code>arr</code>. This is a simple function that iterates through each <code>int</code> in <code>arr</code>, adds <code>'0'</code> to it, before writing it to standard output. 

Just remember to add a new line at the end of each displayed solution!

<h4>Iterating through candidate solutions using <code>ft_check_print</code></h4>

Now for the main event: <code>ft_check_print</code>. The logic of this function is:
- We start with all the queens on the board in the first row. This was initialised in <code>ft_ten_queens_puzzle</code> and passed into <code>ft_check_print</code>.
- Everytime we place a queen on the board, we assess whether it can be in that row based on whether it is in the same row or diagonal as an existing queen (i.e., the queens placed in the columns left of it). We make this assessment starting from the left (line 68).
- If these checks are passed:
	- We leave the queen in that row and move on to the next column (by incrementing <code>i</code>) (lines 70-79). We iterate through this process for the next column as well.
	- However, if we have already placed all the queens on the board, we shouldn't iterate <code>i</code> anymore. Instead, we have found a correct solution and can display it using <code>ft_print_array</code> (lines 74).
	- To move from this correct solution to other candidate solutions, we reset the queen in the last column to the first row (<code>arr[i] = 0</code> in line 76). There's no need to shift this last queen to another row - there cannot be another correct solution with this last queen in a different row (all these other rows have been taken up). We move to the previous column (<code>i--</code> in line 76) and shift that queen down a row (<code>arr[i]++</code> in line 78)
- If these checks fail (i.e., there is a queen in the same row or along the same diagonal):
	- <code>arr[i]</code> is incremented and we place a queen in the next row (lines line 82-83)
	- we cannot increment arr[i] anymore, we reset the queen in column i to the first row (<code>arr[i] = 0</code> in line 86) and move back to the previous column (<code>i--</code> in line 86). In this column, we move the queen down a row using <code>arr[i]++</code> (line 87).
- Broadly, we move across columns from left to right to find new candidate solutions and when a candidate solution proves to be infeasible, we reset and backtrack. 
- We want these checks and iterations to continue until we backtrack so much that we are back in the first column and we are attempting to the queen in the first column off the board (i.e., arr[0] = 10)!

Working through a 4x4 board (i.e., a Four Queens Puzzle) may make it easier to understand this function. This is covered in the sub-section below. It's a long example (you were warned) but it manually runs through the entire process of finding the correct solutions and eliminating the incorrect ones. It demonstrates how the queens should be moved to get to a correct solution, how to move from a correct solution to the next one and how to know when to terminate the entire process and call it a day!

Finally, note that we could have declared and initialised <code>i</code> in <code>ft_check_print</code> and it would be my preference to keep it this way but this was done in <code>ft_ten_queens_puzzle</code> so that each function remains 25 lines or shorter. 

<details>
<summary> <h5> (Optional) Broad logic of <code>ft_check_print</code> using a 4x4 board </h5></summary>

Let's use a 4x4 board to illustrate the broad logic of <code>ft_check_print</code>. 

- Let's start by placing all the queens on the board - unorthodox, I know, but we have to start somewhere. In the 4x4 board below, all 4 queens are placed in the first row. Let's also label these queens - Q<sub>1</sub> is the queen in the first column, Q<sub>2</sub> the queen in the second column, etc. Note that this board can also be represented in an array of <code>int</code>: <code>arr[4] = {0, 0, 0, 0}</code>.

	We first consider Q<sub>1</sub> and check whether it is in the same row or diagonal as another queen that comes before it. However, since we are considering the very first column, there is simply no other queen that comes before this one. Hence, we move on to the next column. 

	| Q<sub>1</sub> | Q<sub>2</sub> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | -- | -- |
	| -- | -- | -- | -- |
	| -- | -- | -- | -- | 

- In the next column, Q<sub>2</sub> clearly can't be there since it's in the same row as Q<sub>1</sub>. Let's try the next row. Now, <code>arr = {0, 1, 0, 0}</code>. 

	| Q<sub>1</sub> | <s>Q<sub>2</sub></s> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | <b>Q<sub>2</sub></b> | -- | -- |
	| -- | -- | -- | -- |
	| -- | -- | -- | -- | 

- The next row isn't any better since Q<sub>2</sub> is along the same diagonal as Q<sub>1</sub>. We try the next row. Now, <code>arr = {0, 2, 0, 0}</code>. 

	| Q<sub>1</sub> | <s>Q<sub>2</sub></s> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | -- | -- |
	| -- | <b>Q<sub>2</sub></b> | -- | -- |
	| -- | -- | -- | -- | 	
	
- Oh, this row works! Let's tidy up the second column (by removing the strikethroughs) and move to the next column. 
	
	As before, we check whether Q<sub>3</sub> makes sense where it is. And nope, it's in the same row as Q<sub>1</sub>. Let's strike it out and consider the next row. Now, <code>arr = {0, 2, 1, 0}</code>. 

	| Q<sub>1</sub> | -- | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <b>Q<sub>3</sub></b> | -- |
	| -- | <b>Q<sub>2</sub></b> | -- | -- |
	| -- | -- | -- | -- | 

- Oh no, Q<sub>3</sub> is in the same diagonal as Q<sub>2</sub>. Next row then. Now, <code>arr = {0, 2, 2, 0}</code>.  

	| Q<sub>1</sub> | -- | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | <b>Q<sub>2</sub></b> | <b>Q<sub>3</sub></b> | -- |
	| -- | -- | -- | -- | 

- Nope, Q<sub>3</sub> is in the same row as Q<sub>2</sub>. Next row please. Now, <code>arr = {0, 2, 3, 0}</code>. 

	| Q<sub>1</sub> | -- | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | <b>Q<sub>2</sub></b> | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | -- | <b>Q<sub>3</sub></b> | -- | 

- Now Q<sub>3</sub> is in the same diagonal as Q<sub>2</sub> again and we've run out of rows. This means that there are no correct solutions with Q1 and Q2 where they are (i.e., a correct solution would not have <code>arr[0] = 0</code> and <code>arr[1] = 2</code>).

	We reset Q<sub>3</sub> to the first row and move Q<sub>2</sub> to the next row. Now, <code>arr = {0, 3, 0, 0}</code>. 

	It seems okay to put Q<sub>2</sub> there (it's neither on the same row nor diagonal as Q<sub>1</sub>). So let's work on Q<sub>3</sub> again.

	| Q<sub>1</sub> | -- | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | -- | -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | -- | -- | 
	| -- | <b>Q<sub>2</sub></b> | -- | -- |

- Q<sub>3</sub> can't be in the same row as Q<sub>1</sub> so we consider the next row. Q<sub>3</sub> seems good in that second row, so let's work on Q<sub>4</sub>. Now, <code>arr = {0, 2, 1, 0}</code>. 

	| Q<sub>1</sub> | -- | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <b>Q<sub>3</sub></b> | -- |
	| -- | -- | -- | -- | 
	| -- | <b>Q<sub>2</sub></b> | -- | -- |

- Let's speed this up a little: There doesn't seem to be a suitable row for Q<sub>4</sub> - it will always be in the same row or same diagonal as one of the previously placed queens. Let's rewind.

	| Q<sub>1</sub> | -- | -- | <s>Q<sub>4</sub></s> |
	| -- | -- | -- | -- |
	| -- | -- | <b>Q<sub>3</sub></b> | <s><b>Q<sub>4</sub></b></s> |
	| -- | -- | -- | <s><b>Q<sub>4</sub></b></s> | 
	| -- | <b>Q<sub>2</sub></b> | -- | <s><b>Q<sub>4</sub></b></s> |

- We reset Q<sub>4</sub>the first row and work on Q<sub>3</sub> again. But oh no, the subsequent rows aren't any better since Q<sub>3</sub> will be in the same diagonal or row as Q<sub>1</sub> and Q<sub>2</sub>. We have to rewind some more. 

	But Q<sub>2</sub> is already in the last possible row. Sigh, more rewinding then. We return to work on Q<sub>1</sub>.

	| Q<sub>1</sub> | -- | -- | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- | 
	| -- | <s><b>Q<sub>2</sub></b></s> | <s><b>Q<sub>3</sub></b></s> | -- |

- We move Q<sub>1</sub> to the next row. Note that as we back-tracked, we reset Q<sub>2</sub> and Q<sub>3</sub> by placing them in the first row. As before, Q<sub>1</sub> will not be in the same row or diagonal as a previously placed queen (since these don't exist). Now, <code>arr = {1, 0, 0, 0}</code>. 

	| <s>Q<sub>1</sub></s> | Q<sub>2</sub> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| <b>Q<sub>1</sub></b> | -- | -- | -- |
	| -- | -- | -- | -- |
	| -- | -- | -- | -- |

- We move Q<sub>1</sub> to the next row. Note that as we back-tracked, we reset Q<sub>2</sub> and Q<sub>3</sub> by placing them in the first row. As before, Q<sub>1</sub> will not be in the same row or diagonal as a previously placed queen (since these don't exist). We can move on to work on Q<sub>2</sub>. 

	Q<sub>2</sub> cannot be in the first three rows as it will be in the same row or diagonal as Q<sub>1</sub>, but the last row works! 

	Let's work on Q<sub>3</sub>. Wait a minute, is Q<sub>3</sub> fine exactly where it is? Yes! 

	Okay, let's move on to Q<sub>4</sub>. Now, <code>arr = {1, 3, 0, 0}</code>. 

	| -- | <s>Q<sub>2</sub></s> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| <b>Q<sub>1</sub></b> | <s><b>Q<sub>2</sub></b></s> | -- | -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | -- | -- |
	| -- | <b>Q<sub>2</sub></b> | -- | -- |
	
- Q4 can't be in the same row as Q3 but the next row is perfectly fine. We've finally arrived at our first correct solution: <code>arr = {1, 3, 0, 2}</code>.

	| -- | -- | Q<sub>3</sub> | <s>Q<sub>4</sub></s> |
	| -- | -- | -- | -- |
	| <b>Q<sub>1</sub></b> | -- | -- | <b>Q<sub>4</sub></b> |
	| -- | -- | -- | -- |
	| -- | <b>Q<sub>2</sub></b> | -- | -- |

- To continue iterating, we reset Q<sub>4</sub> and go back to Q<sub>3</sub>. We don't bother iterating through other rows for Q<sub>4</sub>. This is because in the correct solution, there will only be one row where Q<sub>4</sub> can be: all the other rows are already taken! 

	But all the other rows for Q3 do not work either. We go back to Q2 but that is already in the last possible row. So back to Q1 we go. 
	
	| -- | -- | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| <b>Q<sub>1</sub></b> | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | <s><b>Q<sub>3</sub></b></s> | -- |

- We shift Q<sub>1</sub> to the next row. Q<sub>2</sub> seems good where it is too. Now we consider Q<sub>3</sub>. Now, <code>arr = {2, 0, 0, 0}</code>.

	| -- | Q<sub>2</sub> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| <s><b>Q<sub>1</sub></b></s> | -- | -- | -- | 
	| <b>Q<sub>1</sub></b> | -- | -- | -- | 
	| -- | -- | -- | -- |

- Q<sub>3</sub> can only go in the last row (else it'll be in the same row or diagonal as Q<sub>1</sub> and Q<sub>2</sub>). Now, <code>arr = {2, 0, 3, 0}</code>.

	| -- | Q<sub>2</sub> | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| <b>Q<sub>1</sub></b> | -- | <s><b>Q<sub>3</sub></b></s> | -- | 
	| -- | -- | <b>Q<sub>3</sub></b> | -- |

- Q<sub>4</sub> can't stay in the first row but the second row looks perfect. And we have our second correct solution: <code>arr = {2, 0, 3, 1}</code>. This is actually the last of the solutions but let's confirm that. 

	| -- | Q<sub>2</sub> | -- | <s>Q<sub>4</sub></s> |
	| -- | -- | -- | -- |
	| -- | -- | -- | <b>Q<sub>4</sub></b> |
	| <b>Q<sub>1</sub></b> | -- | -- | -- | 
	| -- | -- | <b>Q<sub>3</sub></b> | -- |

- We reset Q<sub>4</sub> to the first row since we'd found a correct solution. We then reset Q<sub>3</sub> as well since it's already at the last row. Q<sub>2</sub> can't be in any other row since it'll be in the same row or diagonal as Q<sub>1</sub>. We have no choice but to reset Q<sub>2</sub> as well and move Q<sub>1</sub> to the last row. Now, <code>arr = {3, 0, 0, 0}</code>.

	| -- | Q<sub>2</sub> | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | -- | -- |
	| <b>Q<sub>1</sub></b> | <s><b>Q<sub>2</sub></b></s> | -- | -- | 
	| -- | <s><b>Q<sub>2</sub></b></s> | -- | -- |

- Q<sub>2</sub> is good where it is. Going row by row, we find that the best spot for Q<sub>3</sub> is in the third row. Now, <code>arr = {3, 0, 2, 0}</code>.

	| -- | Q<sub>2</sub> | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> | -- |
	| -- | -- | <b>Q<sub>3</sub></b> | -- |
	| <b>Q<sub>1</sub></b> | -- | -- | -- |

- But unfortunately, there is nowhere for Q<sub>4</sub> to go! We reset Q<sub>4</sub> and focus on Q<sub>3</sub>. 
	

	| -- | Q<sub>2</sub> | -- | <s>Q<sub>4</sub></s> |
	| -- | -- | -- | -- |
	| -- | -- | -- | <s><b>Q<sub>4</sub></b></s> |
	| -- | -- | <b>Q<sub>3</sub></b> | <s><b>Q<sub>4</sub></b></s> |
	| <b>Q<sub>1</sub></b> | -- | -- | <s><b>Q<sub>4</sub></b></s> |

- We want to move Q<sub>3</sub> to the last row but that's the same row as Q<sub>1</sub>. Guess we have to reset Q<sub>3</sub> and move Q<sub>2</sub>

	| -- | Q<sub>2</sub> | -- | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | -- | -- |  -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> |  -- |
	| <b>Q<sub>1</sub></b> | -- | <s><b>Q<sub>3</sub></b></s> |  -- |

- But hmmm, there's nowhere for Q<sub>3</sub> to go. Let's go back to Q<sub>2</sub> and move it down the rows.

	| -- | <s>Q<sub>2</sub></s> | <s>Q<sub>3</sub></s> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | <b>Q<sub>2</sub></b> | <s><b>Q<sub>3</sub></b></s> |  -- |
	| -- | -- | <s><b>Q<sub>3</sub></b></s> |  -- |
	| <b>Q<sub>1</sub></b> | -- | <s><b>Q<sub>3</sub></b></s> |  -- |

- But wait, Q<sub>2</sub> can't go anywhere beyond that! Okay we'd normally reset Q<sub>2</sub> and shift Q<sub>1</sub> down but we can't move Q<sub>1</sub> down anymore. This signals the end of the search for candidate solutions. We'd found 2 solutions and that's all the solutions possible in a 4x4 board!

	| -- | -- | Q<sub>3</sub> | Q<sub>4</sub> |
	| -- | -- | -- | -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | -- |  -- |
	| -- | <s><b>Q<sub>2</sub></b></s> | -- |  -- |
	| <b>Q<sub>1</sub></b> | <s><b>Q<sub>2</sub></b></s> | -- |  -- |

</details>

<h4> Keeping count of the solutions</h4>

One last component: we have to return the number of correct solutions found. 

If I wasn't limited by the number of lines per function (max 25 lines per function as per The Norme), I would declare and initialise <code>count</code> within <code>ft_check_print</code>. This function will then return an <code>int</code> value for <code>ft_ten_queens_puzzle</code> to return. 

But alas, I was forced to declare and initialise <code>count</code> in <code>ft_ten_queens_puzzle</code>. For the value of <code>count</code> to be updated in <code>ft_check_print</code>, we will have to pass in the address of <code>count</code> to <code>ft_check_print</code>. Within the function, <code>countptr</code> contains this address and the value of count is updated by dereferencing <code>countptr</code> (line 75). Even though <code>ft_check_print</code> doesn't return a value, it 'returns' the value of <code>count</code> by directly updating <code>count</code> at its address. That's it!

</details>

<details>
<summary><h3>Approach 2: Identify solutions recursively</h3></summary>

If you made it through <a href=ft_ten_queens_puzzle_v1.c>Approach 1</a>, thanks for sticking with it. I used the iterative approach to figure out the <a href=ft_ten_queens_puzzle_v2.c>recursive approach</a>. A lot of the code remains the same:
- Checks of <code>arr[i]</code> using <code>ft_samerow</code> and <code>ft_diag</code>;
- Printing correct solutions using <code>ft_print_array</code>; and 
- Keeping count of the solutions.

These are all sections within Approach 1 above so please check that out. 

But this time, <code>ft_check_print</code> is set up differently with recursion, though the steps it implements is largely the same:
- it sets <code>arr[i]</code> to <code>0</code> everytime <code>ft_check_print</code> is called. Due to this, there's no need to initialise <code>arr</code> to an array of <code>0</code>'s in <code>ft_ten_queens_puzzle</code>. This time, <code>ft_check_print</code> will do this. Assigning <code>arr[i] = 0</code> everytime <code>ft_check_print</code> is called will also be useful to reset the queens in the first row everytime we want to backtrack - more details on this below. 
- <code>ft_samerow</code> and <code>ft_diag</code> checks that the queen in column <code>i</code> isn't in the same row or diagonal as the queens in the columns up to <code>i - 1</code>. 
- If these checks aren't passed, we shift the queen in column <code>i</code> down a row by incrementing <code>arr[i]</code>(line 77).
- If <code>arr[i]</code> passes the checks, <code>ft_check_print</code> calls on itself. This time, it passes <code>i + 1</code> so that <code>ft_check_print</code> moves on to the next column, perform the same checks there and moves the queen in column <code>i + 1</code> down the rows as needed. 
- A correct solution is reached when <code>ft_check_print(arr, 9, countptr)</code> calls <code>ft_check_print(arr, 10, countptr)</code>. Of course, <code>i = 10</code> refers to something off the board. Within <code>ft_check_print(arr, 10, countptr)</code> We should stop the iteration and print the correct solution we have in <code>arr</code> (line 68 using <code>ft_print_array</code>). At the same time, we add to <code>count</code> (line 67).
- After the correct solution is reached, control returns from <code>ft_check_print(arr, 10, countptr)</code> to <code>ft_check_print(arr, 9, countptr)</code> which continues iterating through values of <code>arr[9]</code> i.e., shifting the queen in this last column through the rows. This differs to <a href=ft_ten_queens_puzzle_v1.c>Approach 1</a> where this is skipped. 
- Eventually, <code>ft_check_print(arr, 9, countptr)</code> will finish iterating <code>arr[9]</code>, so that control returns to <code>ft_check_print(arr, 8, countptr)</code>. As <code>ft_check_print(arr, 8, countptr)</code> iterates through values of <code>arr[8]</code>, it will call on <code>ft_check_print(arr, 9, countptr)</code> which will have <code>arr[9]</code> reset to <code>0</code> initially. This is the same process as Approach 1. 
- Finally the end of the process is indicated when <code>ft_check_print(arr, 0, countptr)</code> (the original call made by <code>ft_ten_queens_puzzle</code>) has finished iterating through the values of <code>arr[0]</code>.

Ta da!

</details>

<details>
<summary><h3>Other Links</h3></summary>

- Solutions to the more general N-Queens puzzle can be found <a href="https://github.com/marsha-t/Misc-Projects/tree/main/N%20Queens%20Puzzle"/>here</a>. These solutions were created before tackling the Ten Queens Puzzle since I found it easier to build the function(s) for smaller values of N first. 

</details>

