#pragma once
#include"core.h"
#include"Events/Event.h"
namespace nuts {
	class  NUTS_API  Application
	{
	public:

		Application();
		virtual ~Application();
		void Run();

	};

	Application* CreateApplication();
}