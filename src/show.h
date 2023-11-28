#ifndef SHOW_H
#define SHOW_H

#include <QWidget>
#include <QMimeData>
#include <QDebug>
#include <QTimer>
#include <QDragEnterEvent>
#include <QKeyEvent>
#include <QMenu>
#include <QActionGroup>
#include <QAction>

#include "videoctl.h"

namespace Ui{
class Show;
}

class Show : public QWidget{
    Q_OBJECT

public:
    Show(QWidget *parent);
    ~Show();

    bool Init();

private:
    Ui::Show *ui;

    int m_nLastFrameWidth; ///< 记录视频宽高
    int m_nLastFrameHeight;

    QTimer timerShowCursor;

    QMenu m_stMenu;
    QActionGroup m_stActionGroup;
};





#endif // SHOW_H
