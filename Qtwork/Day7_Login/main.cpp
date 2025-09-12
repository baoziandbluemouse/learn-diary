#include "login.h"
#include "register.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Login> s = std::make_shared<Login>();
    s->initSignals();
    Register w;
    s->show();
    return a.exec();
}
