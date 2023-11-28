#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QMenu>
#include <QAction>
#include <QPropertyAnimation>
#include <QTimer>
#include <QMainWindow>

#include "playlist.h"
#include "title.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //初始化
    bool Init();

private:
    Ui::MainWindow *ui;

    bool m_bPlaying; ///< 正在播放


    PlayList m_stPlaylist;
    Title m_stTitle;

};
#endif // MAINWINDOW_H
