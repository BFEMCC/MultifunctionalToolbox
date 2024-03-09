#include "dragframe.h"


DragFrame::DragFrame(QWidget* parent)
    :QFrame{parent}
{
    setAcceptDrops(true);//允许接受拖拽
}

void DragFrame::paintEvent(QPaintEvent *event)
{
    return QFrame::paintEvent(event);
}

void DragFrame::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
}

void DragFrame::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        emit dragFilePaths(event->mimeData());
    }
}
