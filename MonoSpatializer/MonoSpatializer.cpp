
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include <lv2/core/lv2.h>
///////////////////////// MACRO SUPPORT ////////////////////////////////

#define PLUGIN_URI "urn:bill:MonoSpatializer"

using std::min;
using std::max;

#define __rt_data __attribute__((section(".rt.data")))
#include "MonoSpatializer.cc"

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace monospatializer {

class Xmonospatializer
{
private:
    float* input0;
    float* output0;
    float* output1;
    monospatializer::Dsp* plugin;

    // private functions
    inline void run_dsp_(uint32_t n_samples);
    inline void connect_(uint32_t port,void* data);
    inline void init_dsp_(uint32_t rate);
    inline void connect_all__ports(uint32_t port, void* data);
    inline void activate_f();
    inline void clean_up();
    inline void deactivate_f();
public:
    // LV2 Descriptor
    static const LV2_Descriptor descriptor;
    // static wrapper to private functions
    static void deactivate(LV2_Handle instance);
    static void cleanup(LV2_Handle instance);
    static void run(LV2_Handle instance, uint32_t n_samples);
    static void activate(LV2_Handle instance);
    static void connect_port(LV2_Handle instance, uint32_t port, void* data);
    static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
    Xmonospatializer();
    ~Xmonospatializer();
};

// constructor
Xmonospatializer::Xmonospatializer() :

    input0(NULL),
    output0(NULL),
    output1(NULL),
    plugin(monospatializer::plugin()) {};

// destructor
Xmonospatializer::~Xmonospatializer() {
    plugin->del_instance(plugin);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Xmonospatializer::init_dsp_(uint32_t rate)
{
    plugin->init(rate);
}

// connect the Ports used by the plug-in class
void Xmonospatializer::connect_(uint32_t port,void* data)
{
    switch ((PortIndex)port)
    {
        case 0:
            input0 = static_cast<float*>(data);
            break;
        case 1:
            output0 = static_cast<float*>(data);
            break;
        case 2:
            output1 = static_cast<float*>(data);
            break;
        default:
            break;
    }
}

void Xmonospatializer::activate_f()
{
    // allocate the internal DSP mem
}

void Xmonospatializer::clean_up()
{
    // delete the internal DSP mem
}

void Xmonospatializer::deactivate_f()
{
    // delete the internal DSP mem
}

void Xmonospatializer::run_dsp_(uint32_t n_samples)
{
    if(n_samples<1) return;

    plugin->compute(n_samples, input0, output0, output1);
}

void Xmonospatializer::connect_all__ports(uint32_t port, void* data)
{
    // connect the Ports used by the plug-in class
    connect_(port,data); 
    plugin->connect(port,data);}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Xmonospatializer::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
    // init the plug-in class
    Xmonospatializer *self = new Xmonospatializer();
    if (!self) {
        return NULL;
    }
    self->init_dsp_((uint32_t)rate);
    return (LV2_Handle)self;
}

void Xmonospatializer::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
    // connect all ports
    static_cast<Xmonospatializer*>(instance)->connect_all__ports(port, data);
}

void Xmonospatializer::activate(LV2_Handle instance)
{
    // allocate needed mem
    static_cast<Xmonospatializer*>(instance)->activate_f();
}

void Xmonospatializer::run(LV2_Handle instance, uint32_t n_samples)
{
    // run dsp
    static_cast<Xmonospatializer*>(instance)->run_dsp_(n_samples);
}

void Xmonospatializer::deactivate(LV2_Handle instance)
{
    // free allocated mem
    static_cast<Xmonospatializer*>(instance)->deactivate_f();
}

void Xmonospatializer::cleanup(LV2_Handle instance)
{
    // well, clean up after us
    Xmonospatializer* self = static_cast<Xmonospatializer*>(instance);
    self->clean_up();
    delete self;
}

const LV2_Descriptor Xmonospatializer::descriptor =
{
    PLUGIN_URI ,
    Xmonospatializer::instantiate,
    Xmonospatializer::connect_port,
    Xmonospatializer::activate,
    Xmonospatializer::run,
    Xmonospatializer::deactivate,
    Xmonospatializer::cleanup,
    NULL
};

} // end namespace monospatializer

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
    switch (index)
    {
        case 0:
            return &monospatializer::Xmonospatializer::descriptor;
        default:
            return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
