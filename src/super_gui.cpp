#include "super_gui.h"

#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>



// Classes
DebugGUI::DebugGUI(Window &window, Renderer &renderer) {
	initialize_imgui();
	setup_io();
	set_style();
	initialize_backends(window, renderer);
}

DebugGUI::~DebugGUI() {
	destroy();
}

bool DebugGUI::process_events(SDL_Event &event) {
	ImGui_ImplSDL2_ProcessEvent(&event);

	return false;
}

std::function<bool(SDL_Event &)> DebugGUI::get_event_handler() {
	return [this](SDL_Event &event) {
		return process_events(event);
	};
}

void DebugGUI::create_new_frame() {
	ImGui_ImplSDLRenderer2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
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
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
}

void DebugGUI::set_style() {
	ImGui::StyleColorsDark();
}

void DebugGUI::initialize_imgui() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
}

void DebugGUI::setup_io() {
	io = ImGui::GetIO();
}

void DebugGUI::initialize_backends(Window &window, Renderer &renderer) {
	ImGui_ImplSDL2_InitForSDLRenderer(window.window.get(), renderer.renderer.get());
	ImGui_ImplSDLRenderer2_Init(renderer.renderer.get());
}

void DebugGUI::destroy() {
	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}
