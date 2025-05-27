/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionExport_File;
    QAction *actionFile_System_Information;
    QAction *actionData_Content_Mode;
    QAction *actionMetaData_Mode;
    QAction *actionBoot_Sector;
    QAction *actionSuper_Block;
    QAction *actionGroup_Desctiptor_Table;
    QAction *actionBlock_Bitmap;
    QAction *actionInode_Bitmap;
    QAction *actionData_Block;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionInodeTable;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuData_Recovery;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName("actionopen");
        actionExport_File = new QAction(MainWindow);
        actionExport_File->setObjectName("actionExport_File");
        actionFile_System_Information = new QAction(MainWindow);
        actionFile_System_Information->setObjectName("actionFile_System_Information");
        actionData_Content_Mode = new QAction(MainWindow);
        actionData_Content_Mode->setObjectName("actionData_Content_Mode");
        actionMetaData_Mode = new QAction(MainWindow);
        actionMetaData_Mode->setObjectName("actionMetaData_Mode");
        actionBoot_Sector = new QAction(MainWindow);
        actionBoot_Sector->setObjectName("actionBoot_Sector");
        actionSuper_Block = new QAction(MainWindow);
        actionSuper_Block->setObjectName("actionSuper_Block");
        actionGroup_Desctiptor_Table = new QAction(MainWindow);
        actionGroup_Desctiptor_Table->setObjectName("actionGroup_Desctiptor_Table");
        actionBlock_Bitmap = new QAction(MainWindow);
        actionBlock_Bitmap->setObjectName("actionBlock_Bitmap");
        actionInode_Bitmap = new QAction(MainWindow);
        actionInode_Bitmap->setObjectName("actionInode_Bitmap");
        actionData_Block = new QAction(MainWindow);
        actionData_Block->setObjectName("actionData_Block");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionInodeTable = new QAction(MainWindow);
        actionInodeTable->setObjectName("actionInodeTable");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuData_Recovery = new QMenu(menuView);
        menuData_Recovery->setObjectName("menuData_Recovery");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionopen);
        menuFile->addSeparator();
        menuFile->addAction(actionExport_File);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuView->addAction(actionFile_System_Information);
        menuView->addSeparator();
        menuView->addAction(menuData_Recovery->menuAction());
        menuView->addAction(actionBoot_Sector);
        menuView->addAction(actionInodeTable);
        menuView->addAction(actionSuper_Block);
        menuView->addAction(actionGroup_Desctiptor_Table);
        menuView->addAction(actionBlock_Bitmap);
        menuView->addAction(actionInode_Bitmap);
        menuView->addSeparator();
        menuView->addAction(actionData_Block);
        menuData_Recovery->addAction(actionData_Content_Mode);
        menuData_Recovery->addAction(actionMetaData_Mode);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExport_File->setText(QCoreApplication::translate("MainWindow", "Export File", nullptr));
        actionFile_System_Information->setText(QCoreApplication::translate("MainWindow", "File System Information", nullptr));
        actionData_Content_Mode->setText(QCoreApplication::translate("MainWindow", "Data Content Mode", nullptr));
        actionMetaData_Mode->setText(QCoreApplication::translate("MainWindow", "MetaData Mode", nullptr));
        actionBoot_Sector->setText(QCoreApplication::translate("MainWindow", "Boot Sector", nullptr));
        actionSuper_Block->setText(QCoreApplication::translate("MainWindow", "Super Block", nullptr));
        actionGroup_Desctiptor_Table->setText(QCoreApplication::translate("MainWindow", "Group Desctiptor Table", nullptr));
        actionBlock_Bitmap->setText(QCoreApplication::translate("MainWindow", "Block Bitmap", nullptr));
        actionInode_Bitmap->setText(QCoreApplication::translate("MainWindow", "Inode Bitmap", nullptr));
        actionData_Block->setText(QCoreApplication::translate("MainWindow", "Data Block", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionInodeTable->setText(QCoreApplication::translate("MainWindow", "InodeTable", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuData_Recovery->setTitle(QCoreApplication::translate("MainWindow", "Data Recovery", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
