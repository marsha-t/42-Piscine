## ft_print_combn

|               ft_print_combn        |
|---------------------------------|
| Turn-in directory : ex08/       |
| Files to turn in : ft_print_combn.c |
| Allowed functions : write       |
- Create a function that displays all different combinations of n numbers by ascending order.
- n will be so that : 0 < n < 10.
- If n = 2, here’s the expected output :
```
$>./a.out | cat -e
01, 02, 03, ..., 09, 12, ..., 79, 89$>
```
- Here’s how it should be prototyped :

```
void ft_print_combn(int n);
```


<details>
<summary><h3>Testing</h3></summary>
	
<pre><code>#include &ltunistd.h&gt
int	main(void)
{
	write(1, "n = 1\n", 6);
	ft_print_combn(1);
	write(1, "\nn = 2\n", 7);
	ft_print_combn(2);
	write(1, "\nn = 3\n", 7);
	ft_print_combn(3);
	write(1, "\nn = 4\n", 7);
	ft_print_combn(4);
	write(1, "\nn = 5\n", 7);
	ft_print_combn(5);
	write(1, "\nn = 6\n", 7);
	ft_print_combn(6);
	write(1, "\nn = 7\n", 7);
	ft_print_combn(7);
	write(1, "\nn = 8\n", 7);
	ft_print_combn(8);
	write(1, "\nn = 9\n", 7);
	ft_print_combn(9);
	return (0);
}</code></pre>

See [testing file](main.c)

</details>


<details>
<summary><h3>Output</h3></summary>

The output has been separated into separate sections:

<details>
<summary><code>n = 1</code></summary>
<pre><code>n = 1
0, 1, 2, 3, 4, 5, 6, 7, 8, 9</code></pre>

</details>

<details>
<summary><code>n = 2</code></summary>
<pre><code>n = 2
01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89</code></pre>

</details>

<details>
<summary><code>n = 3</code></summary>
<pre><code>n = 3
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789</code></pre>

</details>

<details>
<summary><code>n = 4</code></summary>
<pre><code>n = 4
0123, 0124, 0125, 0126, 0127, 0128, 0129, 0134, 0135, 0136, 0137, 0138, 0139, 0145, 0146, 0147, 0148, 0149, 0156, 0157, 0158, 0159, 0167, 0168, 0169, 0178, 0179, 0189, 0234, 0235, 0236, 0237, 0238, 0239, 0245, 0246, 0247, 0248, 0249, 0256, 0257, 0258, 0259, 0267, 0268, 0269, 0278, 0279, 0289, 0345, 0346, 0347, 0348, 0349, 0356, 0357, 0358, 0359, 0367, 0368, 0369, 0378, 0379, 0389, 0456, 0457, 0458, 0459, 0467, 0468, 0469, 0478, 0479, 0489, 0567, 0568, 0569, 0578, 0579, 0589, 0678, 0679, 0689, 0789, 1234, 1235, 1236, 1237, 1238, 1239, 1245, 1246, 1247, 1248, 1249, 1256, 1257, 1258, 1259, 1267, 1268, 1269, 1278, 1279, 1289, 1345, 1346, 1347, 1348, 1349, 1356, 1357, 1358, 1359, 1367, 1368, 1369, 1378, 1379, 1389, 1456, 1457, 1458, 1459, 1467, 1468, 1469, 1478, 1479, 1489, 1567, 1568, 1569, 1578, 1579, 1589, 1678, 1679, 1689, 1789, 2345, 2346, 2347, 2348, 2349, 2356, 2357, 2358, 2359, 2367, 2368, 2369, 2378, 2379, 2389, 2456, 2457, 2458, 2459, 2467, 2468, 2469, 2478, 2479, 2489, 2567, 2568, 2569, 2578, 2579, 2589, 2678, 2679, 2689, 2789, 3456, 3457, 3458, 3459, 3467, 3468, 3469, 3478, 3479, 3489, 3567, 3568, 3569, 3578, 3579, 3589, 3678, 3679, 3689, 3789, 4567, 4568, 4569, 4578, 4579, 4589, 4678, 4679, 4689, 4789, 5678, 5679, 5689, 5789, 6789</code></pre>

