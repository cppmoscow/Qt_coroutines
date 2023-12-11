#pragma once
#include <qcoro5/QCoro/QCoroImageProvider>
#include <qcoro5/QCoro/QCoroTimer>
#include <qcoro5/QCoro/QCoroCore>

class CoroImageProvider: public QCoro::ImageProvider {
public:
    virtual QCoro::Task<QImage> asyncRequestImage(const QString &id, const QSize &requestedSize) override;
};

