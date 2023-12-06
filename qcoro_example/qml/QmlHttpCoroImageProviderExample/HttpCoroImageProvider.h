#pragma once
#include <qcoro5/QCoro/QCoroImageProvider>
#include <qcoro5/QCoro/QCoroTimer>
#include <qcoro5/QCoro/QCoroCore>
#include <qcoro5/QCoro/QCoroNetworkReply>
#include <qcoro5/QCoro/QCoroNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


class HttpCoroImageProvider: public QCoro::ImageProvider {
public:
    virtual QCoro::Task<QImage> asyncRequestImage(const QString &id, const QSize &requestedSize) override;
};
