#include "statemachine.h"
#include <QDebug>

StateMachine::StateMachine() {
    StateManager = new QStateMachine();
    Stack = new QStackedWidget();
    Stack->setContentsMargins(0, 0, 0, 0);
}

void StateMachine::AddState(QWidget *State) {

    int index = this->Stack->addWidget(State);

    States.push_back(std::make_unique<QState>());
    QState *CurrentState = States.back().get();
    CurrentState->assignProperty(this->Stack, "currentIndex", index);
    this->StateManager->addState(CurrentState);

    this->Stack->setCurrentIndex(index);
    // Only set initial state and start once
    if (!this->StateManager->isRunning() && States.size() == 1) {
        this->StateManager->setInitialState(States.front().get());
        this->StateManager->start();
    }

    emit InsertTab();
}

void StateMachine::RemoveState() {
    this->StateManager->removeState(States.back().get());

}


