#include <QCoreApplication>
#include <qcoro5/QCoro/QCoroGenerator>
#include <qcoro5/QCoro/QCoroCore>

QCoro::Generator<double> values() {
    for(auto index = 0; index < 100; ++index) {
        qDebug() << "Return coro value: " << index;
        co_yield index;
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication app{ argc, argv };
    QTimer::singleShot(100, []() ->QCoro::Task<> {
        for(auto value: values())
            qDebug() << "Use coro value: " << value;

        co_return;
    });
    return app.exec();
}
