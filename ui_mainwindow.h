/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelSeed;
    QSpinBox *seedSpinBox;
    QSpinBox *goalSpinBox;
    QLabel *labelGoal;
    QPushButton *upPushButton;
    QPushButton *leftPushButton;
    QPushButton *downPushButton;
    QPushButton *rightPushButton;
    QPushButton *startPushButton;
    QPushButton *resetPushButton;
    QPushButton *closePushButton;
    QTextBrowser *resultTextBrowser;
    QWidget *gridLayoutWidget;
    QGridLayout *TimerGridLayout;
    QLabel *minutesLabel;
    QLabel *secondsLabel;
    QLCDNumber *minutesLcdNumber;
    QLCDNumber *secondsLcdNumber;
    QWidget *gridLayoutWidget_2;
    QGridLayout *scoreSridLayout;
    QLCDNumber *timeLeftLcdNumber;
    QLabel *timeLeftLabel;
    QLCDNumber *movesLcdNumber;
    QLabel *movesLabel;
    QPushButton *pausePushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(719, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 30, 211, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelSeed = new QLabel(formLayoutWidget);
        labelSeed->setObjectName(QString::fromUtf8("labelSeed"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelSeed);

        seedSpinBox = new QSpinBox(formLayoutWidget);
        seedSpinBox->setObjectName(QString::fromUtf8("seedSpinBox"));
        seedSpinBox->setEnabled(true);
        seedSpinBox->setMaximum(250);
        seedSpinBox->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, seedSpinBox);

        goalSpinBox = new QSpinBox(formLayoutWidget);
        goalSpinBox->setObjectName(QString::fromUtf8("goalSpinBox"));
        goalSpinBox->setMaximum(5000);

        formLayout->setWidget(1, QFormLayout::FieldRole, goalSpinBox);

        labelGoal = new QLabel(formLayoutWidget);
        labelGoal->setObjectName(QString::fromUtf8("labelGoal"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelGoal);

        upPushButton = new QPushButton(centralwidget);
        upPushButton->setObjectName(QString::fromUtf8("upPushButton"));
        upPushButton->setGeometry(QRect(530, 350, 50, 51));
        leftPushButton = new QPushButton(centralwidget);
        leftPushButton->setObjectName(QString::fromUtf8("leftPushButton"));
        leftPushButton->setGeometry(QRect(470, 410, 50, 50));
        downPushButton = new QPushButton(centralwidget);
        downPushButton->setObjectName(QString::fromUtf8("downPushButton"));
        downPushButton->setGeometry(QRect(530, 410, 50, 50));
        rightPushButton = new QPushButton(centralwidget);
        rightPushButton->setObjectName(QString::fromUtf8("rightPushButton"));
        rightPushButton->setGeometry(QRect(590, 410, 50, 50));
        startPushButton = new QPushButton(centralwidget);
        startPushButton->setObjectName(QString::fromUtf8("startPushButton"));
        startPushButton->setGeometry(QRect(250, 10, 150, 25));
        resetPushButton = new QPushButton(centralwidget);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));
        resetPushButton->setGeometry(QRect(250, 40, 150, 25));
        closePushButton = new QPushButton(centralwidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(250, 70, 150, 25));
        resultTextBrowser = new QTextBrowser(centralwidget);
        resultTextBrowser->setObjectName(QString::fromUtf8("resultTextBrowser"));
        resultTextBrowser->setGeometry(QRect(425, 10, 241, 121));
        QPalette palette;
        resultTextBrowser->setPalette(palette);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(410, 180, 141, 91));
        TimerGridLayout = new QGridLayout(gridLayoutWidget);
        TimerGridLayout->setObjectName(QString::fromUtf8("TimerGridLayout"));
        TimerGridLayout->setContentsMargins(0, 0, 0, 0);
        minutesLabel = new QLabel(gridLayoutWidget);
        minutesLabel->setObjectName(QString::fromUtf8("minutesLabel"));
        minutesLabel->setAlignment(Qt::AlignCenter);

        TimerGridLayout->addWidget(minutesLabel, 0, 1, 1, 1);

        secondsLabel = new QLabel(gridLayoutWidget);
        secondsLabel->setObjectName(QString::fromUtf8("secondsLabel"));
        secondsLabel->setAlignment(Qt::AlignCenter);

        TimerGridLayout->addWidget(secondsLabel, 1, 1, 1, 1);

        minutesLcdNumber = new QLCDNumber(gridLayoutWidget);
        minutesLcdNumber->setObjectName(QString::fromUtf8("minutesLcdNumber"));

        TimerGridLayout->addWidget(minutesLcdNumber, 0, 0, 1, 1);

        secondsLcdNumber = new QLCDNumber(gridLayoutWidget);
        secondsLcdNumber->setObjectName(QString::fromUtf8("secondsLcdNumber"));

        TimerGridLayout->addWidget(secondsLcdNumber, 1, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(560, 180, 131, 91));
        scoreSridLayout = new QGridLayout(gridLayoutWidget_2);
        scoreSridLayout->setObjectName(QString::fromUtf8("scoreSridLayout"));
        scoreSridLayout->setContentsMargins(0, 0, 0, 0);
        timeLeftLcdNumber = new QLCDNumber(gridLayoutWidget_2);
        timeLeftLcdNumber->setObjectName(QString::fromUtf8("timeLeftLcdNumber"));

        scoreSridLayout->addWidget(timeLeftLcdNumber, 0, 0, 1, 1);

        timeLeftLabel = new QLabel(gridLayoutWidget_2);
        timeLeftLabel->setObjectName(QString::fromUtf8("timeLeftLabel"));
        timeLeftLabel->setAlignment(Qt::AlignCenter);

        scoreSridLayout->addWidget(timeLeftLabel, 0, 1, 1, 1);

        movesLcdNumber = new QLCDNumber(gridLayoutWidget_2);
        movesLcdNumber->setObjectName(QString::fromUtf8("movesLcdNumber"));

        scoreSridLayout->addWidget(movesLcdNumber, 1, 0, 1, 1);

        movesLabel = new QLabel(gridLayoutWidget_2);
        movesLabel->setObjectName(QString::fromUtf8("movesLabel"));
        movesLabel->setAlignment(Qt::AlignCenter);

        scoreSridLayout->addWidget(movesLabel, 1, 1, 1, 1);

        pausePushButton = new QPushButton(centralwidget);
        pausePushButton->setObjectName(QString::fromUtf8("pausePushButton"));
        pausePushButton->setGeometry(QRect(420, 150, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 719, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelSeed->setText(QCoreApplication::translate("MainWindow", "Seed value", nullptr));
        labelGoal->setText(QCoreApplication::translate("MainWindow", "Goal number", nullptr));
        upPushButton->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        leftPushButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        downPushButton->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        rightPushButton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        startPushButton->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        resetPushButton->setText(QCoreApplication::translate("MainWindow", "Reset Game", nullptr));
        closePushButton->setText(QCoreApplication::translate("MainWindow", "Close Game", nullptr));
        minutesLabel->setText(QCoreApplication::translate("MainWindow", "minutes", nullptr));
        secondsLabel->setText(QCoreApplication::translate("MainWindow", "seconds", nullptr));
        timeLeftLabel->setText(QCoreApplication::translate("MainWindow", "time left", nullptr));
        movesLabel->setText(QCoreApplication::translate("MainWindow", "moves", nullptr));
        pausePushButton->setText(QCoreApplication::translate("MainWindow", "Pause game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
