#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gameboard.hh"
#include "numbertile.hh"

#include <iostream>


const std::map<int, QBrush> COLORS = {
    {2, Qt::red}, {4, Qt::green}, {8,Qt::blue},{16, Qt::magenta},
    {32,Qt::white},{64, Qt::yellow},{128, Qt::cyan}, {256, Qt::darkRed},
    {512, Qt::darkGreen},{1024, Qt::darkBlue},{2048, Qt::darkMagenta}
};

const Coords DEFAULT_DIR = {0, 0};
const Coords UP = {0, -1};
const Coords LEFT = {-1, 0};
const Coords DOWN = {0, 1};
const Coords RIGHT = {1, 0};

const std::string LOSS = "Can't add new tile, you lost!\n "
                         "You can play again pressing RESET button!",
                  START = "Press START to play the game.\n"
                          "Choose the SEED and GOAL (power of two)\n"
                          "values you prefer.",
                  GUIDE = "Press the key buttons to move the tiles.\n"
                          "Press RESET to set up the game again.\n"
                          "You have limited seconds per movement! RUN!",
                  PAUSE = "GAME PAUSED\n"
                          "Press RESUME to continue playing.\n"
                          "Press RESET to begin the game again.";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    board_graphics_view_ = new QGraphicsView(this);

    board_graphics_view_->setGeometry(SCENE_X, SCENE_Y,
                                    SIZE*GRID_SIDE + 4,
                                    SIZE*GRID_SIDE + 4);

    board_graphics_view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    board_graphics_view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scene_ = new QGraphicsScene(this);
    scene_->setBackgroundBrush(Qt::white);

    board_graphics_view_->setScene(scene_);
    scene_->setSceneRect(SCENE_X, SCENE_Y,
                         SIZE*GRID_SIDE,
                         SIZE*GRID_SIDE);

    initBoard();
    setLabels();

    // MAIN CONNECTIONS:
    connect(ui->closePushButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->startPushButton, &QPushButton::clicked, this, &MainWindow::startButtonPressed);
    connect(ui->resetPushButton, &QPushButton::clicked, this, &MainWindow::resetButtonPressed);
    connect(ui->pausePushButton, &QPushButton::clicked, this, &MainWindow::pauseGame);

    // ARROW-KEYS CONNECTIONS:
    connect(ui->leftPushButton, &QPushButton::clicked, this, &MainWindow::updateNumberTiles);
    connect(ui->rightPushButton, &QPushButton::clicked, this, &MainWindow::updateNumberTiles);
    connect(ui->downPushButton, &QPushButton::clicked, this, &MainWindow::updateNumberTiles);
    connect(ui->upPushButton, &QPushButton::clicked, this, &MainWindow::updateNumberTiles);

    // AUXILIAR CONNECTION TO DEALLOCATE TIMER POINTERS:
    connect(ui->closePushButton, &QPushButton::clicked, this, &MainWindow::deallocateTimers);

    // Directions with their coordinates for the update of the gameboard.
    directions_.push_back({ui->leftPushButton, LEFT});
    directions_.push_back({ui->rightPushButton, RIGHT});
    directions_.push_back({ui->downPushButton, DOWN});
    directions_.push_back({ui->upPushButton, UP});

    // Color design for the timer.
    ui->minutesLcdNumber->setStyleSheet("color: red; background-color: black");
    ui->minutesLabel->setStyleSheet("color: black; background-color: grey");
    ui->secondsLcdNumber->setStyleSheet("color: red; background-color: black");
    ui->secondsLabel->setStyleSheet("color: black; background-color: grey");

    // Time out color design.
    ui->timeLeftLcdNumber->setStyleSheet("color: red; background-color: black");
    ui->timeLeftLabel->setStyleSheet("color: black; background-color: grey");

    // Movement counter color design.
    ui->movesLcdNumber->setStyleSheet("color: red; background-color: black");
    ui->movesLabel->setStyleSheet("color: black; background-color: grey");

    timer_ = new QTimer();

    countdown_ = new QTimer();

    // connect timer interval to mainwindow:
    connect(timer_, &QTimer::timeout, this, &MainWindow::secondPassed);

    // connect countdown interval to mainwindow:
    connect(countdown_, &QTimer::timeout, this, &MainWindow::secondCount);

    // Initial message in the board.
    ui->resultTextBrowser->setText(QString::fromStdString(START));

    // For initial stadio of key buttons
    disableButtons();

    ui->resetPushButton->setDisabled(true);
    ui->resetPushButton->setStyleSheet("color: red; background-color: grey");

    ui->pausePushButton->setDisabled(true);
    ui->pausePushButton->setStyleSheet("color: red; background-color: grey");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Initializes the action logic board with empty pointers. Creates in the same
 * way a rectangle graphical item and a label simulating the same grid created
 * in the action logic but in graphical way. Also, in order to maintain the
 * matrix form for the grid, each rectangle and label are added to vectors, so
 * that in incoming functions will be used.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::initBoard()
{
    // Initialize the board:
    board_.init_empty();

    for (int i=0; i < SIZE; ++i) // for rows
    {
        std::vector<QLabel*> row;
        std::vector<QGraphicsRectItem*> rectRow;
        for (int j = 0; j < SIZE; ++j) // for columns
        {
            // Creation of the rectangles.
            QRect rectangle;
            rectangle.setRect(SCENE_X + (i*GRID_SIDE),
                              SCENE_Y + (j*GRID_SIDE),
                              GRID_SIDE, GRID_SIDE);
            QBrush grey_brush(Qt::lightGray);
            QPen black_pen(Qt::black);
            rect_item_ = scene_->addRect(rectangle, black_pen, grey_brush);
            rectRow.push_back(rect_item_);

            QLabel* tileValue = new QLabel("", this);
            row.push_back(tileValue);
        }
        graphic_board_.push_back(row);
        graphic_rect_board_.push_back(rectRow);
    }
}

