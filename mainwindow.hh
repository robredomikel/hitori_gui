/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project4: Game called 2048                                                #
# File: mainwindow                                                          #
# Description: GUI engine that handles the information from the action logic#
# in gameboard and numbertile classes and shows the game in a graphical way #
# for the user.                                                             #
#############################################################################
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "numbertile.hh"
#include "gameboard.hh"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QBrush>
#include <QPushButton>
#include <QTimer>
#include <QPalette>

#include <vector>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initBoard();

    void setLabels();

    void startButtonPressed();

    void resetButtonPressed();

    void updateNumberTiles();

    void pauseGame();

private slots:

    // Timer:
    void secondPassed();
    void resetTimer();
    void startTimer();

    // Countdown:
    void secondCount();
    void resetCountdown();
    void startCountdown();

private:
    Ui::MainWindow *ui;

    // Our gameboard(action logic):
    GameBoard board_;

    // Graphical board:
    QGraphicsView* board_graphics_view_;

    // Our surface to draw the number tiles:
    QGraphicsScene* scene_;

    // Rectangle graphical item for each number tile:
    QGraphicsRectItem* rect_item_;

    // Pointer to each number tile in the board.
    NumberTile* number_tile_;

    // Timer.
    QTimer* timer_;

    // Countdown.
    QTimer* countdown_;

    // Vector data structure for all the labels containing the numbers.
    std::vector<std::vector<QLabel*>> graphic_board_;

    // Vector of vectors containing the graphical matrix of rectangles.
    std::vector<std::vector<QGraphicsRectItem*>> graphic_rect_board_;

    // Coords of the scene dimensions.
    const int SCENE_X = 90;
    const int SCENE_Y = 180;

    // Size of each number tile rectangle width and height.
    const int GRID_SIDE = 50;

    bool checkPowerOfTwo();

    void setNumberTiles();

    // Stores the goal value chosen by the user.
    int goal_value_;

    // Vector storing the possible appearing numbers based on user's choice.
    std::vector<int> possible_numbers_;

    void possibleNumbers(int goal_value_);

    // Struct with the two components that each key button contains.
    struct directionButton
    {
        QPushButton* button;
        Coords direction;
    };

    //Vector structure for the key buttons.
    std::vector<directionButton> directions_;

    void setBkgndColor(int number_tile_value, QGraphicsRectItem* rect_item);

    // Stores the value of the time passed in the game.
    int time_passed_ = 0;
    void updateLCD();

    // Stores the initial time left for each movement:
    int time_left_ = 11;
    void updateCountdown();

    void deallocateTimers();

    void disableButtons();

    void enableButtons();

    // Pause button flag:
    bool paused_ = false; // It's not paused.

    // Stores the current amount of movements made by the user.
    int move_counter_ = 0;

    void updateMovements();
};
#endif // MAINWINDOW_HH
