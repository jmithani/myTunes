#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>

#include <QApplication>
#include <QDesktopWidget>

#include <QtCore/QCoreApplication>
#include <iostream>
#include <QFileDialog>
#include <vector>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>
#include <QDebug>
#include <sstream>

using namespace std;

class Library : public QWidget
{
    Q_OBJECT
public:
    Library();
    ~Library();

    int size();
    void getLibrary();
    string operator[](int i);

    void setDir(string dir);
    string getDir();
    //void addMusic();
    //void deleteMusic();
    /*
    void artistSort();
    void genreSort();
    void titleSort();
    void albumSort();

    string getRandomSong();
    string getArtist();
    string getTitle();
    string getAlbum();
    string getGenre();
    string getSize();
    string editInfor();
    int playCount();


    void display();
    void nextSong();
    void prevSong();
    void currSong();
*/
    friend class Playlist;

public slots:
    void addMusic();
    //void deleteMusic();

signals:
    void musicAdded();
    void musicDeleted();

private:
    vector<string> files;
    vector<string> readDir( const string& path);
    int songToPlay;
    string libPath;

    //void sort();
    void loadSongs();
};

#endif // LIBRARY_H
