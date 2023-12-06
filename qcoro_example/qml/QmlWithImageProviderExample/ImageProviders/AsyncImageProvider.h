#pragma once
#include <QQuickAsyncImageProvider>
#include <QQuickImageResponse>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class AsyncImage: public QQuickImageResponse {
private:
    QImage m_image{};
public:
    AsyncImage(const QString &id, const QSize &requestedSize);
    QQuickTextureFactory *textureFactory() const;
};

class AsyncImageProvider : public QQuickAsyncImageProvider {
public:
    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize);
};

//file:///home/the_gast/%D0%98%D0%B7%D0%BE%D0%B1%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D1%8F/Screenshot_20230924_145145.png

