#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ScreenShot.h"
#include "PicturePicker.h"

class ScreenShot : public QMainWindow
{
    Q_OBJECT

public:
    ScreenShot(QWidget *parent = Q_NULLPTR);

protected:
    bool nativeEvent(const QByteArray& eventType, void* message, long* result);

private slots:
    //void on_pushButton_clicked();
    void slotPickDone();
private:
    Ui::ScreenShotClass ui;
    QPixmap pixmap;
    PicturePicker* picturePicker;

    void init();
    void capture();

};
