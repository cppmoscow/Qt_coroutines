#pragma once
#include <QQuickImageProvider>

class StandardImageProvider: public QQuickImageProvider {
public:
    StandardImageProvider();
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
};



