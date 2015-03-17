/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Playlist;
    QAction *actionView_Playlists;
    QAction *actionAdd_Music;
    QAction *actionView_Playlists_2;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuPlaylists;
    QMenu *menuLibrary;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionAdd_Playlist = new QAction(MainWindow);
        actionAdd_Playlist->setObjectName(QStringLiteral("actionAdd_Playlist"));
        actionView_Playlists = new QAction(MainWindow);
        actionView_Playlists->setObjectName(QStringLiteral("actionView_Playlists"));
        actionAdd_Music = new QAction(MainWindow);
        actionAdd_Music->setObjectName(QStringLiteral("actionAdd_Music"));
        actionView_Playlists_2 = new QAction(MainWindow);
        actionView_Playlists_2->setObjectName(QStringLiteral("actionView_Playlists_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, -10, 1021, 671));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPlaylists = new QMenu(menuFile);
        menuPlaylists->setObjectName(QStringLiteral("menuPlaylists"));
        menuLibrary = new QMenu(menuFile);
        menuLibrary->setObjectName(QStringLiteral("menuLibrary"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(menuLibrary->menuAction());
        menuFile->addAction(menuPlaylists->menuAction());
        menuPlaylists->addAction(actionAdd_Playlist);
        menuPlaylists->addAction(actionView_Playlists_2);
        menuLibrary->addAction(actionAdd_Music);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_Playlist->setText(QApplication::translate("MainWindow", "Add Playlist", 0));
        actionView_Playlists->setText(QApplication::translate("MainWindow", "View Playlists", 0));
        actionAdd_Music->setText(QApplication::translate("MainWindow", "Add Music", 0));
        actionView_Playlists_2->setText(QApplication::translate("MainWindow", "View Playlists", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuPlaylists->setTitle(QApplication::translate("MainWindow", "Playlists", 0));
        menuLibrary->setTitle(QApplication::translate("MainWindow", "Library", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
