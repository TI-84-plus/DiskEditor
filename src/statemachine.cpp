#include "statemachine.h"
#include <QDebug>
#include "HexView.h"

StateMachine::StateMachine(QObject *parent, QWidget *StackParent)
    : QObject(parent)
{
    StateManager = new QStateMachine(this);
    Stack = new QStackedWidget(StackParent);
    Stack->setContentsMargins(0, 0, 0, 0);
}

void StateMachine::RemoveState() {
    this->StateManager->removeState(States.back().get());

}


