#include <QApplication>
#include "hello_world.h"
 
int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	HelloW hw;
	QObject::connect(&hw, SIGNAL(clicked()), &app, SLOT(quit()));
	hw.show();

	return app.exec();
}

