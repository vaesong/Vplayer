
#include <QDebug>
#include <QTime>
#include <QSettings>

#include "ctrlbar.h"
#include "ui_CtrlBar.h"

//构造函数，根据父指针来设置
CtrlBar::CtrlBar(QWidget *parent) : QWidget(parent), ui(new Ui::CtrlBar){
    ui->setupUi(this);
}

//析构函数，释放类的指针
CtrlBar::~CtrlBar(){
    delete ui;
}

bool CtrlBar::Init(){

    return true;
}
