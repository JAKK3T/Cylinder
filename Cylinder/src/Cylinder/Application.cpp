#include "Application.h"

#include "Cylinder/Events/ApplicationEvent.h"
#include "Cylinder/Log.h"

namespace Cylinder {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}


	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CYL_TRACE(e);
		while (true);
	}


}