/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       样式表皮肤
*******************************************************************************/
#include <QApplication>
#include <QTranslator>
#include "appsource.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtTran;
    qtTran.load(":/qt_zh_CN.qm");
    a.installTranslator(&qtTran);

    QTranslator qtBase;
    qtBase.load(":/qtbase_zh_CN.qm");
    a.installTranslator(&qtBase);

    AppSource w;
    w.show();

    return a.exec();
}
