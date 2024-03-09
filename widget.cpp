#include "widget.h"
#include "ui_widget.h"
#include "qtoperatingbuttons.h"

// QApplication::applicationDirPath()//运行目录
// QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);//下载目录
// QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);桌面路径
// QDir::homePath();//主页home路径

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->dragFrame,&DragFrame::dragFilePaths,this,&Widget::receiveDragFile);
    connect(ui->selectFileButton,&QPushButton::clicked,this,&Widget::selectUiFileManually);

    ui->detailsList->setColumnWidth(0, 150);// 设置第1列的列宽为 200
    // ui->detailsList->verticalHeader()->setVisible(false);//隐藏默认显示的数字行头
    // ui->detailsList->setAlternatingRowColors(true);//隔行交替背景色
    // ui->detailsList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自动分配大小
    // ui->detailsList->horizontalHeader()->setStretchLastSection(true);//水平方向标签拓展剩下的窗口部分，填满表格
    ui->detailsList->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//第1列不可调整大小
    ui->detailsList->setFocusPolicy(Qt::NoFocus);//去除选中虚线和蓝色背景
    ui->detailsList->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->detailsList->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中模式为选中行
    ui->detailsList->setWordWrap(false);//不自动换行

    //设置平滑滚动
    ui->detailsList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel); //垂直滚动条设置为像素移动
    ui->detailsList->verticalScrollBar()->setSingleStep(5); //获取垂直滚动条//设置单步，值越小，下滑越慢
    ui->detailsList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->detailsList->horizontalScrollBar()->setSingleStep(5);

    resize(1200,700);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setAdaptive(int rownum)
{
    ui->detailsList->resizeColumnToContents(0); //第1列的宽度自适应
    ui->detailsList->resizeColumnToContents(1); //第2列的宽度自适应
    ui->detailsList->resizeColumnToContents(2); //第3列的宽度自适应
    ui->detailsList->resizeColumnToContents(3); //第4列的宽度自适应
    ui->detailsList->setRowHeight(rownum, 60);
}

void Widget::addLineInformation(QFileInfo &fileInfo)
{
    int rowCount = ui->detailsList->rowCount();//获取当前行数
    ui->detailsList->insertRow(rowCount);//在当前行后面新增一行

    QtOperatingButtons* operatings  = new QtOperatingButtons(ui->detailsList);
    QTableWidgetItem* fileName = new QTableWidgetItem(fileInfo.fileName());
    QTableWidgetItem* filePath = new QTableWidgetItem(fileInfo.filePath());
    QTableWidgetItem* savePath = new QTableWidgetItem(QStandardPaths::writableLocation(QStandardPaths::DownloadLocation));

    ui->detailsList->setCellWidget(rowCount,0,operatings);
    ui->detailsList->setItem(rowCount,1, fileName);
    ui->detailsList->setItem(rowCount,2, filePath);
    ui->detailsList->setItem(rowCount,3, savePath);
    this->setAdaptive(rowCount);
}

void Widget::receiveDragFile(const QMimeData *mimeData)
{
    for(const QUrl& fileUrl : mimeData->urls())
    {
        QFileInfo fileInfo(fileUrl.toLocalFile());

        if(fileInfo.suffix().toLower() == "ui")
            this->addLineInformation(fileInfo);
        else
            QMessageBox::warning(this,"格式不正确",fileInfo.fileName()+" 不是ui文件",QMessageBox::Ok);
    }
}

void Widget::selectUiFileManually()
{
    QStringList filePaths = QFileDialog::getOpenFileNames(this,"选择ui文件",QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),"ui文件 (*.ui)");
    if(!filePaths.isEmpty())
    {
        for(QString& filePath : filePaths)
        {
            QFileInfo fileInfo(filePath);
            this->addLineInformation(fileInfo);
        }
    }

}
