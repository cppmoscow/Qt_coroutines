#include <QCoreApplication>
#include <qcoro5/QCoro/QCoroNetwork>
#include <qcoro5/QCoro/QCoroCore>

void complex_request() {
    auto manager = new QNetworkAccessManager{};
    auto reply_1 = manager->get(QNetworkRequest{ QUrl{ "..." } });
    QObject::connect(reply_1, &QNetworkReply::finished,
    [reply_1, manager] {
        const auto result_1 = reply_1->readAll();
        /* ... */
        auto reply_2 = manager->get(QNetworkRequest{ QUrl{ "..." } });
        QObject::connect(reply_1, &QNetworkReply::finished,
        [reply_1, reply_2, manager] {
            const auto result_1 = reply_2->readAll();
            /* ... */
            reply_1->deleteLater();
            reply_2->deleteLater();
            manager->deleteLater();
        });
    });
}
QCoro::Task<> complex_coro_request() {
    QNetworkAccessManager manager{};
    auto reply_1 = QScopedPointer{ co_await manager.get(QNetworkRequest{ QUrl{ "..." } }) };
    const auto result_1 = reply_1->readAll();
    /* ... */
    auto reply_2 = QScopedPointer{ co_await manager.get(QNetworkRequest{ QUrl{ "..." } }) };
    const auto result_2 = reply_2->readAll();
    /* ... */
}

QCoro::Task<int32_t> generate_number() {
    constexpr auto request = "https://www.random.org/integers/?num=1&min=1&max=100&col=1&base=10&format=plain&rnd=new";
    QNetworkAccessManager manager{};
    auto reply = QScopedPointer{ co_await manager.get(QNetworkRequest{ QUrl{ request } }) };
    co_return reply->readAll().toInt();
}

int main(int argc, char *argv[]) {
    QCoreApplication app{ argc, argv };
    generate_number().then([](int32_t number) { qDebug() << number; });
    return app.exec();
}