</details>

<details>
<summary><code>n = 5</code></summary>
<pre><code>n = 5
01234, 01235, 01236, 01237, 01238, 01239, 01245, 01246, 01247, 01248, 01249, 01256, 01257, 01258, 01259, 01267, 01268, 01269, 01278, 01279, 01289, 01345, 01346, 01347, 01348, 01349, 01356, 01357, 01358, 01359, 01367, 01368, 01369, 01378, 01379, 01389, 01456, 01457, 01458, 01459, 01467, 01468, 01469, 01478, 01479, 01489, 01567, 01568, 01569, 01578, 01579, 01589, 01678, 01679, 01689, 01789, 02345, 02346, 02347, 02348, 02349, 02356, 02357, 02358, 02359, 02367, 02368, 02369, 02378, 02379, 02389, 02456, 02457, 02458, 02459, 02467, 02468, 02469, 02478, 02479, 02489, 02567, 02568, 02569, 02578, 02579, 02589, 02678, 02679, 02689, 02789, 03456, 03457, 03458, 03459, 03467, 03468, 03469, 03478, 03479, 03489, 03567, 03568, 03569, 03578, 03579, 03589, 03678, 03679, 03689, 03789, 04567, 04568, 04569, 04578, 04579, 04589, 04678, 04679, 04689, 04789, 05678, 05679, 05689, 05789, 06789, 12345, 12346, 12347, 12348, 12349, 12356, 12357, 12358, 12359, 12367, 12368, 12369, 12378, 12379, 12389, 12456, 12457, 12458, 12459, 12467, 12468, 12469, 12478, 12479, 12489, 12567, 12568, 12569, 12578, 12579, 12589, 12678, 12679, 12689, 12789, 13456, 13457, 13458, 13459, 13467, 13468, 13469, 13478, 13479, 13489, 13567, 13568, 13569, 13578, 13579, 13589, 13678, 13679, 13689, 13789, 14567, 14568, 14569, 14578, 14579, 14589, 14678, 14679, 14689, 14789, 15678, 15679, 15689, 15789, 16789, 23456, 23457, 23458, 23459, 23467, 23468, 23469, 23478, 23479, 23489, 23567, 23568, 23569, 23578, 23579, 23589, 23678, 23679, 23689, 23789, 24567, 24568, 24569, 24578, 24579, 24589, 24678, 24679, 24689, 24789, 25678, 25679, 25689, 25789, 26789, 34567, 34568, 34569, 34578, 34579, 34589, 34678, 34679, 34689, 34789, 35678, 35679, 35689, 35789, 36789, 45678, 45679, 45689, 45789, 46789, 56789</code></pre>

</details>

<details>
<summary><code>n = 6</code></summary>
<pre><code>n = 6
012345, 012346, 012347, 012348, 012349, 012356, 012357, 012358, 012359, 012367, 012368, 012369, 012378, 012379, 012389, 012456, 012457, 012458, 012459, 012467, 012468, 012469, 012478, 012479, 012489, 012567, 012568, 012569, 012578, 012579, 012589, 012678, 012679, 012689, 012789, 013456, 013457, 013458, 013459, 013467, 013468, 013469, 013478, 013479, 013489, 013567, 013568, 013569, 013578, 013579, 013589, 013678, 013679, 013689, 013789, 014567, 014568, 014569, 014578, 014579, 014589, 014678, 014679, 014689, 014789, 015678, 015679, 015689, 015789, 016789, 023456, 023457, 023458, 023459, 023467, 023468, 023469, 023478, 023479, 023489, 023567, 023568, 023569, 023578, 023579, 023589, 023678, 023679, 023689, 023789, 024567, 024568, 024569, 024578, 024579, 024589, 024678, 024679, 024689, 024789, 025678, 025679, 025689, 025789, 026789, 034567, 034568, 034569, 034578, 034579, 034589, 034678, 034679, 034689, 034789, 035678, 035679, 035689, 035789, 036789, 045678, 045679, 045689, 045789, 046789, 056789, 123456, 123457, 123458, 123459, 123467, 123468, 123469, 123478, 123479, 123489, 123567, 123568, 123569, 123578, 123579, 123589, 123678, 123679, 123689, 123789, 124567, 124568, 124569, 124578, 124579, 124589, 124678, 124679, 124689, 124789, 125678, 125679, 125689, 125789, 126789, 134567, 134568, 134569, 134578, 134579, 134589, 134678, 134679, 134689, 134789, 135678, 135679, 135689, 135789, 136789, 145678, 145679, 145689, 145789, 146789, 156789, 234567, 234568, 234569, 234578, 234579, 234589, 234678, 234679, 234689, 234789, 235678, 235679, 235689, 235789, 236789, 245678, 245679, 245689, 245789, 246789, 256789, 345678, 345679, 345689, 345789, 346789, 356789, 456789</code></pre>

