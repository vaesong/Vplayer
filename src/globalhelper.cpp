// 包含Qt框架的文件操作、调试输出、设置管理、核心应用程序和目录操作相关的头文件
#include <QFile>
#include <QDebug>
#include <QSettings>
#include <QCoreApplication>
#include <QDir>

// 包含自定义的全局帮助类头文件
#include "globalhelper.h"

// 定义播放器配置文件的基目录为临时目录
const QString PLAYER_CONFIG_BASEDIR = QDir::tempPath();

// 定义播放器配置文件的名称
const QString PLAYER_CONFIG = "player_config.ini";

// 定义应用程序的版本号
const QString APP_VERSION = "0.1.0";

// GlobalHelper类的构造函数实现
GlobalHelper::GlobalHelper()
{

}

// 从指定路径读取QSS样式表文件，并返回样式表内容的字符串
QString GlobalHelper::GetQssStr(QString strQssPath)
{
    QString strQss;
    QFile FileQss(strQssPath);
    if (FileQss.open(QIODevice::ReadOnly))
    {
        strQss = QLatin1String(FileQss.readAll());
        FileQss.close();
    }
    else
    {
        qDebug() << "读取样式表失败" << strQssPath;
    }
    return strQss;
}

// 为QPushButton设置FontAwesome图标
void GlobalHelper::SetIcon(QPushButton* btn, int iconSize, QChar icon)
{
    QFont font;
    font.setFamily("FontAwesome");
    font.setPointSize(iconSize);

    btn->setFont(font);
    btn->setText(icon);
}

// 将播放列表保存到配置文件中
void GlobalHelper::SavePlaylist(QStringList& playList)
{
    QString strPlayerConfigFileName = PLAYER_CONFIG_BASEDIR + QDir::separator() + PLAYER_CONFIG;
    QSettings settings(strPlayerConfigFileName, QSettings::IniFormat);
    settings.beginWriteArray("playlist");
    for (int i = 0; i < playList.size(); ++i)
    {
        settings.setArrayIndex(i);
        settings.setValue("movie", playList.at(i));
    }
    settings.endArray();
}

// 从配置文件中读取播放列表
void GlobalHelper::GetPlaylist(QStringList& playList)
{
    QString strPlayerConfigFileName = PLAYER_CONFIG_BASEDIR + QDir::separator() + PLAYER_CONFIG;
    QSettings settings(strPlayerConfigFileName, QSettings::IniFormat);

    int size = settings.beginReadArray("playlist");
    for (int i = 0; i < size; ++i)
    {
        settings.setArrayIndex(i);
        playList.append(settings.value("movie").toString());
    }
    settings.endArray();
}

// 将播放音量保存到配置文件中
void GlobalHelper::SavePlayVolume(double& nVolume)
{
    QString strPlayerConfigFileName = PLAYER_CONFIG_BASEDIR + QDir::separator() + PLAYER_CONFIG;
    QSettings settings(strPlayerConfigFileName, QSettings::IniFormat);
    settings.setValue("volume/size", nVolume);
}

// 从配置文件中读取播放音量
void GlobalHelper::GetPlayVolume(double& nVolume)
{
    QString strPlayerConfigFileName = PLAYER_CONFIG_BASEDIR + QDir::separator() + PLAYER_CONFIG;
    QSettings settings(strPlayerConfigFileName, QSettings::IniFormat);
    nVolume = settings.value("volume/size", nVolume).toDouble();
}

// 获取应用程序的版本号
QString GlobalHelper::GetAppVersion()
{
    return APP_VERSION;
}