/* Sets the previously created QLabels into the graphical layout. Labels and
 * Rectangles are located in the layout in a different way since the labels are
 * located in the layout, and the rectangles inside the scene_ dimensions.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::setLabels()
{
    for (int i=0; i < SIZE; ++i) // for rows
    {
        for (int j = 0; j < SIZE; ++j) // for columns
        {
            QLabel* tileValue = graphic_board_.at(i).at(j);
            tileValue->setGeometry(SCENE_X + (i*GRID_SIDE),
                                   SCENE_Y + (j*GRID_SIDE),
                                   GRID_SIDE,
                                   GRID_SIDE);
            tileValue->setAlignment(Qt::AlignCenter);
        }
    }
}

/* Once the START button is pressed the action logic board is filled in a random
 * way given by the input seed. The goal value is also added to the game in this
 * point. From this latter one the possible numbers appearing in the game are
 * stored in a data structure for future use.
 *
 * Different buttons within the game are enabled/disabled for a correct game
 * functioning.
 *
 * Also, at this points the numbers from the action logic are ordered to be
 * printed in the QLabels (a function for this is called).
 *
 * The timer for the game and the countdown are initialized.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::startButtonPressed()
{
    // Fill the tiles with numbers.
    int seedValue = ui->seedSpinBox->value();
    board_.fill(seedValue);

    goal_value_ = int(ui->goalSpinBox->value());

    ui->resultTextBrowser->setText(QString::fromStdString(GUIDE));

    if (checkPowerOfTwo() == true)
    {
        ui->goalSpinBox->setValue(goal_value_);
    }
    else // If it's 0 or not power of two we set the default goal.
    {
        ui->goalSpinBox->setValue(DEFAULT_GOAL);
        goal_value_ = DEFAULT_GOAL;
    }

    possibleNumbers(goal_value_);

    // Makes spinboxes disabled:
    ui->seedSpinBox->setEnabled(false);
    ui->seedSpinBox->setStyleSheet("color: red; background-color: grey");

    ui->goalSpinBox->setEnabled(false);
    ui->goalSpinBox->setStyleSheet("color: red; background-color: grey");

    // Disables the start button:
    ui->startPushButton->setEnabled(false);
    ui->startPushButton->setStyleSheet("color: red; background-color: grey");

    ui->resetPushButton->setEnabled(true);
    ui->resetPushButton->setStyleSheet("color: black; background-color: none");

    ui->pausePushButton->setEnabled(true);
    ui->pausePushButton->setStyleSheet("color: black; background-color: none");

    enableButtons();

    setNumberTiles();
    startTimer();
    startCountdown();
}

/* Cleans the current board, but doesn't eliminate grid created by the action
 * logic part of this project. Resets all the timers and counters and enable/
 * disables all the buttons in a way that the game can work well.
 *
 * Sets all the graphical acpect of the game at the scratch so that the user
 * can model again the seed and goal number of the game and start it again.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::resetButtonPressed()
{
    ui->seedSpinBox->setEnabled(true);
    ui->seedSpinBox->setStyleSheet("color: black; background-color: none");
    ui->goalSpinBox->setEnabled(true);
    ui->goalSpinBox->setStyleSheet("color: black; background-color: none");

    ui->startPushButton->setEnabled(true);
    ui->startPushButton->setStyleSheet("color: black; background-color: none");

    ui->resultTextBrowser->setText(QString::fromStdString(START));

    // Clears the tiles.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            graphic_board_.at(i).at(j)->setText("");
            graphic_rect_board_.at(i).at(j)->setBrush(Qt::gray);
        }
    }

    resetTimer();
    ui->pausePushButton->setText("Pause game");
    timer_->stop();

    resetCountdown();
    countdown_->stop();

    move_counter_ = 0;
    updateMovements();

    ui->centralwidget->setStyleSheet("background-color: none");
    ui->statusbar->setStyleSheet("background-color: none");

    ui->pausePushButton->setDisabled(true);
    ui->pausePushButton->setStyleSheet("color: red; background-color: grey");

    disableButtons();
}

/* This function connects with the action logic part of this project in a way
 * that whenever its called, depending on the key button used for the movement,
 * orders to the action logic board to compute the ordered moves, and this one
 * deals with the number tile objects.
 *
 * If the method MOVE from the logic board notifies that the goal number has
 * been reached then the GUI changes all its features into the WINNING scenario,
 * the game has ended and only is possible to reset the game.
 *
 * Else, if the board notifies that after the last movement the board is full
 * of numbers, then the game ends in LOSS scenario, and all the features change
 * to this specific scenario.
 *
 * If none of these previous cases occur, this function updates the graphical
 * aspect of the grid (number labels and rectangle colors.)
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::updateNumberTiles()
{
    Coords dir = DEFAULT_DIR;

    for (auto& dir_button : directions_)
    {
        if (dir_button.button == sender())
        {
            dir = dir_button.direction;
        }
    }

    if( dir != DEFAULT_DIR )
    {
        if( board_.move(dir, goal_value_) )
        {
            setNumberTiles();
            std::string goal_str = std::to_string(goal_value_);
            std::string win_message = "You reached the goal value of "+
                    goal_str +
                    "!\n" "Press RESET button to start the game again.";
            ui->resultTextBrowser->setText(QString::fromStdString(win_message));

            ui->centralwidget->setStyleSheet("background-color: green");
            ui->statusbar->setStyleSheet("background-color: green");

            for (auto& dir : directions_)
            {
                dir.button->setEnabled(false);
                dir.button->setStyleSheet("color: black; background-color: green");
            }

            ui->pausePushButton->setDisabled(true);
            ui->pausePushButton->setStyleSheet("color: black; background-color: green");

            countdown_->stop();
            timer_->stop();


        }
        else if( board_.is_full() )
        {
            setNumberTiles();
            ui->resultTextBrowser->setText(QString::fromStdString(LOSS));

            for (auto& dir : directions_)
            {
                dir.button->setEnabled(false);
                dir.button->setStyleSheet("color: red; background-color: black");
            }
            ui->centralwidget->setStyleSheet("background-color: red");
            ui->statusbar->setStyleSheet("background-color: red");

            ui->pausePushButton->setDisabled(true);
            ui->pausePushButton->setStyleSheet("color: red; background-color: grey");

            return;
        }
        board_.new_value(false);
        setNumberTiles();
        resetCountdown();
        move_counter_++;
        updateMovements();

    }
}

/* This function pauses or resumes the game depending on the state of the flag
 * value defined in the private part of the header file. Depending on which
 * is the case, it enables/disables key/option buttons and stops or re-starts
 * the timer/counters of the game.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::pauseGame()
{
    if (!paused_) // If the game is not paused, we pause it when pressing.
    {
        ui->pausePushButton->setText("Resume");

        ui->resultTextBrowser->setText(QString::fromStdString(PAUSE));

        disableButtons();

        timer_->stop();
        countdown_->stop();
        paused_ = true;
    }
    else // The game should be paused, we continue playing.
    {
        ui->pausePushButton->setText("Pause game");
        ui->resultTextBrowser->setText(QString::fromStdString(GUIDE));

        enableButtons();

        timer_->start(1000);
        countdown_->start(1000);
        paused_ = false;
    }

}

/* AUXILIAR FUNCTION for the timer of this game, it only deals with the current
 * value of the time that has passed and calls another function to reflect this
 * change in the GUI.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::secondPassed()
{
    time_passed_++;
    updateLCD();
}

/* AUXILIAR FUNCTION for the start of the timer of this game.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::startTimer()
{
    // 1000 by 1000 miliseconds (= 1 sec by 1 sec)
    timer_->start(1000);
}

/* AUXILIAR FUNCTION for the countdown of this game, so that it reduces the
 * pending time by one second unit each time is called, and calls another
 * function to reflect this change in the GUI.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::secondCount()
{
    time_left_--;
    updateCountdown();
}

/* AUXILIAR FUNCTION that resets the initial value of the countdown for each
 * movement.
 *
 * If the amount of movements surpasses 10 moves then the initial time for the
 * countdown goes to 5.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::resetCountdown()
{
    if (move_counter_ >= 10)
    {
        time_left_ = 5;
    }
    else
    {
        time_left_ = 10;
    }

    updateCountdown();
}

/* AUXILIAR FUNCTION that starts the countdown time counter of this game.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::startCountdown()
{
    countdown_->start(1000);
}

/* Checks if the goal value for the game is power of two or not.
 *
 * PARAM: None
 *
 * RETURN: bool, TRUE; In case the goal value introduced is power of two.
 *               FALSE; In case the goal value introduced is not a power of two
 *               or directly hasn't been modified initially (= 0)
 */
