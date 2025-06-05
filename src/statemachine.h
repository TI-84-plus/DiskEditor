#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <QStateMachine>
#include <QStackedWidget>
#include <memory>
#include <QVBoxLayout>

class StateMachine : public QObject {

    Q_OBJECT
public:
    StateMachine(QObject *parent = nullptr, QWidget *StackParent = nullptr);

    QStackedWidget *Stack;

    void RemoveState();

   template<typename T>
    T* AddState() {
        T *state = new T(this->Stack);
        int index = this->Stack->addWidget(state);

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
        return state;
    }


    signals:
    void InsertTab();

private:
    QStateMachine *StateManager;
    std::vector<std::unique_ptr<QState>>States;

};

#endif // STATEMACHINE_H
