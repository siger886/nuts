#pragma once
#include"core.h"
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