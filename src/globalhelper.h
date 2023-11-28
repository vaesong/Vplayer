// 防止这个头文件被重复包含的宏定义
#ifndef GLOBALHELPER_H
#define GLOBALHELPER_H

// 设置执行字符集为UTF-8
#pragma execution_character_set("utf-8")

// 定义一个枚举类型ERROR_CODE，用于整个应用程序的错误代码
enum ERROR_CODE
{
    NoError = 0,         // 表示没有错误发生
    ErrorFileInvalid     // 表示文件无效的错误代码
};

// 包含必要的Qt模块和类
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <QStringList>

// GlobalHelper类的声明，提供静态的实用函数
class GlobalHelper
{
public:
    GlobalHelper(); // 构造函数声明

    // 静态方法，从给定路径获取样式表，返回类型为QString
    static QString GetQssStr(QString strQssPath);

    // 静态方法，为QPushButton设置图标
    static void SetIcon(QPushButton* btn, int iconSize, QChar icon);

    // 静态方法，保存播放列表
    static void SavePlaylist(QStringList& playList);
    // 静态方法，获取播放列表
    static void GetPlaylist(QStringList& playList);
    // 静态方法，保存音量
    static void SavePlayVolume(double& nVolume);
    // 静态方法，获取音量
    static void GetPlayVolume(double& nVolume);

    // 静态方法，获取应用程序版本
    static QString GetAppVersion();
};

// 以下宏定义是为了兼容C和C99标准，如果没有定义INT64_C，则定义它
#ifndef INT64_C
#define INT64_C
#define UINT64_C
#endif

// 包含FFmpeg库和SDL2库的头文件，使用extern "C"是为了C++代码能够链接C库
extern "C"{
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/fifo.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/time.h"
#include "libavutil/bprint.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavfilter/avfilter.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "libswresample/swresample.h"

#include "SDL2/SDL.h"
}

// 定义滑块的最大值为65536
#define MAX_SLIDER_VALUE 65536

#endif // GLOBALHELPER_H // 结束宏定义，确保头文件内容不被重复包含
