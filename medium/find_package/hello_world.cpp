#include "hello_world.h"

HelloW::HelloW()
{
    l = new QLabel("hello world");
    b = new QPushButton("exit");
    QObject::connect(this->b, SIGNAL(clicked()), this, SLOT(button_click()));

    vbl = new QVBoxLayout();
    vbl->addWidget(l);
    vbl->addWidget(b);

    this->setLayout(vbl);
    this->resize(400,300);
}

void HelloW::button_click()
{
    emit clicked();
}
