#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <QApplication>
#include <QDesktopWidget>
#include <QObject>
#include <QtCore/QCoreApplication>
#include <QFileDialog>

#include <dirent.h>
#include <sys/types.h> 
#include <algorithm>

#include "library.h"

using namespace std;

Library::Library()
{
    files = readDir("C:\\Users\\Jasmine\\Documents\\CS 3A\\myTunesWindows\\resources");
    libPath = "C:\\Users\\Jasmine\\Documents\\CS 3A\\myTunesWindows\\resources";
    //string qty;
    //stringstream ss;
    //ss<<files.size();
    //ss>>qty;
    //qty = "Number of files read: "+qty;
}

Library::~Library()
{

}

void Library::setDir(string dir)
{
    files = readDir(dir);
    libPath = dir;
}

int Library::size()
{
    return files.size();
}


vector<string> Library::readDir( const string& path)
{
  vector <string> result;
  dirent* dirEntry;
  DIR* dp;
  errno = 0;
  dp = opendir( path.empty() ? "." : path.c_str() );
  if (dp)
  {
    while (true)
    {
      errno = 0;
      dirEntry = readdir( dp );
      if (dirEntry == NULL) break;
      result.push_back( string( dirEntry->d_name ) );
    }
    closedir( dp );
    sort( result.begin(), result.end() );
    result.erase(result.begin(), result.begin()+2);
  }
  return result;
}

void Library::getLibrary()
{
    vector<string> files;

    files = readDir("\\resources");
    for(int i = 0; i < files.size(); i++)
        cout<<files[i]<<endl;
    return;
}

void Library::addMusic()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open IMusic File"), "C:\\", tr("Music Files (*.ogg *.wav)"));
    //emit(musicAdded());

    qDebug()<<"fileName = "<<fileName;

    string dir = getDir();
    cout<<"\ncurrent dir = "<<dir<<endl;
    QString direc = QString::fromStdString(dir);
    setDir(direc.toStdString());
    libPath = direc.toStdString();
    cout<<"libPath = "<<libPath<<endl;

    int pos;
    string toCopy = fileName.toStdString();
    cout<<"toCopy = "<<toCopy<<endl;
    pos = toCopy.rfind("/") + 1;
    cout<<pos<<endl;
    toCopy = toCopy.substr(pos);
    cout<<"toCopy = "<<toCopy<<endl;
    QString file = QString::fromStdString(toCopy);

    direc = direc + "\\" + file;
    qDebug()<<"copying from (fileName): "<<fileName;
    qDebug()<<"copying to (direc): "<<direc<<endl;
    QFile::copy(fileName, direc);
    //cout<<direc.toStdString();


    /*
    string newSong;
    newSong = fileName.toStdString();
    files.push_back(newSong);
    cout<<newSong<<endl;
    fileName = QDir().dirName();
    qDebug()<<fileName;
    QString song = QString::fromStdString(newSong);
    song = fileName + song;
    qDebug()<<song;
    QDir().mkpath(song);
    */
}

string Library::operator[](int index)
{
    return files[index];
}

string Library::getDir()
{
    return libPath;
}
