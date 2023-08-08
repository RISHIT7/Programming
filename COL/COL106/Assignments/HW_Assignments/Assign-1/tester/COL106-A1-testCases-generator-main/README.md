# COL106-A1-testCases-generator

This repo can be used to generate test cases for COL-106-A1(implementation of set.) 2023 at IITD.

Requirements:

  python3
  
  C-compiler(gcc,g++,clang..etc)

Usage: 
<hr>
First clone the repo into your device then replace the the main.cpp dummy file with your main.cpp file.

Then move to testcases folder and compile the generator.cpp file.

run the the executable generated, and put the required info.

once the test cases are generated, move to parent folder and compile your main.cpp file.

Here after you have a few options depending on which OS you are doing this on.
<hr>
for Linux:

  you may just run the following command to see if your output differs from the expected output
  
<code>./main < ./testcases/test-1.txt | diff ./testcases/result-test-1.txt - </code>

  This command show nothing if output matches else it will show what is the difference.

  You may additionall want to redirect output to 'less' for better reading, in such case use

  <code>./main < ./testcases/test-1.txt | diff ./testcases/result-test-1.txt - | less</code>
<hr>
for Windows/Linux:
  You can output the content to a file and manullly see the difference.

  <code>./main < ./testcases/test-1.txt > ./myoutput-test-1.txt</code>

(If there is a better way to do this, fork this repo, update and do a pull request).

<hr>

The above code is for test-1 only. You may well do it for all tests you generate by executing commands one by one or by some automation code.

for example in c++ you may do a system("command") to execute a command, so you may loop over all test files you generated.

Try various combinations of generated files for better results.

Additionally explore the generator code and make modifications you like and make a pull request if you want think it generates better results.

<br><br><br>

How is result file(expeted answer) generated? Am I sharing the code this way?
<hr>
The solver.py file has the exact same statemnts as the give qn. It is doing this using sets and calling the default set functions of set class of python.

Hence no implementation of any function is being shared here.
