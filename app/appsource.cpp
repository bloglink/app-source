/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       样式表皮肤
*******************************************************************************/
#include "appsource.h"

AppSource::AppSource(QWidget *parent) : QMainWindow(parent, Qt::FramelessWindowHint)
{
    initUI();
}

AppSource::~AppSource()
{
}

void AppSource::initUI()
{
    initSkin();
    initLayout();
    initTitleBar();
    initInputBar();
    initContents();
    initButtonBar();
    initCheckBoxBar();
    initDateTimeBar();
    initSplitterBar();
    initTabWidgetBar();
    initTreeWidgetBar();
    initTableWidgetBar();
}

void AppSource::initSkin()
{
    QFile file;
    QString qss;
    file.setFileName(":/qss_black.css");
    file.open(QFile::ReadOnly);
    qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
}

void AppSource::initLayout()
{
    layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);

    topLayout = new QVBoxLayout;
    layout->addLayout(topLayout);

    splitter = new QSplitter(Qt::Vertical, this);
    QVBoxLayout *barLayout = new QVBoxLayout;
    barLayout->setMargin(5);
    barLayout->addWidget(splitter);
    layout->addLayout(barLayout);

    QFrame *frame = new QFrame(this);
    frame->setLayout(layout);

    this->setCentralWidget(frame);
    this->resize(640, 720);
}

