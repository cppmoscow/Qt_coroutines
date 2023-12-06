#pragma once
#include <QObject>

class CustomObject: public QObject {
    Q_OBJECT
public:
    explicit CustomObject(QObject *parent = nullptr);
signals:
    void completed_zero();
    void completed_one(int32_t);
    void completed_two(int32_t, bool);
    void completed_three(int32_t, bool, char);
protected:
    void timerEvent(QTimerEvent *event);
};

