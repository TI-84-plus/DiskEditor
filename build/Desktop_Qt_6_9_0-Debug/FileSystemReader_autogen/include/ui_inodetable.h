/********************************************************************************
** Form generated from reading UI file 'inodetable.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INODETABLE_H
#define UI_INODETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InodeTable
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QComboBox *comboBox;
    QTreeWidget *treeWidget_4;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_3;
    QTableWidget *tableWidget_3;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_8;

    void setupUi(QWidget *InodeTable)
    {
        if (InodeTable->objectName().isEmpty())
            InodeTable->setObjectName("InodeTable");
        InodeTable->resize(1305, 586);
        gridLayout = new QGridLayout(InodeTable);
        gridLayout->setObjectName("gridLayout");
        splitter_3 = new QSplitter(InodeTable);
        splitter_3->setObjectName("splitter_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy);
        splitter_3->setOrientation(Qt::Orientation::Horizontal);
        splitter_3->setHandleWidth(0);
        widget = new QWidget(splitter_3);
        widget->setObjectName("widget");
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(comboBox);

        treeWidget_4 = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget_4->setHeaderItem(__qtreewidgetitem);
        treeWidget_4->setObjectName("treeWidget_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget_4->sizePolicy().hasHeightForWidth());
        treeWidget_4->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(treeWidget_4);

        splitter_3->addWidget(widget);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName("splitter_2");
        sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy);
        splitter_2->setOrientation(Qt::Orientation::Horizontal);
        splitter_2->setHandleWidth(0);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName("splitter");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(3);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy3);
        splitter->setLineWidth(1);
        splitter->setOrientation(Qt::Orientation::Vertical);
        splitter->setHandleWidth(0);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setClearButtonEnabled(true);

        verticalLayout_3->addWidget(lineEdit_3);

        tableWidget_3 = new QTableWidget(verticalLayoutWidget);
        if (tableWidget_3->columnCount() < 5)
            tableWidget_3->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_3->setObjectName("tableWidget_3");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(8);
        sizePolicy4.setHeightForWidth(tableWidget_3->sizePolicy().hasHeightForWidth());
        tableWidget_3->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(tableWidget_3);

        verticalLayout_3->setStretch(0, 8);
        verticalLayout_3->setStretch(1, 8);
        splitter->addWidget(verticalLayoutWidget);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName("tabWidget");
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tabWidget->addTab(tab_8, QString());
        splitter->addWidget(tabWidget);
        splitter_2->addWidget(splitter);
        splitter_3->addWidget(splitter_2);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);


        retranslateUi(InodeTable);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InodeTable);
    } // setupUi

    void retranslateUi(QWidget *InodeTable)
    {
        InodeTable->setWindowTitle(QCoreApplication::translate("InodeTable", "Form", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("InodeTable", "Search Inode No...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("InodeTable", "Inode No", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("InodeTable", "Mod. Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("InodeTable", "Access Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("InodeTable", "Created Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("InodeTable", "Size", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("InodeTable", "Result View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("InodeTable", "Hex View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("InodeTable", "Media View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("InodeTable", "String View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InodeTable: public Ui_InodeTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INODETABLE_H
