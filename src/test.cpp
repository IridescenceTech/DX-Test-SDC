#include <Audio/Clip.hpp>
#include <Graphics/2D/Sprite.hpp>
#include <Stardust-Celeste.hpp>
#include <Utilities/Controllers/VitaController.hpp>
#include <Utilities/Input.hpp>

using namespace Stardust_Celeste;
using namespace Stardust_Celeste::Utilities::Input;

class GameState : public Core::ApplicationState {

  public:
    GameState() {}

    Rendering::Color color;
    double timer;
    int fps = 0;

    void on_update(Core::Application *app, double dt) {
        Utilities::Input::update();

        timer += dt;
        if(timer > 1.0f) {
            timer = 0.0f;
            SC_APP_INFO("FPS {}", fps);
            fps = 0;
        }

        fps++;
    }
    void on_draw(Core::Application *app, double dt) {
        /*
        if (sprite.get() != nullptr)
            sprite->draw();
            */
        color.rgba.r = 120;
        color.rgba.g = 200;
        color.rgba.b = 255;
        color.rgba.a = 255;

        Rendering::RenderContext::get().set_color(color);
        Rendering::RenderContext::get().vsync = false;
    }
    void on_start() {
        /*
        Rendering::RenderContext::get().matrix_ortho(-1, 1, -1, 1, -1, 1);
        Rendering::RenderContext::get().set_mode_2D();

        tex_id = Rendering::TextureManager::get().load_texture(
            "./container.jpg", SC_TEX_FILTER_NEAREST, SC_TEX_FILTER_NEAREST,
            true);

        auto tex = Rendering::TextureManager::get().get_texture(tex_id);
        sprite = create_scopeptr<Graphics::G2D::Sprite>(
            tex_id, Rendering::Rectangle{{-1, -1}, {2, 2}});
            */
        timer = 0.0f;
    }

    void on_cleanup() {}

  private:
    bool added;
    ScopePtr<Graphics::G2D::Sprite> sprite;
    u32 tex_id;
};

class GameApplication : public Core::Application {
  public:
    void on_start() override {
        state = create_refptr<GameState>();
        Application::get().push_state(state);
    }

  private:
    RefPtr<GameState> state;
};

Core::Application *CreateNewSCApp() {
    Core::AppConfig config;
    config.headless = false;
    config.render_settings.renderingApi = DX11;

    Core::PlatformLayer::get().initialize(config);

    return new GameApplication();
}