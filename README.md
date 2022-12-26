
# Hitori game GUI
This project is based on the final structures project required in the course Programming 2: Structures (C++) at Tampere University. Shortly, my work covered the content appearing in module **mainwindow** where all the **Graphical User Interface** is created for the game 2048. 
  
- **Note:** This project is **focused** on the implementation of the GUI based on a given logic, that is, reading code and implementing the GUI to manipulate the given code.

## Table of contents
- [Description](https://github.com/robredomikel/hitori_gui#description)
- [How to run](https://github.com/robredomikel/hitori_gui#how-to-run)
	- [In Qt](https://github.com/robredomikel/hitori_gui#in-qt)
- [Features](https://github.com/robredomikel/hitori_gui#features) 
	- [Gameboard](https://github.com/robredomikel/hitori_gui#gameboard)
	- [Game buttons](https://github.com/robredomikel/hitori_gui#game-buttons)
	- [Counters](https://github.com/robredomikel/hitori_gui#counters)
- [Further comments](https://github.com/robredomikel/hitori_gui#further-comments)
- [References](https://github.com/robredomikel/hitori_gui#references)

## Description
In this project, given the _2048 game_ logic given in the __gameboard__ module, the implementation is based on the __Graphical User Interface__ of this logic in the module __mainwindow__.

The user could find when running the program  a GUI as the one shown below.
![gui1](https://github.com/robredomikel/hitori_gui/blob/main/readme_content/gui_1.PNG)

During this  README file I will mostly **go over some of the most important features** in which the project is based on, rather than the description of each function and their goal, which can be found on the definition of each function in the self-implemented module files. **Rules and context** of the game can be found in the links attached in the [References](https://github.com/robredomikel/hitori_gui#references) section.
## How to run
As this is a ghapically oriented project, the guidance will be given only in Qt Designer. 

### In Qt
As the GUI is created in Qt and some of the features are mainly created manually through Qt Designer, it's recommendable that the same IDE is used to try this code.
It is only needed to open the pro file in the project directory with Qt Creator, and then execute the program, once it compiles the GUI will show up.

## Features
The project is based on some compulsory features, needed to print all the functionalities that the game logic computes in the **gameboard** module. Then there are some additional extra features as well.
### Gameboard
Located in the left-center of the main window, it will show the numbers that change in each movement and get merged. They change of color based on the given number.

![gui_02](https://github.com/robredomikel/hitori_gui/blob/main/readme_content/gui_2.gif)

### Game buttons
Located at the bottom-right of the main window, the **direction buttons** are needed in order to move the numbers.
Then, above the counters is located the **pause button** that helps the player stop the game and think about the next movement.
The remaining buttons are needed to close the game and finalize the program run, start the game, and reset the current game.
### Counters
First counters are located in the upper left corner of the main window. They are used to **set the seed** for the random creation of the initial numbers (0 is allowed), and to set the goal number, which is set to 2048 as default.
Remaining buttons can be seen at the right side of the main window they count the amount of minutes and seconds of the current game, the remaining time for the current move (10 seconds) and the number of movements made in the game.
## Further comments
This project should be seen from a **Graphical User Interface** oriented perspective. Indeed, all the implemented code has been based on this part of the project.

**It is worth to notice** that all the graphical display implemented has been done by code instead that by hand, since it gives a more accurate manipulation range over the features in the main window. 

## References
- [Programming 2: Structures (FITech) | Tampere universities (tuni.fi)](https://www.tuni.fi/en/study-with-us/programming-2-structures-fitech)
- [cppreference.com](https://en.cppreference.com/w/)
- [Qt Designer Manual](https://doc.qt.io/qt-6/qtdesigner-manual.html)
- [2048 (video game) - Wikipedia](https://en.wikipedia.org/wiki/2048_(video_game))
- [2048 (play2048.co)](https://play2048.co/)
