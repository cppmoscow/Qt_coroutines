#include "HttpCoroImageProvider.h"
using namespace std::chrono_literals;


QCoro::Task<QImage> HttpCoroImageProvider::asyncRequestImage(const QString &id, const QSize &requestedSize) {
    auto manager = QNetworkAccessManager{};
    const auto reply = QScopedPointer{
        co_await manager.get(QNetworkRequest{ QUrl{
            QString{ "http://178.208.86.244:8000/images/%1.png" }.arg(id) } })
    };
    co_return QImage::fromData(reply->readAll());
}