</details>

<details>
<summary><code>n = 7</code></summary>
<pre><code>n = 7
0123456, 0123457, 0123458, 0123459, 0123467, 0123468, 0123469, 0123478, 0123479, 0123489, 0123567, 0123568, 0123569, 0123578, 0123579, 0123589, 0123678, 0123679, 0123689, 0123789, 0124567, 0124568, 0124569, 0124578, 0124579, 0124589, 0124678, 0124679, 0124689, 0124789, 0125678, 0125679, 0125689, 0125789, 0126789, 0134567, 0134568, 0134569, 0134578, 0134579, 0134589, 0134678, 0134679, 0134689, 0134789, 0135678, 0135679, 0135689, 0135789, 0136789, 0145678, 0145679, 0145689, 0145789, 0146789, 0156789, 0234689, 0234789, 0235678, 0235679, 0235689, 0235789, 0236789, 0245678, 0245679, 0245689, 0245789, 0246789, 0256789, 0345678, 0345679, 0345689, 0345789, 0346789, 0356789, 0456789, 1234567, 1234568, 1234569, 1234578, 1234579, 1234589, 1234678, 1234679, 1234689, 1234789, 1235678, 1235679, 1235689, 1235789, 1236789, 1245678, 1245679, 1245689, 1245789, 1246789, 1256789, 1345678, 1345679, 1345689, 1345789, 1346789, 1356789, 1456789, 2345678, 2345679, 2345689, 2345789, 2346789, 2356789, 2456789, 3456789</code></pre>

</details>

<details>
<summary><code>n = 8</code></summary>
<pre><code>n = 8
01234567, 01234568, 01234569, 01234578, 01234579, 01234589, 01234678, 01234679, 01234689, 01234789, 01235678, 01235679, 01235689, 01235789, 01236789, 01245678, 01245679, 01245689, 01245789, 01246789, 01256789, 01345678, 01345679, 01345689, 01345789, 01346789, 01356789, 01456789, 02345678, 02345679, 02345689, 02345789, 02346789, 02356789, 02456789, 03456789, 12345678, 12345679, 12345689, 12345789, 12346789, 12356789, 12456789, 13456789, 23456789</code></pre>

</details>

<details>
<summary><code>n = 9</code></summary>
<pre><code>n = 9
012345678, 012345679, 012345689, 012345789, 012346789, 012356789, 012456789, 013456789, 023456789, 123456789</code></pre>

</details>

</details>

<details>
<summary><h3>Approach</code></h3></summary>

Before coding the solution, I thought about how I would manually complete the task. For 3 digits, I would 
1. Start with the initial combination. This combination is always in ascending order starting from 0. With 3 digits, I start with <code>012</code>.
2. The next combination is reached by incrementing the last digit in the combination e.g., <code>013</code>, <code>014</code>, etc. 
3. When the last digit is already <code>9</code> (<code>019</code>), I increment the penultimate digit and reset the last digit to be one higher than the penultimate digit (<code>023</code>).
4. Repeat steps 2 and 3 to get <code>024</code>, ..., <code>029</code>, <code>034</code>, ..., <code>039</code>, <code>045</code>, ... until the penultimate digit reaches <code>8</code> (<code>089</code>); 
5. When the penultimate digit is already <code>8</code>, I increment the next digit from the end (which is now the first digit in the combination) and reset the other digits to be one higher than the digit on the left: <code>123</code>.
6. Repeat steps 2, 3 and 5 to get <code>124</code>, ..., <code>129</code>, <code>134</code>, ..., <code>189</code>, <code>234</code>, ... until the first digit reaches <code>7</code>: <code>789</code>. The end!

