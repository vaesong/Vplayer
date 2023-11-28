#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_stPlaylist(this),
    m_stTitle(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Init(){

    //创建一个新的 QWidget,作为控件的上层
    QWidget *em = new QWidget(this);
    ui->PlayListWid->setTitleBarWidget(em);
    ui->PlayListWid->setWidget(&m_stPlaylist);

    QWidget *emTitle = new QWidget(this);
    ui->TitleWid->setTitleBarWidget(emTitle);
    ui->TitleWid->setWidget(&m_stTitle);


    if(ui->CtrlBarWid->Init() == false ||
       ui->ShowWid->Init() == false ||
       m_stTitle.Init() == false ||
       m_stPlaylist.Init() == false
       ){
        return false;
    }

    return true;
}

