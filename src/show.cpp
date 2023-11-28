#include <QDebug>
#include <QMutex>

#include "show.h"
#include "ui_show.h"

#include "globalhelper.h"

#pragma execution_character_set("utf-8")

QMutex g_show_rect_mutex;

Show::Show(QWidget *parent) : QWidget(parent), ui(new Ui::Show), m_stActionGroup(this), m_stMenu(this){
    ui->setupUi(this);

    //加载样式
    setStyleSheet(GlobalHelper::GetQssStr("://asset/qss/show.css"));
    setAcceptDrops(true);
}

Show::~Show()
{
    delete ui;
}

bool Show::Init(){

    return true;
}
