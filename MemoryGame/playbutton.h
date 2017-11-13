#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include <QWidget>
#include <QPushButton>

class Playbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Playbutton(QWidget *parent = nullptr);
    static int ID_count;
    int getID();
    void addID();

signals:

public slots:

private:
    int ID_btn = 0;
};

#endif // PLAYBUTTON_H
