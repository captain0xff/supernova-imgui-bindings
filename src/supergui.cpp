#include "supergui.h"

#include <imgui/imgui_impl_sdl3.h>
#include <imgui/imgui_impl_sdlrenderer3.h>



// Classes
DebugGUI::DebugGUI(Window &_window, Renderer &_renderer): renderer(_renderer) {
	initialize_imgui();
	setup_io();
	set_style();
	initialize_backends(_window, _renderer);
}

DebugGUI::~DebugGUI() {
	destroy();
}

bool DebugGUI::process_events(SDL_Event &event) {
	ImGui_ImplSDL3_ProcessEvent(&event);

	return false;
}

std::function<bool(SDL_Event &)> DebugGUI::get_event_handler() {
	return [this](SDL_Event &event) {
		return process_events(event);
	};
}

void DebugGUI::create_new_frame() {
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();
}

void DebugGUI::update() {
	create_new_frame();

	ImGui::Begin("Debug GUI");
	ImGui::Text("Hello! Please overwrite the update function to remove this annoying text");
	ImGui::End();
}

void DebugGUI::draw() {
	ImGui::Render();
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer.renderer.get());
}

void DebugGUI::set_style() {
	ImGui::StyleColorsDark();
}

void DebugGUI::initialize_imgui() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
}

void DebugGUI::setup_io() {
	io = &ImGui::GetIO();
}

void DebugGUI::initialize_backends(Window &window, Renderer &renderer) {
	ImGui_ImplSDL3_InitForSDLRenderer(window.window.get(), renderer.renderer.get());
	ImGui_ImplSDLRenderer3_Init(renderer.renderer.get());
}

void DebugGUI::destroy() {
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
}
