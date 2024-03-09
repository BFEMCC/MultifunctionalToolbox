#ifndef DRAGFRAME_H
#define DRAGFRAME_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QUrl>
#include <QList>

class DragFrame : public QFrame
{
    Q_OBJECT
public:
    DragFrame(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event)override;

    void dragEnterEvent(QDragEnterEvent* event)override;//拖入事件
    void dropEvent(QDropEvent* event)override;//拖入后松开事件


signals:
    void dragFilePaths(const QMimeData*);
};

#endif // DRAGFRAME_H
