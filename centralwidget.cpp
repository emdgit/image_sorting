#include "centralwidget.h"

#include <QPainter>

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    updateDrawRect();
}

CentralWidget::~CentralWidget()
{
    if (image_) {
        delete image_;
    }
}

void CentralWidget::loadImage(const QString & path)
{
    QImage * img = new QImage(path);

    if (image_) {
        delete image_;
    }

    image_ = img;
    updateDrawRect();
    repaint();
}

void CentralWidget::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event)

    if (!image_) {
        return;
    }

    QPainter painter(this);
    painter.drawImage(drawRect_, *image_);
}

void CentralWidget::resizeEvent(QResizeEvent * event)
{
    Q_UNUSED(event)

    updateDrawRect();
}

void CentralWidget::updateDrawRect()
{
    if (!image_) {
        drawRect_ = this->rect();
        return;
    }

    auto iw = image_->width();
    auto ih = image_->height();
    auto rect = this->rect();

    if (!rect.width() || !rect.height()) {
        return;
    }

    auto k = std::max(static_cast<double>(iw) / rect.width(),
                      static_cast<double>(ih) / rect.height());

    if (k < 1) {
        k = 1;
    }

    rect.setX( width() / 2 - iw / k / 2 );
    rect.setY( height() / 2 - ih / k / 2 );
    rect.setWidth(iw / k);
    rect.setHeight(ih / k);

    drawRect_ = rect;
}
