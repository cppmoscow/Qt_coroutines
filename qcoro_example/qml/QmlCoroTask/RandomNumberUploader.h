#pragma once
#include <qcoro5/QCoro/QCoroQmlTask>
#include <qcoro5/QCoro/QCoroQml>



class RandomNumberUploader: public QObject {
private:
    Q_OBJECT
public:
    RandomNumberUploader(QObject* parent = nullptr);
    Q_INVOKABLE QCoro::QmlTask generate() const;
private:
    QCoro::Task<int32_t> generate_number() const;
};

