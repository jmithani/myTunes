#ifndef INITIAL_H
#define INITIAL_H

#include <QMainWindow>
#include <QStringList>
#include <QApplication>
#include <QDesktopWidget>
#include <QtCore/QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <vector>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>
#include "library.h"
#include <QDebug>
#include "mainwindow.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class Initial : public QMainWindow
{
    Q_OBJECT

public:
    explicit Initial(QWidget *parent = 0);
    ~Initial();

public slots:
    void cellSelected(int nRow, int nCol);
    void addMusic();
    void updateMusic();
    void openPlayer();

private:
    //MainWindow *player;
    Ui:: *ui;
    Library lib;
    vector<string> read_directory( const string& path = string() );
};

#endif // MainWindow_H
