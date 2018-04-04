# pluQuizGames
Are you an average checker at a major Grocery Store? Use this program to up your skills by memorizing those pesky PLU numbers and level-up your checking speed.

# Build and Run

If you are on a linux machine, make sure you have the gnu compiler (g++), go into the pluQuizGames/ top folder and enter the word 'make'.

Two executables will result, buildQuiz and game.

Enter ./game in a terminal/console and the quiz will start.

# Game Play

Currently, the game will randomly choose 10 of the top 150 PLU products and will quiz you on those numbers. It will loop through these numbers 4 times in all, so if you don't know the number the first time through, it's still of benefit to try to memorize it before the next loop. 

If you get the number right then you get full points for that product. 

If you get it wrong, then a hint will be given. Each time the hint will show more and more of the number.


# Commenting out PLU's
If there is a PLU that is wrong or a product that doesn't exist in your store, then go into the pluNums1.txt file and type a \# symbol as the first character on that line. It will be ignored by the game.

# BuildQuiz
The buildQuiz program will be set up to make quizes for numbers that you wish to focus on. It can be used to make a subset of numbers that output to a file.

#Problems
The game itself is only set up to utilize pluNums1.txt. The game program is meant as a proof of concept, it may be some time before I make a GUI Game for this project. I will work on the TUI as well because I'd like to merge the two into one binary so that it can still be used on a non-gui environment.

Picking a GUI Library is my current concern. I'm currently thinking about SDL2 as the library of choice.