void AppSource::initTitleBar()
{
    QHBoxLayout *title = new QHBoxLayout;
    title->setMargin(0);
    title->setSpacing(0);

    QFrame *frame = new QFrame(this);
    frame->setLayout(title);
    topLayout->addWidget(frame);

    QLabel *iconLabel = new QLabel(this);
    iconLabel->setFixedSize(25, 25);
    iconLabel->setPixmap(QPixmap(":/icon_link.ico"));
    iconLabel->setScaledContents(true);
    title->addWidget(iconLabel);

    char s_month[5];
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    int month, day, year;

    sscanf((__DATE__), "%s %d %d", s_month, &day, &year);
    month = (strstr(month_names, s_month)-month_names)/3+1;

    QDate dt;
    dt.setDate(year, month, day);
    static const QTime tt = QTime::fromString(__TIME__, "hh:mm:ss");

    QDateTime t(dt, tt);
    QString verNumb = QString("V-0.1.%1").arg(t.toString("yyMMdd-hhmm"));

    textLabel = new QLabel(tr("自定义UI演示%1").arg(verNumb), this);
    title->addWidget(textLabel);

    title->addStretch();

    QToolButton *min = new QToolButton(this);
    min->setObjectName("min");
    min->setFixedSize(TSIZE, TSIZE);
    min->setFocusPolicy(Qt::NoFocus);
    min->setIconSize(QSize(TSIZE, TSIZE));
    min->setIcon(QIcon(":/icon_min.png"));
    title->addWidget(min);
    connect(min, SIGNAL(clicked(bool)), this, SLOT(changeShow()));

    QToolButton *max = new QToolButton(this);
    max->setObjectName("max");
    max->setFixedSize(TSIZE, TSIZE);
    max->setFocusPolicy(Qt::NoFocus);
    max->setIconSize(QSize(TSIZE, TSIZE));
    max->setIcon(QIcon(":/icon_max.png"));
    title->addWidget(max);
    connect(max, SIGNAL(clicked(bool)), this, SLOT(changeShow()));

    QToolButton *ext = new QToolButton(this);
    ext->setFixedSize(TSIZE, TSIZE);
    ext->setFocusPolicy(Qt::NoFocus);
    ext->setIconSize(QSize(TSIZE, TSIZE));
    ext->setIcon(QIcon(":/icon_ext.png"));
    title->addWidget(ext);
    connect(ext, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void AppSource::initInputBar()
{
    QHBoxLayout *input = new QHBoxLayout;

    QGroupBox *group = new QGroupBox(this);
    group->setLayout(input);
    splitter->addWidget(group);

    input->addWidget(new QLabel(tr("密码输入"), this));

    QLineEdit *pwd = new QLineEdit(this);
    pwd->setFixedHeight(30);
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setText("123456");
    input->addWidget(pwd);

    QSpinBox *spn = new QSpinBox(this);
    spn->setFixedHeight(30);
    spn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    input->addWidget(spn);

    QDoubleSpinBox *dsp = new QDoubleSpinBox(this);
    dsp->setFixedHeight(30);
    dsp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    input->addWidget(dsp);

    QPushButton *btn = new QPushButton(tr("主窗体"), this);
    btn->setFixedHeight(35);
    btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    input->addWidget(btn);
}

void AppSource::initContents()
{
    btnLayout = new QVBoxLayout;

    QGroupBox *btnGroup = new QGroupBox(this);
    btnGroup->setLayout(btnLayout);
    splitter->addWidget(btnGroup);
}

void AppSource::initButtonBar()
{
    QHBoxLayout *layout1 = new QHBoxLayout;
    btnLayout->addLayout(layout1);

    QLineEdit *edit = new QLineEdit(this);
    edit->setText(tr("今天天气不错"));
    edit->setFixedHeight(30);
    layout1->addWidget(edit);

    QPushButton *msgButton = new QPushButton(this);
    msgButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    msgButton->setText(tr("信息框"));
    msgButton->setFixedSize(97, 35);
    layout1->addWidget(msgButton);

    QPushButton *qstButton = new QPushButton(this);
    qstButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    qstButton->setText(tr("询问框"));
    qstButton->setFixedSize(97, 35);
    layout1->addWidget(qstButton);

    QPushButton *errButton = new QPushButton(this);
    errButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    errButton->setText(tr("错误框"));
    errButton->setFixedSize(97, 35);
    layout1->addWidget(errButton);

    QPushButton *iptButton = new QPushButton(this);
    iptButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    iptButton->setText(tr("输入框"));
    iptButton->setFixedSize(97, 35);
    layout1->addWidget(iptButton);
}

void AppSource::initCheckBoxBar()
{
    QHBoxLayout *layout1 = new QHBoxLayout;
    btnLayout->addLayout(layout1);

    QRadioButton *btn1 = new QRadioButton(this);
    btn1->setText(tr("男"));
    layout1->addWidget(btn1);

    QRadioButton *btn2 = new QRadioButton(this);
    btn2->setText(tr("女"));
    layout1->addWidget(btn2);

    QCheckBox *btn3 = new QCheckBox(this);
    btn3->setText(tr("中国"));
    layout1->addWidget(btn3);

    QCheckBox *btn4 = new QCheckBox(this);
    btn4->setText(tr("美国"));
    layout1->addWidget(btn4);

    names << tr("黑色") << tr("浅蓝");

    QComboBox *box1 = new QComboBox(this);
    box1->setFixedHeight(35);
    box1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    box1->setView(new QListView);
    box1->addItems(names);
    layout1->addWidget(box1);
    connect(box1, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeSkin(QString)));

    QTimeEdit *box2 = new QTimeEdit(this);
    box2->setFixedHeight(35);
    layout1->addWidget(box2);

    QPushButton *iptButton = new QPushButton(this);
    iptButton->setEnabled(false);
    iptButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    iptButton->setText(tr("不可用按钮"));
    iptButton->setFixedSize(97, 35);
    layout1->addWidget(iptButton);
}

void AppSource::initDateTimeBar()
{
    QHBoxLayout *layout1 = new QHBoxLayout;
    btnLayout->addLayout(layout1);

    QDateEdit *box1 = new QDateEdit(this);
    box1->setFixedHeight(35);
    layout1->addWidget(box1);

    QDateTimeEdit *box2 = new QDateTimeEdit(this);
    box2->setFixedHeight(35);
    layout1->addWidget(box2);

    QDateEdit *box3 = new QDateEdit(this);
    box3->setCalendarPopup(true);
    box3->setFixedHeight(35);
    layout1->addWidget(box3);

    QDateTimeEdit *box4 = new QDateTimeEdit(this);
    box4->setCalendarPopup(true);
    box4->setFixedHeight(35);
    layout1->addWidget(box4);
}

void AppSource::initSplitterBar()
{
    QProgressBar *bar1 = new QProgressBar(this);
    bar1->setValue(50);
    bar1->setFixedHeight(25);
    btnLayout->addWidget(bar1);

    QSlider *bar2 = new QSlider(Qt::Horizontal, this);
    btnLayout->addWidget(bar2);

    QScrollBar *bar3 = new QScrollBar(Qt::Horizontal, this);
    bar3->setFixedHeight(15);
    btnLayout->addWidget(bar3);
}

void AppSource::initTabWidgetBar()
{
    view = new QTabWidget(this);
    splitter->addWidget(view);
}

void AppSource::initTreeWidgetBar()
{
    QFrame *frame1 = new QFrame(this);
    view->addTab(frame1, tr("选项卡1"));
    QVBoxLayout *layout1 = new QVBoxLayout;
    frame1->setLayout(layout1);
    QTreeWidget *onlineTree = new QTreeWidget(this);
    onlineTree->setHeaderHidden(true);
    layout1->addWidget(onlineTree);
    onlineTree->setColumnCount(2);

    QString msg = "MyFile/\nMyText/\naip.exe*\nfile";

    QString temp = msg;
    QStringList FileList = temp.split("\n", QString::SkipEmptyParts);
    for (int i=0; i < FileList.size(); i++) {
        QString t = FileList.at(i);
        QTreeWidgetItem *item = new QTreeWidgetItem;
        if (t.endsWith("/")) {
            item->setText(0, t.remove("/"));
            QPixmap pixmap(":/icon_dir.png");
            item->setIcon(0, pixmap);
            item->setText(1, "文件夹");
        } else if (t.endsWith("*")) {
            item->setText(0, t.remove("*"));
            QPixmap pixmap(":/icon_link.png");
            item->setIcon(0, pixmap);
            item->setText(1, "程序");
        } else {
            item->setText(0, t.remove("*"));
            QPixmap pixmap(":/icon_file.png");
            item->setIcon(0, pixmap);
            item->setText(1, "文件");
        }
        onlineTree->addTopLevelItem(item);
    }
}

void AppSource::initTableWidgetBar()
{
    QFrame *frame2 = new QFrame(this);
    view->addTab(frame2, tr("选项卡2"));
    QVBoxLayout *layout2 = new QVBoxLayout;
    frame2->setLayout(layout2);
    QTableWidget *view2 = new QTableWidget(this);
    layout2->addWidget(view2);
    view2->setColumnCount(2);
    view2->setRowCount(5);

    QStringList tmp;
    tmp << tr("张三") << tr("李四") << tr("王五") << tr("赵六") << tr("周七");
    for (int i=0; i < 5; i++) {
        view2->setItem(i, 0, new QTableWidgetItem(tmp.at(i)));
        view2->setItem(i, 1, new QTableWidgetItem(QString::number(i+89)));
    }
}

void AppSource::changeShow()
{
    if (this->isMaximized()) {
        this->showNormal();
    } else {
        this->showMaximized();
    }
}

void AppSource::changeSkin(QString msg)
{
    skins[tr("黑色")] = ":/qss_black.css";
    skins[tr("浅蓝")] = ":/qss_light.css";
    QFile file;
    QString qss;
    file.setFileName(skins[msg].toString());
    file.open(QFile::ReadOnly);
    qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
}

void AppSource::mousePressEvent(QMouseEvent *e)
{
    if (e->button() & Qt::LeftButton) {
        if (e->y() < this->height() && e->x() > this->width() - 120) {
            leftbuttonpressed = false;
        } else {
            dragPosition = e->globalPos() - frameGeometry().topLeft();
            leftbuttonpressed = true;
        }
    }
    e->accept();
}

void AppSource::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    e->accept();
}

void AppSource::mouseMoveEvent(QMouseEvent *e)
{
    if (isMaximized()) {
        e->ignore();
    } else {
        if (e->y() < this->height() && e->x() > this->width() - 120) {
            e->ignore();
        } else {
            if (leftbuttonpressed) {
                this->move(e->globalPos() - dragPosition);
                e->accept();
            }
        }
    }
}
