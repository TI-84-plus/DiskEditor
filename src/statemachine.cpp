#include "statemachine.h"
#include <QDebug>
#include "HexDumpState.h"

StateMachine::StateMachine(QObject *parent)
    : QObject(parent)
{
    QWidget *widgetParent = qobject_cast<QWidget*>(parent);
    Stack = new QStackedWidget(widgetParent);
    Stack->setContentsMargins(0, 0, 0, 0);
}

