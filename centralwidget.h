#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

class CentralWidget : public QWidget
{

    Q_OBJECT

public:

    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget() override;


public slots:

    void loadImage(const QString &path);


protected:

    // QWidget interface
    void paintEvent(QPaintEvent * event) override;
    void resizeEvent(QResizeEvent * event) override;

    void updateDrawRect();


private:

    QImage * image_ = nullptr;

    QRect drawRect_;

};

#endif // CENTRALWIDGET_H
