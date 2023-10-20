#include <supernova/engine.h>
#include <supernova/constants.h>

#include "../src/super_gui.h"


using namespace std;



int main(int argc, char* argv[]) {

	Engine engine;

	Window window("Debug GUI", 800, 600);
	Renderer renderer(window);

	Clock clock;
	Events events;

	DebugGUI gui(window, renderer);

	bool running = true;
	double dt;

	while (running) {
		dt = clock.tick(60);

		running = events.process_events(&EVENT_KEYS, nullptr, nullptr, gui.get_event_handler());

		gui.update();

		renderer.clear(WHITE);
		gui.draw();
		renderer.present();
	}

	return 0;
}
