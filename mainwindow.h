#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
//#include "musicEngine.h"
#include "library.h"
#include "player.h"
#include "playlist.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    friend class Player;
    friend class Playlist;

public slots:
    void cellSelectedLib(int nRow, int nCol);
    void cellSelectedP(int nRow, int nCol);
    void addMusic();
    void updateMusic();
    void addPlaylist();
    void viewPlaylists();
    void viewLibrary();
    //void openPlayer(int nRow, int nCol);

private:
    //Player player;
    Ui::MainWindow *ui;
    Library lib;
    vector<string> read_directory( const string& path = string() );


};

#endif // MAINWINDOW_H
