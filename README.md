# supernova-imgui-bindings
Dear imgui extension for supernova engine

## Building
Clone this repository and run the these commands in the project root.
```
mkdir build
cd build
cmake ..
make install
```

## Basic Usage
For basic use cases just initialize the `DebugGUI` class, call the member function `create_new_frame()` and start using ImGUI elements. Finally call the member function `draw` to draw the ui on the window.
```cpp
#include <supernova/debug_gui.h>
...
// Outside the gameloop
DebugGUI gui(window, renderer);
...
// In the gameloop
running = events.process_events(&EVENT_KEYS, nullptr, nullptr, gui.get_event_handler());
gui.create_new_frame();
create_new_frame();
ImGui::Begin("Debug GUI");
ImGui::Text("Hello! Please overwrite the update function to remove this annoying text");
ImGui::End();
...
// While drawing
gui.draw();
```

## Advanced Usage
The above code doesn't give much control over the imgui context. For more complex cases inherit the `DebugGUI` class and overload or create member functions as needed. Like the following example
```cpp
class MyDebugGUI: public DebugGUI {
	public:
		MyDebugGUI(Window &window, Renderer &renderer);

		void update(double fps);
};

MyDebugGUI::MyDebugGUI(Window &window, Renderer &renderer): DebugGUI(window, renderer) {}


void MyDebugGUI::update(double fps) {
	create_new_frame();

    ImGui::Begin("Window");
	ImGui::Text("FPS: %f", fps);
	ImGui::Button("Cool");
	ImGui::End();
}
```

## Examples
Check the official [examples repository](https://github.com/captain1947/supernova-examples) for demos and sample projects.
