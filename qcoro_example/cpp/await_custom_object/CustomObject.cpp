#include "CustomObject.h"

CustomObject::CustomObject(QObject *parent)
    :QObject{ parent } { this->startTimer(std::chrono::seconds{ 5 }); }

void CustomObject::timerEvent(QTimerEvent *event) {
    QObject::timerEvent(event);
    emit this->completed_zero();
    emit this->completed_one(42);
    emit this->completed_two(42, true);
    emit this->completed_three(42, true, '@');
}
