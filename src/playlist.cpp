#include <QDebug>
#include <QDir>

#include "playlist.h"
#include "ui_playlist.h"

#include "globalhelper.h"

PlayList::PlayList(QWidget *parent) : QWidget(parent), ui(new Ui::PlayList){
    ui->setupUi(this);
}

PlayList::~PlayList(){
    QStringList strListPlayList;

    for(int i = 0; i < ui->List->count(); ++i){
        strListPlayList.append(ui->List->item(i)->toolTip());
    }
    GlobalHelper::SavePlaylist(strListPlayList);

    delete ui;
}

bool PlayList::Init(){
    //初始化 MediaList类
    if(ui->List->Init() == false){
        return false;
    }

    //初始化界面
    if(InitUi() == false){
        return false;
    }

    return true;
}

bool PlayList::InitUi(){
    setStyleSheet(GlobalHelper::GetQssStr("://asset/qss/playlist.css"));  //设置 CSS 格式
    ui->List->clear();  //清空播放列表

    //获取列表中的视频名称
    QStringList strListPlayList;
    GlobalHelper::GetPlaylist(strListPlayList);

    for(QString strVideoFile : strListPlayList){
        QFileInfo fileInfo(strVideoFile);
        if(fileInfo.exists()){
            QListWidgetItem *pItem = new QListWidgetItem(ui->List);
            pItem->setData(Qt::UserRole, QVariant(fileInfo.filePath()));
            pItem->setText(QString("%1").arg(fileInfo.fileName()));
            pItem->setToolTip(fileInfo.filePath());
            ui->List->addItem(pItem);
        }
    }

    if(strListPlayList.length() > 0){
        ui->List->setCurrentRow(0);
    }

    return true;
}
