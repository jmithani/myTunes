#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include<QTableWidget>
#include <QStringList>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    viewLibrary();
    ui->tableWidget->verticalHeader()->setVisible(false);
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setStyleSheet("QTableView {selection-background-color: grey;}");
    ui->tableWidget->setGeometry(QApplication::desktop()->screenGeometry());


    connect(&lib,SIGNAL(musicAdded()), this, SLOT(updateMusic()));
    connect(ui->actionAdd_Music, SIGNAL(clicked()),this,SLOT(addMusic()));

    //LIBRARY MENU
    //Library actions
    connect(ui->actionAdd_Music, SIGNAL(triggered()), this, SLOT(addMusic()));

    //PLAYLIST MENU
    //Playlist actions
    connect(ui->actionAdd_Playlist, SIGNAL(triggered()), this, SLOT(addPlaylist()));
    connect(ui->actionView_Playlists_2, SIGNAL(triggered()),this,SLOT(viewPlaylists()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cellSelectedLib(int nRow, int nCol)
{
    Player *p;
    QString temp = (ui->tableWidget->item(nRow, 0)->text());
    qDebug()<<temp;

    string song = temp.toStdString();
    string path = lib.getDir() + "\\";
    song = path + song;
    cout<<song<<endl;
    p = new Player(this, song, nRow);
    p->show();
    cout<<"done\n";

    /*
    QMessageBox::information(this, "",
                            "Cell at row "+QString::number(nRow)+
                             " column "+QString::number(nCol)+
                             " was double clicked.");
                             */
}


void  MainWindow::addMusic()
{
    cout<<"\naddMusic dir = "<<lib.getDir()<<endl;
    lib.addMusic();

    lib.setDir(lib.getDir());
    updateMusic();
}

void  MainWindow::updateMusic()
{
    ui->tableWidget->clearContents();
    cout<<"updateMusic dir = "<<lib.getDir()<<endl;
    for(int i = 0; i < lib.size(); i++)
    {
        string loading;
        loading = "Now loading ";
        loading += lib[i].c_str();
        cout<<loading<<endl;
        if((loading.find(".wav") != -1) || (loading.find(".ogg") != -1))
        {
            qDebug(loading.c_str());
            //cout<<lib[i].c_str()<<endl;
            ui->tableWidget->setItem(i,0, new QTableWidgetItem(lib[i].c_str()));
        }
    }
    viewLibrary();
}

void MainWindow::addPlaylist()
{
    QInputDialog* getName = new QInputDialog;
    QString playlistName = getName->getText(this, "Playlist", "Please enter the name for the new playlist.",
                                     QLineEdit::Normal);
    //http://www.codeprogress.com/cpp/libraries/qt/showQtExample.php?key=QInputDialogGetText&index=331

    ui->menuPlaylists->addAction(playlistName);
    Playlist(playlistName.toStdString());
}

void MainWindow::viewPlaylists()
{
    ui->tableWidget->clearContents();
    Library playlists;
    playlists.setDir("resources\\playlists\\");
    cout<<playlists.getDir()<<endl;
    cout<<playlists.size()<<endl;
    for(int i = 0; i < playlists.size(); i++)
    {
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(playlists[i].c_str()));
    }
    disconnect( ui->tableWidget, SIGNAL( cellDoubleClicked (int, int) ),
             this, SLOT( cellSelectedLib( int, int ) ) );
    connect( ui->tableWidget, SIGNAL( cellDoubleClicked (int, int) ),
             this, SLOT( cellSelectedP( int, int ) ) );
}

void MainWindow::viewLibrary()
{
    disconnect( ui->tableWidget, SIGNAL( cellDoubleClicked (int, int) ),
             this, SLOT( cellSelectedP( int, int ) ) );

    ui->tableWidget->clearContents();

    //Setting up the table view for the library
    //ui->tableWidget->verticalScrollBar();
    ui->tableWidget->setRowCount(lib.size()); //includes directories
    ui->tableWidget->setColumnCount(5);

    //Loading library items
    for(int i = 0; i < lib.size(); i++)
    {
        string loading;
        loading = "Now loading ";
        loading += lib[i].c_str();
        cout<<loading<<endl;
        if((loading.find(".wav") != -1) || (loading.find(".ogg") != -1))
        {
            qDebug(loading.c_str());
            //cout<<lib[i].c_str()<<endl;
            ui->tableWidget->setItem(i,0, new QTableWidgetItem(lib[i].c_str()));
        }
    }

    //More formatting and triggers
    QStringList tableHeader;
    tableHeader<<"Title"<<"Artist"<<"Album"<<"Length"<<"Genre";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    //resizeRowsToContents();
    //resizeColumnsToContents();

    connect( ui->tableWidget, SIGNAL( cellDoubleClicked (int, int) ),
             this, SLOT( cellSelectedLib( int, int ) ) );
}

void MainWindow::cellSelectedP(int nRow, int nCol)
{
    qDebug()<<"inside cellSelectedP";
    cout<<"path = "<<lib.getDir()<<endl;
    QString temp = (ui->tableWidget->item(nRow, 0)->text());
    QString path = QString::fromStdString(lib.getDir()+"\\"+"playlists");
    path = path + "\\" + temp;
    qDebug()<<"new path = "<<path<<endl;
    lib.setDir(path.toStdString());
    viewLibrary();
}

