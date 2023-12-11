#include <QCoreApplication>
#include <qcoro5/QCoro/QCoroNetwork>
#include <qcoro5/QCoro/QCoroCore>
#include "CustomObject.h"

QCoro::Task<> awaitCustomObject() {
    CustomObject object{};
    qDebug() << "Step 0";
    const auto r0 = co_await qCoro(&object, &CustomObject::completed_zero);
    qDebug() << "Step 1";
    const auto r1 = co_await qCoro(&object, &CustomObject::completed_one);
    qDebug() << "Step 2: " << r1;
    const auto [r2_1, r2_2] = co_await qCoro(&object, &CustomObject::completed_two);
    qDebug() << "Step 3: " << QString{ "[%1:%2]" }.arg(r2_1).arg(r2_2);
    const auto [r3_1, r3_2, r3_3] = co_await qCoro(&object, &CustomObject::completed_three);
    qDebug() << "Step 4: " << QString{ "[%1:%2:%3]" }.arg(r3_1).arg(r3_2).arg(r3_3);
}

/*
QCoro::Task<> awaitCustomObject() {
    CustomObject object{};
    qDebug() << "Step 0";
    const auto r0 = co_await qCoro(&object, &CustomObject::completed_zero);
    qDebug() << "Step 1";
    const auto r1 = co_await qCoro(&object, &CustomObject::completed_one);
    qDebug() << "Step 2: " << r1;
    const auto r2 = co_await qCoro(&object, &CustomObject::completed_two);
    qDebug() << "Step 3: " << QString{ "[%1:%2]" }.arg(std::get<0>(r2)).arg(std::get<1>(r2));
    const auto r3 = co_await qCoro(&object, &CustomObject::completed_three);
    qDebug() << "Step 3: " << QString{ "[%1:%2]" }.arg(std::get<0>(r3)).arg(std::get<1>(r3)).arg(std::get<2>(r3));
}
*/


int main(int argc, char *argv[]) {
    QCoreApplication app{ argc, argv };
    awaitCustomObject().then([]{ qDebug() << "Ready"; });
    return app.exec();
}