Before we begin coding, being able to identify the final combination will also be handy. The table below shows the final combination for different values of <code>n</code> - by staring at it for a bit, you'd realise that the first digit is always <code>10 - n</code>.
 
| n | Final Combination |
|--| --|
| 1 | 9 |
| 2 | 89 |
| 3 | 789 |
| 4 | 6789 | 
| 5 | 56789 | 
| 6 | 456789 |
| 7 | 3456789 |
| 8 | 23456789 |
| 9 | 123456789 |


Now we are ready to begin and can use the above to create a <a href=ft_print_combn.c>solution</a>:
- The function first declares an array with 9 elements (the maximum we will need) and initialises it to the first combination (lines 53 and 58-60). This is similar to step 1.
- A <code>while</code> loop is used to display and 'increment' the array (lines 61-68):
	- <code>ft_print_array</code> displays the array and adds comma separators;
	- If the last digit is not <code>9</code>, we increment the last digit in the array (lines 64-65). This is step 2. 
	- Otherwise, <code>ft_increment_and_reset</code> is used to increment the array. This covers steps 3 and 5.
	- The <code>while</code> loop stops when the first digit reaches <code>10 - n</code>. This is similar to conditions laid out in step 6. 
- Finally, the function also caters for unreasonable values of <code>n</code>: after all, <code>n</code> should be between 1 and 9.

Initialising the array to the first combination is simple once you realise that the digits are simply their indexes. For instance, for 3 digits, the first combination is <code>012</code>: the digit at index 0 should be <code>0</code>; index 1 should be <code>1</code> and index 2 should be <code>2</code>! In this solution, the code is streamlined further by incrementing <code>i</code> within the <code>while</code> loop - as a result, <code>i</code> is initialised at <code>-1</code> instead of the usual <code>0</code>. 

<code>ft_print_array</code> converts the digits into numeric characters by adding <code>'0'</code> to the digits. It also places a comma and a space after displaying the combination, as long as the combination is not the final combination (i.e., when the first digit is not <code>10 - n</code>). 

After displaying the array, we create the next combination by incrementing the last digit. This should be limited to cases where the last digit hasn't already reached <code>9</code>, the maximum the last digit can reach. Otherwise, we will need to 'increment' the array in a more sophisticated manner. This is accomplished via <code>ft_increment_and_reset</code>.

Within <code>ft_increment_and_reset</code>, we
- Create an array <code>max</code> which is made up of the maximums that each digit can go up to (lines 35-37). For instance, <code>max[0]</code> will contain the maximum that <code>array[0]</code> can go up to, <code>max[1]</code> the maximum that <code>array[1]</code> can go up to, etc, etc. This is also equivalent to the final combination. 
- Starting from the back of array, we locate the first instance where the digit in <code>array</code> is not already at its maximum (lines 38-40). Since we do not know how many such digits there are, we use a <code>while</code> loop. For instance, with <code>589</code>, we want to get to index 0 (where <code>5</code> is) since the digits at index 1 and 2 are already at their maximum. 
- We increment that digit (that is not at its maximum) (line 46) and reset the digits after it so that they are in ascending order, increasing by 1 each time (lines 47-48). <code>589</code> then becomes <code>678</code>.
- If <code>array</code> is the same as <code>max</code> (aka the final combination), we stop any further incrementing and set <code>array</code> to something that terminates the <code>while</code> loop in <code>ft_print_combn</code>. Note that when <code>array</code> is the same as <code>max</code>, lines 38-40 will result in <code>i = -1</code>. Hence, when <code>i == -1</code>, we set array[0] to something greater than <code>10 - n</code> (since this is the <code>while</code> loop condition in <code>ft_print_combn</code>) and exit <code>ft_increment_and_reset</code> using a <code>return</code> statement. 

Now all that's left is to cater for unreasonable values of <code>n</code>. In such situations, we simply exit the function without doing anything (lines 56-57).

</details>

