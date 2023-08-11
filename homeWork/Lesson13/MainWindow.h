#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "Logic/RandomPainter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class - форма для демонстрации реализации задания
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /*!
     * \brief initializeStringPattern - инициализация определения количества строк
     */
    void initializeStringPattern();

    /*!
     * \brief initializePainter - инициализация рисовальщика
     */
    void initializePainter();

private slots:
    /*!
     * \brief onMathClicked - выполнение математических операций с обработкой исключений
     */
    void onMathClicked();

private:
    Ui::MainWindow *ui;

    QTimer mm_timer;            //!< таймер рисования
    RandomPainter mm_painter;   //!< класс рисования


};
#endif // MAINWINDOW_H
