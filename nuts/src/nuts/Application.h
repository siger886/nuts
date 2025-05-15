#pragma once
#include"core.h"
#include"Events/Event.h"
#include"Window.h"
namespace nuts {
	class  NUTS_API  Application
	{
	public:

		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	Application* CreateApplication();
}