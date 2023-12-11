#include <QCoreApplication>
#include <qcoro5/QCoro/QCoroCore>
#include <QTimer>
using namespace std::chrono_literals;

QCoro::Task<> processFor() {
    QTimer timer{};
    timer.start(1000);
    for(auto index = 0; index < 10; ++index, co_await timer) {
        qDebug() << "He-he: " << index;
    }
}

QCoro::Task<> processForWithSleep() {
    for(auto index = 0; index < 10; ++index, co_await QCoro::sleepFor(1s)) {
        qDebug() << "He-he: " << index;
    }
}

QCoro::Task<> processTask() {
    auto task = processForWithSleep();
    qDebug() << "Before await";
    co_await task;
    qDebug() << "After await";
    qApp->exit();
}

int main(int argc, char *argv[]) {
    QCoreApplication app{ argc, argv };
    processTask();
    return app.exec();
}
