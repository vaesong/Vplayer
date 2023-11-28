#include <QPainter>
#include <QFileInfo>
#include <QFontMetrics>
#include <QMessageBox>
#include <QFileDialog>

#include "title.h"
#include "ui_title.h"

#include "globalhelper.h"

#pragma execution_character_set("utf-8")

Title::Title(QWidget *parent) : QWidget(parent), ui(new Ui::Title), m_stActionGroup(this), m_stMenu(this){
    ui->setupUi(this);

    //连接信号和槽函数
}

Title::~Title(){
    delete ui;
}

bool Title::Init(){
    if(InitUi() == false){
        return false;
    }

    return true;
}

bool Title::InitUi(){
    //清空视频名称
    ui->MovieNameLabel->clear();

    //保证窗口不被绘制上的部分透明
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet(GlobalHelper::GetQssStr("://asset/qss/title.css"));

    //设置图标
    GlobalHelper::SetIcon(ui->MaxBtn, 20, QChar(0xf2d0));
    GlobalHelper::SetIcon(ui->MinBtn, 20, QChar(0xf2d1));
    GlobalHelper::SetIcon(ui->CloseBtn, 20, QChar(0xf00d));
    GlobalHelper::SetIcon(ui->FullScreenBtn, 20, QChar(0xf065));

    return true;
}
