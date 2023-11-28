#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QListWidgetItem>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>

namespace Ui{
class PlayList;
}

class PlayList : public QWidget{
    Q_OBJECT

public:
    explicit PlayList(QWidget *parent);
    ~PlayList();

    bool Init();


private:
    bool InitUi();


private:
    Ui::PlayList *ui;

    int m_nCurrentPlayListIndex;    //当前正在播放的视频的 索引
};



#endif // PLAYLIST_H
