#include "RandomNumberUploader.h"
#include <qcoro5/QCoro/QCoroNetworkReply>
#include <qcoro5/QCoro/QCoroNetwork>


RandomNumberUploader::RandomNumberUploader(QObject* parent)
    :QObject{ parent } {}

QCoro::QmlTask RandomNumberUploader::generate() const {
    return generate_number();
}

QCoro::Task<int32_t> RandomNumberUploader::generate_number() const {
    constexpr auto request = "https://www.random.org/integers/?num=1&min=1&max=100&col=1&base=10&format=plain&rnd=new";
    qDebug() << "Request for upload value";
    QNetworkAccessManager manager{};
    auto reply = QScopedPointer{ co_await manager.get(QNetworkRequest{ QUrl{ request } }) };
    const auto value = reply->readAll().toInt();
    qDebug() << "Uploaded value: " << value;
    co_return value;
}
