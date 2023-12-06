#include <QCoreApplication>
#include <qcoro5/QCoro/QCoroAsyncGenerator>
#include <qcoro5/QCoro/QCoroGenerator>
#include <qcoro5/QCoro/QCoroNetworkReply>
#include <qcoro5/QCoro/QCoroNetwork>
#include <qcoro5/QCoro/QCoroCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QScopedPointer>
#include <QUrl>
using namespace std::chrono_literals;

QCoro::AsyncGenerator<int32_t> generate_numbers() {
    constexpr auto request = "https://www.random.org/integers/?num=1&min=1&max=100&col=1&base=10&format=plain&rnd=new";
    for(QNetworkAccessManager manager{};;) {
        auto reply = QScopedPointer{ manager.get(QNetworkRequest{ QUrl{ request } }) };
        co_await qCoro(reply.get(), &QNetworkReply::finished);
        co_yield reply->readAll().toInt();
    }
}


int main(int argc, char *argv[]) {
    QCoreApplication app{ argc, argv };
    QTimer::singleShot(100, &app, []() ->QCoro::Task<>{
        auto generator = generate_numbers();
        for(auto iter = co_await generator.begin(); iter != generator.end(); co_await ++iter) {
            qDebug() << "Coro value: " << *iter;
        }
    });
    return app.exec();
}
