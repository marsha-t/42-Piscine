## Makefile

|               Makefile        |
|---------------------------------|
| Turn-in directory : ex01/       |
| Files to turn in : Makefile |
| Allowed functions : None       |

- Create the <code>Makefile</code> that’ll compile a library <code>libft.a</code>.
- Your makefile should print all the command it’s running.
- Your makefile should not run any unnecessary command.
- The <code>Makefile</code> will get its source files from the "srcs" directory.
- Those files will be: <code>ft_putchar.c</code>, <code>ft_swap.c</code>, <code>ft_putstr.c</code>, <code>ft_strlen.c</code>, <code>ft_strcmp.c</code>
- The <code>Makefile</code> will get its header files from the "includes" directory.
- Those files will be: <code>ft.h</code>
- It should compile the <code>.c</code> files with <code>cc</code> and with <code>-Wall -Wextra -Werror</code> flags in that order.
- The lib should be at the root of the exercise.
- <code>.o</code> files should be near their <code>.c</code> file.
- The <code>Makefile</code> should also implement the following rules: <code>clean</code>, <code>fclean</code>, <code>re</code>, <code>all</code> and of course <code>libft.a</code>.
- Running just <code>make</code> should be equal to <code>make all</code>
- The rule <code>all</code> should be equal to make <code>libft.a</code>.
- The rule <code>clean</code> should remove all the temporary generated files. The rule <code>fclean</code> should be like a <code>make clean</code> plus all the binary made with <code>make all</code>.
- The rule <code>re</code> should be like a <code>make fclean</code> followed by <code>make all</code>.
- Your makefile should not compile any file for nothing.
- We’ll only fetch your <code>Makefile</code> and test it with our files.

<details>

<summary><h3>Testing</h3></summary>

- Run make in the terminal
- It should have created a <code>libft.a</code> file. 
- Check that the functions can be accessed via <code>libft.a</code> by first compiling a test program: <code>gcc main.c libft.a -Iincludes</code>
	- <a href=main.c>main.c</a> contains code to use all five functions. 
	- <code>-Iincludes</code> is to indicate the directory where the header file is located
- Execute the program using <code>./a.out</code>

</details>

<details>
<summary><h3>Output</h3></summary>

<pre><code>a
abc
3
2
1
0</code></pre>

</details>

<details>
<summary><h3>Approach</h3></summary>

This objective of this exercise is the same as the last <a href=../00_libft>one</a> except we will use a <code>Makefile</code> instead. 

<h4>Ingredients in a Makefile</h4>

The <a href=Makefile>Makefile</a>:
- has some variables defined in lines 1-5;
- has 7 rules (lines 7-23): <code>all</code>, <code>%o</code>, <code>libft.a</code>, <code>clean</code>, <code>fclean</code>, <code>re</code>, <code>.PHONY</code>

Variables in a makefile are a way to substitute text in the rule. For instance, creating a variable <code>CFLAGS</code>:
<pre><code>1	CFLAGS = -Wall -Wextra -Werror</code></pre>
and using this reference in one of the rules line 10:
<pre><code>10	gcc ${CFLAGS} -c -I $(HEADER_DIR) $< -o ${<:.c=.o}</code></pre>
is equivalent to
<pre><code>gcc -Wall -Wextra -Werror -c -I $(HEADER_DIR) $< -o ${<:.c=.o}</code></pre>

A rule is like a collection of commands: when you <code>make</code> a rule, the commands in the rule are executed. rules are typically used to create a file of the same name as the rule but a rule <u>need not</u> create a file. For instance, <code>clean</code> is a rule in the makefile and when it is 'made' (by running <code>make clean</code> in the terminal), <code>rm -f $(OFILES)</code> is executed: files are being deleted instead of being created! 

Relatedly, to <code>make</code> a rule, we can combine <code>make</code> with the rule name e.g., <code>make clean</code>. We can also simply run <code>make</code>: this runs the first rule in the <code>Makefile</code>.

Final bit of preamble before we really start: pre-requisites/dependencies. The dependency of each rule is listed after the name of the rule and a colon. For instance, <code>fclean</code> is dependent on <code>clean</code>. When <code>fclean</code> is 'made' (using <code>make fclean</code>), Make finds the <code>clean</code> rule and runs the commands there.

