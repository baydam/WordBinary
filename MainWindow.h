#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTextEdit;
class QPushButton;
class QCheckBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    void createLayout();
    void createMenu();
    QString decimalToBinary(int asciiCode) const;

signals:

public slots:
    void convertFromAscii();

private:
    QWidget* centralWidget;
    QTextEdit *inputTextEdit;
    QPushButton *validationButton;
    QPushButton *clearButton;
    QTextEdit *outputBinaryCode;
    QCheckBox *enableSpace;
};

#endif // MAINWINDOW_H
 
