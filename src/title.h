#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QActionGroup>
#include <QAction>

namespace Ui{
class Title;
}

class Title : public QWidget{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();

    bool Init();

private:
    bool InitUi();      //初始化 UI

private:
    Ui::Title *ui;      //

    QString m_strMovieName;

    QMenu m_stMenu;
    QActionGroup m_stActionGroup;
};






#endif // TITLE_H

