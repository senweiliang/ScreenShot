#include "ScreenShot.h"
#include "windows.h"
#include <QMessageBox>
#include <QBoxLayout>
#include <QDebug>
#include "PictureDialog.h"
#include <QScreen>
#include <qthread.h>
#include <QClipboard>

ScreenShot::ScreenShot(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    init();
    
}

bool ScreenShot::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
    Q_UNUSED(eventType);
    Q_UNUSED(result);
    MSG* msg = static_cast<MSG*>(message);
    if (msg->message == WM_HOTKEY)
    {
        //QMessageBox::information(this, "OK", "Hotkey pressed!");
        this->showMinimized();
        QThread::msleep(200);
        capture();
        picturePicker = new PicturePicker;
        connect(picturePicker, &PicturePicker::sigPickDone, this, &ScreenShot::slotPickDone);
        picturePicker->setPicture(pixmap);
        pixmap.fill(QColor(255,0,0,1));
        picturePicker->setPixmap(pixmap);
        picturePicker->setFixedSize(pixmap.size());
        picturePicker->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        picturePicker->show();
        //QApplication::clipboard()->setPixmap(pixmap, QClipboard::Clipboard);
        return true;
    }
    return false;
}

void ScreenShot::slotPickDone()
{
    delete picturePicker;
    this->showMinimized();
    //this->show();

}

void ScreenShot::init()
{
    if (!RegisterHotKey(HWND(winId()), 0, MOD_ALT | MOD_CONTROL, 0x4D))
    {
        QMessageBox::warning(this, "Warning", "Can't register hotkey ALT+CTRL+M");
    }
}

//void ScreenShot::on_pushButton_clicked()
//{
//    this->hide();
//    QThread::msleep(200);
//    capture();
//    PictureDialog* dialog = new PictureDialog;
//    dialog->setPicture(pixmap);
//    dialog->exec();
//    this->show();
//
//}

void ScreenShot::capture()
{
    pixmap = QApplication::primaryScreen()->grabWindow(0);
    //pixmap.save("./screen.png", "png", -1);

}
