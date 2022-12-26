# Hitori game GUI
This project is based on the final structures project required in the course Programming 2: Structures (C++) at Tampere University. Shortly, my work covered the content appearing in module **mainwindow** where all the **Graphical User Interface** is created for the game 2048. 
  
- **Note:** This project is **focused** on the implementation of the GUI based on a given logic, that is, reading code and implementing the GUI to manipulate the given code.

## Table of contents
- [Description](https://github.com/robredomikel/finnish-railway-system#description)
- [How to run](https://github.com/robredomikel/finnish-railway-system#how-to-run)
	- [In Qt](https://github.com/robredomikel/finnish-railway-system#in-qt)
- [Features](https://github.com/robredomikel/finnish-railway-system#features) 
- [Further comments](https://github.com/robredomikel/finnish-railway-system#further-comments)
- [References](https://github.com/robredomikel/finnish-railway-system#references)

## Description
In this project, given the _2048 game_ logic given in the __gameboard__ module, the implementation is based on the __Graphical User Interface__ of this logic in the module __mainwindow__.

The user could find when running the program  a GUI as the one shown below.
![gui(1)]()
During this  README file I will mostly **go over some of the most important features** in which the project is based on, rather than the description of each function and their goal, which can be found on the definition of each function in the self-implemented module files.
## How to run
In both explained options, input txt files are available in the project folder, so that the user can type them in the CMD line when executing the project, and all the input commands will be executed simultaneously.
### In Qt
As I used Qt Creator during this course I will continue with this IDE, but any IDE that could run C++ code should be able to run this project (e.g. VS Code...).
Open the _.pro_ file in Qt, build it and you will only need to execute it. Then the terminal will show ```CMD>``` in which you would run the functions that _orienteeringmap_ class contains.

![maps](https://github.com/robredomikel/orienteering/blob/main/screenshots/map.PNG)

![route function](https://github.com/robredomikel/orienteering/blob/main/screenshots/route.PNG)

## Features
Explanation of the two classes implemented for this project.
### Orienteering map
This modules creates the map of coordinates for the points and routes, which is the core of the functionality of this project. An orienteeringmap Object should be able to compute methods like _print_map, print_routes, print_points_ and so on and so forth.
The orienteering map will contain the information of the existing points and the routes among them, stored in STL maps as pointers.
```cpp
// Map of Point* objects:
std::map<std::string, std::shared_ptr<Point>>  points_;
// Map of Routes:
std::map< std::string, std::vector<std::shared_ptr<Point> >> routes_;
```
### Point
Point class will define the attributes and methods implemented for Point objects, such as, their coordinates, height or name. Mostly, all methods implemented in this class are __getter__ functions, so that point class works to define and store __all the information__ of each point.
## Further comments
This project should be seen from a **Modularity** backed perspective. Indeed, all the implemented code has been based on this part of the project.

Rather than efficiency, the implementation of this project is more oriented to the **connection between different objects**, so there may be surely some operations that could be more efficient. 

## References
- [Programming 2: Structures (FITech) | Tampere universities (tuni.fi)](https://www.tuni.fi/en/study-with-us/programming-2-structures-fitech)
- [cppreference.com](https://en.cppreference.com/w/)
- [Qt Designer Manual](https://doc.qt.io/qt-6/qtdesigner-manual.html)