bool MainWindow::checkPowerOfTwo()
{
    int current_number = goal_value_;

    if (current_number > 0)
    {
        while ( current_number % 2 == 0)
        {
            current_number /= 2;
        }
        if (current_number == 1)
        {
            return true; // It is power of two.
        }
        else
        {
            return false; // It not power of two.
        }
    }
    else
    {
        return false; // 0 has been given.
    }
}

/* AUXILIAR FUNCTION that resets the timer of this game and call another function
 * to show this change graphically.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::resetTimer()
{
    time_passed_ = 0;
    updateLCD();
}

/* Once the number tiles have been updated, this function sets this change in
 * the action logic graphically in the grid. For this, it changes the value that
 * each QLabel is printing, and depending on the value of each tile, the
 * rectangle for each tile takes an specific background color.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::setNumberTiles()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            number_tile_ = board_.get_item({i,j});
            int number_int = number_tile_->get_value();
            QString number_str = QString::number(number_int);
            graphic_board_.at(i).at(j)->setText(number_str);

            rect_item_ = graphic_rect_board_.at(i).at(j);
            if (number_int != 0)
            {
                setBkgndColor(number_int, rect_item_);
            }
            else
            {
                graphic_board_.at(i).at(j)->setText("");
                rect_item_->setBrush(Qt::gray);
            }
        }
    }
}

/* Stores the number of possible numbers to appear in the game based on the
 * goal value introduced by the user. In this way, logic for rectangle colors
 * is build. So this function just stores these possible values in a data
 * structure for future handling of these.
 *
 * PARAM: int goal_value; The goal value set by the user..
 *
 * RETURN: None.
 */
