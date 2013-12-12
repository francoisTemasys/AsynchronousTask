#include "launcher_async.h"

AsyncButton::AsyncButton()
:QWidget(0)
{
	_button = new QPushButton("Click",this);
	QObject::connect(_button,Q_SIGNAL(clicked()),this,Q_SLOT(DoConnect()));
	_resolver = NULL;

}

AsyncButton::~AsyncButton()
{}

void AsyncButton::DoConnect()
{
	talk_base::SocketAddress server_address;
	server_address.SetIP("localhost");
	_resolver = new talk_base::AsyncResolver();

	_resolver->SignalWorkDone.connect(this, &AsyncButton::OnResolveResult);
	_resolver -> set_address(server_address);
	_resolver -> Start();
	std::cout << "Do Connect"<< std::endl;
}

void AsyncButton::OnResolveResult(talk_base::SignalThread * t)
{
	std::cout << "Start On Resolve Result"<< std::endl;
    if (_resolver -> error() != 0)
    {
        _resolver -> Destroy(false);
        _resolver= NULL;
        std::cout << "Error in async task" << std::endl;

    }
    else
    {
        _resolver->address();
        std::cout << "Resolved async task" << std::endl;
    }
}


