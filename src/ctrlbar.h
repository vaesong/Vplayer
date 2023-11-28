#ifndef CTRLBAR_H
#define CTRLBAR_H

#include <QWidget>

//命名空间
namespace Ui{
class CtrlBar;
}

class CtrlBar : public QWidget{
    Q_OBJECT

public:
    //构造函数与析构函数
    explicit CtrlBar(QWidget *parent = 0);
    ~CtrlBar();

    //做一些初始化
    bool Init();

private:
    //指向该类的指针
    Ui::CtrlBar *ui;

};






#endif // CTRLBAR_H


