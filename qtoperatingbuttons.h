#ifndef QTOPERATINGBUTTONS_H
#define QTOPERATINGBUTTONS_H

#include <QFrame>

namespace Ui {
class QtOperatingButtons;
}

class QtOperatingButtons : public QFrame
{
    Q_OBJECT

public:
    explicit QtOperatingButtons(QWidget *parent = nullptr);
    ~QtOperatingButtons();

private:
    Ui::QtOperatingButtons *ui;
};

#endif // QTOPERATINGBUTTONS_H
