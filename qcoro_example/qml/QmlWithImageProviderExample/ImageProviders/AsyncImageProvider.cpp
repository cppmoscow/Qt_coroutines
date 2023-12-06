#include "AsyncImageProvider.h"
#include <QQuickTextureFactory>
#include <QTimer>

QQuickImageResponse *AsyncImageProvider::requestImageResponse(const QString &id, const QSize &requestedSize) {
    return new AsyncImage{ id, requestedSize };
}

AsyncImage::AsyncImage(const QString &id, const QSize &requestedSize) {
        QTimer::singleShot(2500, this, &AsyncImage::finished);
        m_image = QImage{ QSize{ 100, 50 }, QImage::Format_RGB32 };
        m_image.fill(QColor(id).rgba());
    }

QQuickTextureFactory *AsyncImage::textureFactory() const {
    return QQuickTextureFactory::textureFactoryForImage(m_image);
}
