
#include "launcher_async.h"

//#include <qapplication.h>
#include <gtk/gtk.h>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	AsyncButton *b = new AsyncButton();
	b->show();
	a.exec();

	return EXIT_SUCCESS;
}