void MainWindow::possibleNumbers(int goal_value)
{
    int current_number = goal_value;
    while (current_number >= 2)
    {
        current_number = current_number / 2;
        possible_numbers_.push_back(current_number);
    }
}

/* This function is called each time a numbertile is set, in order to, depending
 * on its number value, give a specific color to the background to its
 * respective rectangle.
 *
 * PARAM: int number_tile_value; Number value of the given number tile.
 *        QGraphicsRectItem rect_item; Rectangle graphical item pointer for the
 *        given number tile.
 *
 * RETURN: None.
 */
void MainWindow::setBkgndColor(int number_tile_value, QGraphicsRectItem* rect_item)
{
    int i = 0;
    while (possible_numbers_.at(i) != possible_numbers_.back())
    {        
        if (possible_numbers_.at(i) == number_tile_value)
        {
            int color_number = possible_numbers_.at(i);
            rect_item->setBrush(COLORS.at(color_number));
        }
        else if (number_tile_value > DEFAULT_GOAL)
        {
            rect_item->setBrush(Qt::darkCyan);
        }
        ++i;
    }
}

/* AUXILIAR FUNCTION that updates graphically the current time of the game in the
 * board.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::updateLCD()
{
    int minutes = time_passed_ / 60;
    int seconds = time_passed_ % 60;

    ui->minutesLcdNumber->display(minutes);
    ui->secondsLcdNumber->display(seconds);
}

/* Updates the countdown time of each movement graphically in the board.
 * In addition, if the current time (seconds) is pair, it shows the number
 * in one given color design, and changes when the second is odd.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::updateCountdown()
{
    if (time_left_ == 0)
    {
        countdown_->stop();
        timer_->stop();
        ui->resultTextBrowser->setText(QString::fromStdString(LOSS));

        disableButtons();

        ui->centralwidget->setStyleSheet("background-color: red");
        ui->statusbar->setStyleSheet("background-color: red");

        ui->pausePushButton->setDisabled(true);
        ui->pausePushButton->setStyleSheet("color: red; background-color: grey");
    }

    if (time_left_ % 2 == 0)
    {
        ui->timeLeftLcdNumber->setStyleSheet("color: red; background-color: black");
    }
    else
    {
        ui->timeLeftLcdNumber->setStyleSheet("color: black; background-color: red");
    }
    ui->timeLeftLcdNumber->display(time_left_);
}

/* AUXILIAR FUNCTION for all the cases in which the key buttons must be disabled,
 * so that the code is neater and same lines of code aren't repeated.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::disableButtons()
{
    for (auto& dir : directions_)
    {
        dir.button->setEnabled(false);
        dir.button->setStyleSheet("color: red; background-color: grey");
    }
}

/* AUXILIAR FUNCTION for all the cases in which the key buttons must be enabled,
 * so that the code is neater and same lines of code aren't repeated.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::enableButtons()
{
    for (auto& dir : directions_)
    {
        dir.button->setEnabled(true);
        dir.button->setStyleSheet("color: black; background-color: none");
    }
}

/* Updates graphically the number of movements that the user has made so that
 * the same one can see the quantity, given the condition that when it reaches 10
 * moves the time for each movement will be of 5 seconds instead of 10.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::updateMovements()
{
    ui->movesLcdNumber->display(move_counter_);
}

/* AUXILIAR FUNCTION that deallocates the allocated data used for timer and
 * countdown timer pointers.
 *
 * NOTE: When I finished the project I run Valgrind and I saw that these two
 * were the reason of memory leaks, so this is the way I made to deallocate the
 * memory easily.
 *
 * PARAM: None.
 *
 * RETURN: None.
 */
void MainWindow::deallocateTimers()
{
    delete timer_;
    delete countdown_;
}

