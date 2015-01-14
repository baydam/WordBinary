#include <QtWidgets>
#include "MainWindow.h"

MainWindow::MainWindow()
{
    createLayout();
}

void MainWindow::createLayout()
{
    centralWidget = new QWidget;
    this->setCentralWidget(centralWidget);

    // Input TextEdit
    inputTextEdit = new QTextEdit;
    inputTextEdit->setOverwriteMode(true);
    inputTextEdit->setUndoRedoEnabled(true);
    inputTextEdit->setWordWrapMode(QTextOption::WordWrap);
    inputTextEdit->setPlaceholderText(tr("Ecrire le texte à transcoder!"));

    // Output displaying the result
    outputBinaryCode = new QTextEdit;
    outputBinaryCode->setReadOnly(true);

    // Button de validation
    validationButton = new QPushButton(tr("Valider"));
    clearButton = new QPushButton(tr("Effacer"));

    // Case a cocher pour l'option espace
    enableSpace = new QCheckBox(tr("Activer les e&spaces"));

    QSplitter *mainSplitter = new QSplitter(Qt::Vertical, centralWidget);
    mainSplitter->setMinimumHeight(120);
    mainSplitter->addWidget(inputTextEdit);
    mainSplitter->addWidget(outputBinaryCode);

    // Layout des button
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(enableSpace);
    buttonLayout->addStretch();
    buttonLayout->addWidget(validationButton);
    buttonLayout->addWidget(clearButton);


    // Principale layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainSplitter);
    mainLayout->addLayout(buttonLayout);
    centralWidget->setLayout(mainLayout);

    // Connexion Signals & Slots
    connect(validationButton, SIGNAL(clicked()), this, SLOT(convertFromAscii()));
    connect(inputTextEdit, SIGNAL(textChanged()), this, SLOT(convertFromAscii()));
    connect(enableSpace, SIGNAL(clicked()), this, SLOT(convertFromAscii()));
    connect(clearButton, SIGNAL(clicked()), inputTextEdit, SLOT(clear()));
    connect(clearButton, SIGNAL(clicked()), outputBinaryCode, SLOT(clear()));
}

void MainWindow::createMenu()
{
    // Later!
}

QString MainWindow::decimalToBinary(int asciiCode) const
{
    QString binnum = "00000000" + static_cast<QString>(QString::number(asciiCode, 2));

    binnum = binnum.right(binnum.length() - 7);
    return binnum;
}

void MainWindow::convertFromAscii()
{
    QString inputText = inputTextEdit->toPlainText();
    QChar charAt;
    QString outputText = "";

    for (int i = 0; i < inputText.size(); ++i) {
        charAt = inputText.at(i);

        outputText.append(decimalToBinary(charAt.unicode()));

        if (enableSpace->isChecked())
            outputText.append(" ");
    }
    outputBinaryCode->setPlainText(outputText);
}
