// 包含处理上下文菜单事件和文件对话框的Qt头文件
#include <QContextMenuEvent>
#include <QFileDialog>

#include "medialist.h" // 自定义的媒体列表类的头文件

#pragma execution_character_set("utf-8") // 设置此源文件的字符编码为UTF-8

// MediaList类的构造函数
MediaList::MediaList(QWidget *parent)
    : QListWidget(parent), // 调用基类QListWidget的构造函数
    m_stMenu(this),      // 初始化右键菜单
    m_stActAdd(this),    // 初始化添加动作
    m_stActRemove(this), // 初始化移除所选项动作
    m_stActClearList(this) // 初始化清空列表动作
{
    // 构造函数体为空
}

// MediaList类的析构函数
MediaList::~MediaList()
{
    // 析构函数体为空
}

// MediaList类的初始化函数
bool MediaList::Init()
{
    // 设置添加动作的文本并将其添加到菜单中
    m_stActAdd.setText("添加");
    m_stMenu.addAction(&m_stActAdd);

    // 设置移除动作的文本并将其添加到一个新的子菜单中
    m_stActRemove.setText("移除所选项");
    QMenu* stRemoveMenu = m_stMenu.addMenu("移除");
    stRemoveMenu->addAction(&m_stActRemove);

    // 设置清空列表动作的文本并将其添加到菜单中
    m_stActClearList.setText("清空列表");
    m_stMenu.addAction(&m_stActClearList);

    // 连接动作的触发信号到对应的槽函数
    connect(&m_stActAdd, &QAction::triggered, this, &MediaList::AddFile);
    connect(&m_stActRemove, &QAction::triggered, this, &MediaList::RemoveFile);
    connect(&m_stActClearList, &QAction::triggered, this, &QListWidget::clear);

    // 初始化函数返回true，表示初始化成功
    return true;
}

// 当上下文菜单事件发生时调用此函数
void MediaList::contextMenuEvent(QContextMenuEvent* event)
{
    // 在鼠标点击位置显示上下文菜单
    m_stMenu.exec(event->globalPos());
}

// 添加文件的槽函数
void MediaList::AddFile()
{
    // 弹出文件对话框并获取用户选择的文件
    QStringList listFileName = QFileDialog::getOpenFileNames(
        this, "打开文件", QDir::homePath(),
        "视频文件(*.mkv *.rmvb *.mp4 *.avi *.flv *.wmv *.3gp)");

    // 遍历选择的文件，并发出添加文件的信号
    for (QString strFileName : listFileName)
    {
        emit SigAddFile(strFileName);
    }
}

// 移除文件的槽函数
void MediaList::RemoveFile()
{
    // 移除当前选中的项
    takeItem(currentRow());
}
