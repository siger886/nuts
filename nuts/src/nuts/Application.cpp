#include"ntpch.h"

#include "Application.h"

#include"nuts/Events/ApplicationEvent.h"
#include"nuts/Log.h"
namespace nuts {
	Application::Application()
	{

	}
	Application::~Application()
	{

	}
	void Application::Run()
	{	
		WindowResizeEvent  e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			NT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			NT_TRACE(e);
		}
		while (true);
	}
}