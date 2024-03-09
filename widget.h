#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMimeData>
#include <QUrl>
#include <QList>
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTableWidgetItem>
#include <QCoreApplication>
#include <QScrollBar>
#include <QAbstractItemView>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    inline void setAdaptive(int rownum);
    inline void addLineInformation(QFileInfo& fileInfo);


private slots:
    void receiveDragFile(const QMimeData* mimeData);//接收拖动文件
    void selectUiFileManually();//手动选择
};
#endif // WIDGET_H
