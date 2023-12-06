#include "StandardImageProvider.h"

StandardImageProvider::StandardImageProvider()
    :QQuickImageProvider(QQuickImageProvider::Pixmap){}

QPixmap StandardImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
    const auto result_size = QSize{
        requestedSize.width() > 0 ? requestedSize.width() : 100,
        requestedSize.height() > 0 ? requestedSize.height() : 50
    };
    if (size) { *size = result_size; }
    QPixmap pixmap{ result_size };
    pixmap.fill(QColor(id).rgba());
    return pixmap;
}
