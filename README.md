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
![gui1](https://github.com/robredomikel/hitori_gui/blob/main/readme_content/gui_1.PNG)

During this  README file I will mostly **go over some of the most important features** in which the project is based on, rather than the description of each function and their goal, which can be found on the definition of each function in the self-implemented module files. **Rules and context** of the game can be found in the links attached in the [References](https://github.com/robredomikel/finnish-railway-system#references) section.
## How to run
As this is a ghapically oriented project, the guidance will be given only in Qt Designer. 

### In Qt
As the GUI is created in Qt and some of the features are mainly created manually through Qt Designer, it's recommendable that the same IDE is used to try this code.
It is only needed to open the pro file in the project directory with Qt Creator, and then execute the program, once it compiles the GUI will show up.

## Features
The project is based on some compulsory features, needed to print all the functionalities that the game logic computes in the **gameboard** module. Then there are some additional extra features as well.

### Gameboard
This modules creates the map of coordinates for the points and routes, which is the core of the functionality of this project. An orienteeringmap Object should be able to compute methods like _print_map, print_routes, print_points_ and so on and so forth.
The orienteering map will contain the information of the existing points and the routes among them, stored in STL maps as pointers.
```cpp
// Map of Point* objects:
std::map<std::string, std::shared_ptr<Point>>  points_;
// Map of Routes:
std::map< std::string, std::vector<std::shared_ptr<Point> >> routes_;
```
### Game buttons
Point class will define the attributes and methods implemented for Point objects, such as, their coordinates, height or name. Mostly, all methods implemented in this class are __getter__ functions, so that point class works to define and store __all the information__ of each point.
### Counters
## Further comments
This project should be seen from a **Modularity** backed perspective. Indeed, all the implemented code has been based on this part of the project.

Rather than efficiency, the implementation of this project is more oriented to the **connection between different objects**, so there may be surely some operations that could be more efficient. 

## References
- [Programming 2: Structures (FITech) | Tampere universities (tuni.fi)](https://www.tuni.fi/en/study-with-us/programming-2-structures-fitech)
- [cppreference.com](https://en.cppreference.com/w/)
- [Qt Designer Manual](https://doc.qt.io/qt-6/qtdesigner-manual.html)
- [2048 (video game) - Wikipedia](https://en.wikipedia.org/wiki/2048_(video_game))
- [2048 (play2048.co)](https://play2048.co/)
