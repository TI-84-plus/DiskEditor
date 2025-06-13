#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <QStateMachine>
#include <QStackedWidget>
#include <memory>
#include <QVBoxLayout>
#include <iostream>
#include <stack>

class StateMachine : public QObject {

    Q_OBJECT
public:
    StateMachine(QObject *parent = nullptr);

    QStackedWidget *Stack;
    std::stack<int> StateIndices;


    template<typename T>
    T* PushState() {
        T* widget = new T(this->Stack);
        int index = this->Stack->addWidget(widget);
        this->StateIndices.push(index); // Stack to track history
        this->Stack->setCurrentIndex(index);

        emit InsertTab(); // Optional
        return widget;
    }




    signals:
    void InsertTab();

private:

};

#endif // STATEMACHINE_H
