#ifndef SUPERGUI_H
#define SUPERGUI_H


#include <functional>

#include <supernova/core.h>

#include <imgui/imgui.h>



// Classes
class DebugGUI {
	private:
		void set_style();
		void initialize_imgui();
		void setup_io();
		void initialize_backends(Window &window, Renderer &renderer);
		void destroy();

	public:
		ImGuiIO *io;

		DebugGUI(Window &window, Renderer &renderer);
		~DebugGUI();

		bool process_events(SDL_Event &event);
		std::function<bool(SDL_Event &)> get_event_handler();
		void create_new_frame();
		virtual void update();
		void draw();
};

#endif /* SUPERGUI_H */
