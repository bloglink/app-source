/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       样式表皮肤
*******************************************************************************/
#ifndef APPSOURCE_H
#define APPSOURCE_H

#include <QFile>
#include <QLabel>
#include <QDebug>
#include <QFrame>
#include <QLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QGroupBox>
#include <QToolButton>
#include <QPushButton>
#include <QMainWindow>
#include <QApplication>
#include <QFontDatabase>
#include <QSplitter>
#include <QProgressBar>
#include <QSlider>
#include <QScrollBar>
#include <QMouseEvent>
#include <QListView>

#include <QTabWidget>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTreeWidget>

#define TSIZE 32

class AppSource : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppSource(QWidget *parent = 0);
    ~AppSource();
private slots:
    void initUI();
    void initSkin();
    void initLayout();
    void initTitleBar();
    void initInputBar();
    void initContents();
    void initButtonBar();
    void initCheckBoxBar();
    void initDateTimeBar();
    void initSplitterBar();
    void initTabWidgetBar();
    void initTreeWidgetBar();
    void initTableWidgetBar();
    void changeShow();
    void changeSkin(QString msg);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
private:
    QVBoxLayout *layout;
    QVBoxLayout *topLayout;
    QVBoxLayout *btnLayout;
    QSplitter *splitter;
    QTabWidget *view;
    QStringList names;
    QVariantMap skins;

    QLabel *textLabel;

    bool leftbuttonpressed;
    QPoint dragPosition;
    int preindex;
};

#endif // APPSOURCE_H
