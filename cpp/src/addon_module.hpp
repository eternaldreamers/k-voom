#ifndef ADDON_MODULE_HPP
#define ADDON_MODULE_HPP

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {
    class AddonModule : public Sprite2D {
        GDCLASS(AddonModule, Sprite2D);

        private:
            double _time_passed;

        protected:
            static void _bind_methods();

        public:
            AddonModule();
            ~AddonModule();

            void _process(double delta) override;
    };
}

#endif