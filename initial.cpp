#include "MainWindow.h"
//#include "ui_mainwindow.h"
#include "library.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->tableWidget->verticalScrollBar();
    ui->tableWidget->setRowCount(lib.size());
    ui->tableWidget->setColumnCount(3);
    for(int i = 0; i < lib.size(); i++)
    {
        string loading;
        loading = "Now loading ";
        loading += lib[i].c_str();
        qDebug(loading.c_str());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(lib[i].c_str()));
    }
    tableHeader<<"File Name"<<"Size"<<"Date";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setStyleSheet("QTableView {selection-background-color: red;}");
    ui->tableWidget->setGeometry(QApplication::desktop()->screenGeometry());

    connect( ui->tableWidget, SIGNAL( cellDoubleClicked (int, int) ),
             this, SLOT( cellSelected( int, int ) ) );
    connect(&lib,SIGNAL(musicAdded()), this, SLOT(updateMusic()));
    connect(ui->addMusic, SIGNAL(clicked()),&lib,SLOT(addMusic()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cellSelected(int nRow, int nCol)
{

    openPlayer();

    /*
    QMessageBox::information(this, "",
                            "Cell at row "+QString::number(nRow)+
                             " column "+QString::number(nCol)+
                             " was double clicked.");
                             */
}


void  MainWindow::addMusic()
{
    lib.addMusic();
}

void  MainWindow::updateMusic()
{
    //Update tableWidget here
}

void MainWindow::openPlayer()
{
    player = new MainWindow();
    player->show();
}
