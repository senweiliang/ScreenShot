/********************************************************************************
** Form generated from reading UI file 'ScreenShot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSHOT_H
#define UI_SCREENSHOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenShotClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenShotClass)
    {
        if (ScreenShotClass->objectName().isEmpty())
            ScreenShotClass->setObjectName(QString::fromUtf8("ScreenShotClass"));
        ScreenShotClass->resize(512, 131);
        centralWidget = new QWidget(ScreenShotClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        ScreenShotClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScreenShotClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 512, 26));
        ScreenShotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenShotClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ScreenShotClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScreenShotClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ScreenShotClass->setStatusBar(statusBar);

        retranslateUi(ScreenShotClass);

        QMetaObject::connectSlotsByName(ScreenShotClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenShotClass)
    {
        ScreenShotClass->setWindowTitle(QApplication::translate("ScreenShotClass", "ScreenShot", nullptr));
        label->setText(QApplication::translate("ScreenShotClass", "0.01\347\211\210\346\234\254", nullptr));
        label_2->setText(QApplication::translate("ScreenShotClass", "\344\275\277\347\224\250CTRL+ALT+M\346\210\252\345\233\276\345\271\266\344\275\277\347\224\250\351\274\240\346\240\207\351\200\211\345\256\232\345\214\272\345\237\237\357\274\214\351\200\211\345\256\232\345\214\272\345\237\237\350\207\252\345\212\250\345\244\215\345\210\266\345\210\260\347\262\230\350\264\264\346\235\277\344\270\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenShotClass: public Ui_ScreenShotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSHOT_H
