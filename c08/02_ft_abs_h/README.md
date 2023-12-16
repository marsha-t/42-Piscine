## ft_abs.h

|               ft_abs.h        |
|---------------------------------|
| Turn-in directory : ex02/       |
| Files to turn in : ft_abs.h |
| Allowed functions : None       |

- Create a macro <code>ABS</code> which replaces its argument by its absolute value:

<pre><code>#define ABS(Value)</code></pre>

<details>

<summary><h3>Testing</h3></summary>

<pre><code>#include "ft_abs.h"
#include &ltstdio.h&gt
int	main(void)
{
	printf("%d\n", ABS(50));
	printf("%d\n", ABS(-50));
}</code></pre>

Note that for testing, the header file (either <a href=ft_abs_v1.h>ft_abs_v1.h</a> or <a href=ft_abs_v2.h>ft_abs_v2.h</a>) should be renamed to <code>ft_abs.h</code> since this is the library included in <a href=main.c>main.c</a>.

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>50
50</code></pre>

</details>

<details>
<summary><h3>Approach 1: Using a ternary operator</h3></summary>

This <a href=ft_abs_v1.h>approach</a> uses a conditional (or ternary) operator, which isn't allowed in The Norme (even though it was used in the <code>main.c</code> in the previous <a href=../01_ft_boolean_h>exercise</a>). Nevertheless, it's still interesting to understand how they work!

The following formulation...

<pre><code># define ABS(Value) ((Value < 0) ? -(Value) : (Value))</code></pre>

is <i>largely</i> equivalent to...

<pre><code>if (Value < 0)
	# define ABS(Value) -(Value)
else
	# define ABS(Value) (Value) </code></pre>

Note that the above is pseudo-code. Including this in the header file will cause compiler errors since it looks like we are trying to re-define ABS(Value). 

But this pseudo-code illustrates the logic underlying the conditional/ternary operator: 
- if <code>Value < 0</code>, the <code>ABS</code> macro will replace its argument with <code>-(Value)</code>. 
- Otherwise, the <code>ABS</code> macro will replace its argument with <code>(Value)</code>. 

In other words, the <code>ABS</code> macro "replaces its argument by its absolute value" as indicated in the assignment. 

</details>


<details>
<summary><h3>Approach 2: Uses arithmetic and Boolean expressions </h3></summary>

This <a href=ft_abs_v2.h>approach</a> avoids conditional (or ternary) and uses arithmetic to generate the absolute value of the <code>ABS</code> argument. 

This arithmetic relies on the fact that <code>(Value < 0)</code> evaluates to <code>1</code> when whether <code>Value</code> is negative and <code>0</code> when it is not. We then layer this with some math so that the resultant expression returns <code>-1</code> when <code>Value</code> is negative and <code>1</code> otherwise: 

<pre><code>(1 - 2 * (Value < 0))</code></pre>

- When <code>Value</code> is negative, the above is: <code>1 - (2 * 1) = -1 </code>
- When <code>Value</code> is not negative, the above is <code>1 - (2 * 0) = 1</code>

To return the absolute value, we simply have to multiply the above expression with <code>Value</code>:

<pre><code>(1 - 2 * (Value < 0)) * Value</code></pre>

</details>

