#include "PictureDialog.h"
#include <QDebug>
#include <QResizeEvent>
#include <QClipboard>

PictureDialog::PictureDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    //ui.label->setScaledContents(true);
    ui.label->installEventFilter(this);

    menu = new QMenu;
    menu->addAction("copy",this,SLOT(slotCopy()));
    
}

PictureDialog::~PictureDialog()
{
}

void PictureDialog::setPicture(QPixmap pic)
{
    pixmap = pic;
    QPixmap fitpixmap = pixmap.scaled(1500, 1200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui.label->setPixmap(fitpixmap);
    //label->setScaledContents(true);
    //dialog->setWindowFlags(Qt::Window);
    //dialog->setFixedSize(1200,600);
    //dialog->setPixmap(pixmap);
}
void PictureDialog::mousePressEvent(QMouseEvent* event)
{

    if (event->buttons() == Qt::RightButton)
    {
        qDebug() << "mousePressEvent RightButton"<< event->pos();
        QPoint point = mapToGlobal(event->pos());
        menu->exec(point);
    }

}

void PictureDialog::slotCopy()
{
    QApplication::clipboard()->setPixmap(pixmap, QClipboard::Clipboard);
}

//bool PictureDialog::eventFilter(QObject* obj, QEvent* event)
//{
//    if (obj == ui.label)
//    {
//        if (event->type() == QEvent::MouseButtonRelease)
//        {
//            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
//            qDebug() << "you press" << keyEvent->key();
//            //事件不再进行传播，拦截
//            return true;
//        }
//        else
//        {
//            return false;//继续传播
//        }
//    }
//    else
//    {
//        //当不确定是否继续传播时，按照父类的方法来处理
//        //即调用父类的evenFilter函数
//        return QDialog::eventFilter(obj, event);
//    }
//}