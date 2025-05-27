#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <QStateMachine>
#include <QStackedWidget>
#include <memory>
#include <QVBoxLayout>

class StateMachine : public QObject {

    Q_OBJECT
public:
    StateMachine();

    QStackedWidget *Stack;

    void RemoveState();
    void AddState(QWidget *State);

    signals:
    void InsertTab();

private:
    QStateMachine *StateManager;
    std::vector<std::unique_ptr<QState>> States;

};

#endif // STATEMACHINE_H
