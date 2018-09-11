# Fan Control system
Create a program that controls the fan/ventilation system for a warehouse/office suite.
Using a menu interface, this program will ONLY turn on the system they decide to choose.
An example of the output is provided below.
After they turn the fans on, execution of the program should stop.
```
Welcome to the fan control system
The fans connected to the system:
1 - Warehouse Fan A
2 - Warehouse Fan B
3 - Office Fan system
4 - Emergency Ventilation
0 - Exit program
Please select which fans you want to turn on by entering a number 0-4: 3
Office Fan system is now turned on
Thank you for using the fan control system!
```

# Various Outputs
Since there are a variety of inputs the user could submit, your menu prompt should display the right
message that corresponds to the user's choice.

If they input 1 then the output should be:
```
  Warehouse Fan A is now turned on
```
If they input 2 then the output should be:
```
  Warehouse Fan B is now turned on
```
If they input 3 then the output should be:
```
  Office Fan system is now turned on
```
If they input 4 then the output should be:
```
  Emergency Ventilation is now turned on - Please Evacuate the building
```
If they input 0 then the output should be:
```
  Exiting program
```
If they input ANY OTHER INTEGER the output should be:
```
  ***Invalid menu option***
  Please run the program again and select a valid option!
```

THEN the function should say goodbye to the user at the end:
```
  Thank you for using the fan control system!
```

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `g++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `prob1.cc` and into the executable file `prob1`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 prob1.cc -o prob1
./prob1
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.    
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
