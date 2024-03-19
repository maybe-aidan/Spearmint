#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"

namespace Spearmint {
	class SPEARMINT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

#endif