<h4>Creating <code>libft.a</code></h4>

Now, let's start with the <code>libft.a</code> rule:

<pre><code>12	libft.a: $(OFILES)
13		ar rc libft.a $(OFILES)</code></pre>

This rule is dependent on the list of object files listed within the variable OFILES (line 3). These files do not exist yet but there is a rule to create them:

<pre><code>9	%o: %c 
10		gcc ${CFLAGS} -c -I $(HEADER_DIR) $< -o ${<:.c=.o}</code></pre>

<code>%</code> is a wildcard. When the first of the object files (<code>.src/ft_putchar.o</code>)can't be found, Make searches for a suitable rule to create it. It finds it in <code>%o</code> since this file does end with a <code>o</code>. This rule is in turn dependent on <code>%c</code> which is interpreted as <code>./src/ft_putchar.c</code>. This is an existing file. Yay, we can proceed to execute the commands under the <code>%o</code> rule i.e., use <code>gcc</code> to generate the object file (<code>.o</code>) from a source file (<code>.c</code>). Let's look at this command with all the variables substituted in for <code>ft_putchar.o</code>:

<pre><code>./src/ft_putchar.o: ./src/ft_putchar.c
	gcc -Wall -Wextra -Werror -c -I includes ./src/ft_putchar.c -o ./src/ft_putchar.o
</code></pre>

Let's break this down:
- <code>%o</code> is substituted as the first file in OFILES where <code>%</code> is a wildcard that now stands for <code>./src/ft_putchar.</code> and <code>%c</code> reuses this stub to be <code>./src/ft_putchar.c</code>
- <code>-I</code> is a <code>gcc</code> flag to specify the directory where the compiler should look for header files. The header file is in the <code>includes</code> directory, which is substituted in for <code>$(HEADER_DIR)</code>.
- <code><</code> is an automatic variable and is the name of the first pre-requisite. In this case, it is <code>./src/ft_putchar.c</code>. Note that <code>$</code> is also used here to indicate that a variable is being used here.
- <code>-o</code> is another <code>gcc</code> flag. It asks for the output to be placed in a specific file
- The output file is indicated by <code>${<:.c=.o}</code> which means to take <code>${<}</code> (i.e., the first pre-requisite)and convert the suffix <code>.c</code> with <code>.o</code>. This gives us <code>./src/ft_putchar.o</code> 

The above process is repeated for all the object files listed in OFILES. Once these files exist, we can continue executing the libft.a rule:

<pre><code>ar rc libft.a $(OFILES)</code></pre>

This is equivalent to the following code and is the same as the one used in the last <a href=../00_libft/libft_creator.sh>exercise</a>

<pre><code>ar rc libft.a ./src/ft_putchar.o ./src/ft_putstr.o ./src/ft_strcmp.o ./src/ft_strlen.o ./src/ft_swap.o</code></pre>

And that's it (in terms of creating <code>libft.a</code>).

<h4>The other rules: <code>clean</code>, <code>fclean</code>, <code>re</code>, <code>all</code></code>.</h4>

<code>clean</code> removes all the 'temporary generated files'. These are the object files. 

<code>fclean</code> has <code>clean</code> as a pre-requisite. Hence, <code>make fclean</code> will cause <code>clean</code> to be made as well. After <code>clean</code> is made, the command in <code>fclean</code> is executed i.e., to delete <code>libft.a</code> (a binary file).

Similarly, for <code>re</code> to combine <code>make fclean</code> and <code>make all</code>, <code>fclean</code> and <code>all</code> are listed as pre-requisites for the rule. 

Finally, for <code>make</code> to be equal to <code>make all</code>, <code>all</code> needs to the first rule in the file. For <code>make all</code> to be equal to <code>make libft.a</code>, it also lists <code>libft.a</code> as a pre-requisite. 

<hr>The very last rule <code>.PHONY</code></hr>

This is a special built-in target that makes sure that the specified names (e.g., <code>clean</code>) are recognised as target names rather than file names. For instance, if there was an existing file called <code>clean</code>, and we run <code>make clean</code>, the <code>clean</code> rule will not work and its commands will not be executed. 

</details>

