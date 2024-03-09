#include "qtoperatingbuttons.h"
#include "ui_qtoperatingbuttons.h"

QtOperatingButtons::QtOperatingButtons(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::QtOperatingButtons)
{
    ui->setupUi(this);
}

QtOperatingButtons::~QtOperatingButtons()
{
    delete ui;
}
