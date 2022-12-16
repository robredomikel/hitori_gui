/* HEADER */
/* Game called 2048
 *
 * Desc:
 * This program creates a graphical user interface in the 2048 game, as the action
 * logic has been already given in the template. The following points are further
 * explained in the instructions.txt file, so here they won't be explained in
 * order to not make a long header:
 *
 * - HOW TO USE THE PROGRAM
 * - RULES OF THE GAME
 * - ADDED FUNCTIONALITIES
 *
 * Given this information, the implementation of this project is almost completely
 * done in the mainwindow module, there all the necessary functions haven been
 * implemented for making the game run, be visible, and contain extra features.
 *
 * Further information will be given in function headers.
 *
 * No comments will be added to the already given template code.
 * JUST: Comments will be added to get_value() function in numbertile class.
 *
 * Name: Mikel Robredo Manero
 * Student number: 150167534
 * UserID: pqmiro
 * E-Mail: mikel.robredomanero@tuni.fi
 *
 * */

#include "mainwindow.hh"
#include "gameboard.hh"
#include "numbertile.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
