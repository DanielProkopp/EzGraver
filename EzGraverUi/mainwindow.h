#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <memory>
#include <functional>

#include "ezgraver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    Q_PROPERTY(bool connected READ connected NOTIFY connectedChanged)

public:
    explicit MainWindow(QWidget* parent = NULL);
    ~MainWindow();

    bool connected() const;
signals:
    void connectedChanged(bool connected);

private slots:
    void on_connect_clicked();
    void on_home_clicked();
    void on_up_clicked();
    void on_left_clicked();
    void on_center_clicked();
    void on_right_clicked();
    void on_down_clicked();
    void on_upload_clicked();
    void on_preview_clicked();
    void on_start_clicked();
    void on_pause_clicked();
    void on_reset_clicked();
    void on_disconnect_clicked();
    void on_image_clicked();

    void updatePorts();
    void bytesWritten(qint64 bytes);
    void updateProgress(qint64 bytes);

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

private:
    Ui::MainWindow* _ui;
    QTimer _portTimer;
    QTimer _statusTimer;
    QImage _image;

    std::shared_ptr<EzGraver> _ezGraver;
    std::function<void(qint64)> _bytesWrittenProcessor;
    bool _connected;

    void initBindings();
    void initConversionFlags();

    void setConnected(bool connected);
    void printVerbose(QString const& verbose);
    void loadImage(QString const& fileName);
};

#endif // MAINWINDOW_H
