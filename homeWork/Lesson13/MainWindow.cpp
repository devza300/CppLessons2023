#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Logic/OperationsVectorString.h"
#include "Logic/NontrivialMathematics.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    mm_timer(this)
{
    ui->setupUi(this);

    // обработка применения паттерна к списку строк
    initializeStringPattern();

    // обработка событий отрисовки
    initializePainter();

    connect(ui->pushButtonMath, &QPushButton::clicked,
            this, &MainWindow::onMathClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeStringPattern()
{
    connect(ui->pushButtonApplyPattern, &QPushButton::clicked,
            this, [this]() {
                // получение вектора строк
                QStringList list = ui->plainTextEditInput->toPlainText().split("\n");
                std::vector<std::string> data;
                std::for_each(list.begin(), list.end(), [&data](auto item){data.push_back(item.toStdString());});

                // получение паттерна
                auto pattern = ui->lineEditPattern->text().toStdString();

                // применение паттерна
                OperationsVectorString op(data);
                std::vector<std::string> result;
                int count = op.findByAngryPattern(pattern, result);

                // отображение результата
                ui->labelCount->setText(QString::number(count));

                // преобразование результата в строку
                QString out;
                std::for_each(result.begin(), result.end(), [&out](auto item){out += QString::fromStdString(item) + "\n";});
                ui->plainTextEditResult->setPlainText(out);
    });
}

void MainWindow::initializePainter()
{
    // рисование линии
    connect(ui->checkBoxLine, &QCheckBox::clicked,
            this, [this](bool checked) {

                // удаление, если выключен
                if (!checked)
                {
                    mm_painter.removePainter(0);
                    return;
                }

                std::function<void ()> paint = [this]() {
                    auto value = ui->lcdNumberLine->intValue();
                    value++;
                    ui->lcdNumberLine->display(value);
                };
                mm_painter.appendPainter(0, paint);
            });

    // рисование прямоугольника
    connect(ui->checkBoxRect, &QCheckBox::clicked,
            this, [this](bool checked) {

                // удаление, если выключен
                if (!checked)
                {
                    mm_painter.removePainter(1);
                    return;
                }

                std::function<void ()> paint = [this]() {
                    auto value = ui->lcdNumberRectangle->intValue();
                    value++;
                    ui->lcdNumberRectangle->display(value);
                };
                mm_painter.appendPainter(1, paint);
            });

    // рисование кругов
    connect(ui->checkBoxCircle, &QCheckBox::clicked,
            this, [this](bool checked) {

                // удаление, если выключен
                if (!checked)
                {
                    mm_painter.removePainter(2);
                    return;
                }

                std::function<void ()> paint = [this]() {
                    auto value = ui->lcdNumberCircle->intValue();
                    value++;
                    ui->lcdNumberCircle->display(value);
                };
                mm_painter.appendPainter(2, paint);
            });

    // интервал рисования - секунда
    mm_timer.setInterval(1000);
    connect(&mm_timer, &QTimer::timeout,
            this, [this]() {
                mm_painter.draw();
            });
    mm_timer.start();
}

void MainWindow::onMathClicked()
{
    NontrivialMathematics *math = new NontrivialMathematics();

    try
    {
        // выполнение вычислений
        QString result = math->evaluate(ui->textEditMathInput->toPlainText());
        ui->textEditMathResult->setPlainText(result);
    }
    catch (NontrivialMathematics::runtime_error &ex)
    {
        ui->textEditMathResult->setPlainText(ex.what());
    }
    catch (NontrivialMathematics::logic_error &ex)
    {
        ui->textEditMathResult->setPlainText(ex.what());
    }
    catch (...)
    {
        ui->textEditMathResult->setPlainText("catch unknown error");
    }

    delete math;
}

