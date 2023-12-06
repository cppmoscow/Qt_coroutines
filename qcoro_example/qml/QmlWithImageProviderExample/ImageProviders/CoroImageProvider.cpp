#include "CoroImageProvider.h"
using namespace std::chrono_literals;

QCoro::Task<QImage> CoroImageProvider::asyncRequestImage(const QString &id, const QSize &requestedSize) {
    const auto color = QColor(id).rgba();

    co_await QCoro::sleepFor(5s);
    auto image = QImage{ 100, 50, QImage::Format_RGB32 };
    image.fill(color);
    co_return image;
}
