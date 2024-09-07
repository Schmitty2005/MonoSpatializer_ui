// generated from file '/home/bill/src/Faust-DSP/MonoSpatializer.dsp' by dsp2cc:
// Code generated with Faust 2.70.3 (https://faust.grame.fr)

#include <cmath>
#include <algorithm>

#define FAUSTFLOAT float

using std::signbit;

template<class T> inline T mydsp_faustpower2_f(T x) {return (x * x);}
template<class T> inline T mydsp_faustpower3_f(T x) {return ((x * x) * x);}
template<class T> inline T mydsp_faustpower4_f(T x) {return (((x * x) * x) * x);}
template<class T> inline T mydsp_faustpower5_f(T x) {return ((((x * x) * x) * x) * x);}
template<class T> inline T mydsp_faustpower6_f(T x) {return (((((x * x) * x) * x) * x) * x);}

#define always_inline inline __attribute__((__always_inline__))

typedef enum
{
   input0,
   output0,
   output1,
   DELAYMILLISECONDS, // fHslider1 , 2e+01, 1.0, 4e+01, 1.0 
   IMAGEVOLUME, // fHslider2 , 0.0, -96.0, 0.0, 0.1 
   LOWPASSFILTERFREQ, // fHslider0 , 8e+03, 2e+01, 2e+04, 1e+02 
   IMAGEPAN, // fEntry0 , 2e+01, -9e+01, 9e+01, 1.0 
   ORIGINALPAN, // fEntry1 , -2e+01, -9e+01, 9e+01, 1.0 
} PortIndex;


namespace monospatializer {

class Dsp {
private:
	uint32_t fSampleRate;
	double fConst1;
	double fConst2;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT	*fHslider0_;
	double fRec0[2];
	double fConst3;
	int IOTA0;
	double fVec0[8192];
	double fConst4;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT	*fHslider1_;
	double fRec8[2];
	double fConst5;
	double fRec4[2];
	double fRec5[2];
	double fRec6[2];
	double fRec7[2];
	double fRec3[3];
	double fRec2[3];
	double fRec1[3];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT	*fHslider2_;
	double fRec9[2];
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT	*fEntry0_;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT	*fEntry1_;


public:
	void connect(uint32_t port,void* data);
	void del_instance(Dsp *p);
	void clear_state_f();
	void init(uint32_t sample_rate);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, FAUSTFLOAT *output1);
	Dsp();
	~Dsp();
};



Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; l0 < 2; l0 = l0 + 1) fRec0[l0] = 0.0;
	for (int l1 = 0; l1 < 8192; l1 = l1 + 1) fVec0[l1] = 0.0;
	for (int l2 = 0; l2 < 2; l2 = l2 + 1) fRec8[l2] = 0.0;
	for (int l3 = 0; l3 < 2; l3 = l3 + 1) fRec4[l3] = 0.0;
	for (int l4 = 0; l4 < 2; l4 = l4 + 1) fRec5[l4] = 0.0;
	for (int l5 = 0; l5 < 2; l5 = l5 + 1) fRec6[l5] = 0.0;
	for (int l6 = 0; l6 < 2; l6 = l6 + 1) fRec7[l6] = 0.0;
	for (int l7 = 0; l7 < 3; l7 = l7 + 1) fRec3[l7] = 0.0;
	for (int l8 = 0; l8 < 3; l8 = l8 + 1) fRec2[l8] = 0.0;
	for (int l9 = 0; l9 < 3; l9 = l9 + 1) fRec1[l9] = 0.0;
	for (int l10 = 0; l10 < 2; l10 = l10 + 1) fRec9[l10] = 0.0;
}

inline void Dsp::init(uint32_t sample_rate)
{
	fSampleRate = sample_rate;
	double fConst0 = std::min<double>(1.92e+05, std::max<double>(1.0, double(fSampleRate)));
	fConst1 = 44.1 / fConst0;
	fConst2 = 1.0 - fConst1;
	fConst3 = 3.141592653589793 / fConst0;
	fConst4 = 0.04 * fConst0;
	fConst5 = 0.001 * fConst0;
	IOTA0 = 0;
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
#define fHslider0 (*fHslider0_)
#define fHslider1 (*fHslider1_)
#define fHslider2 (*fHslider2_)
#define fEntry0 (*fEntry0_)
#define fEntry1 (*fEntry1_)
	double fSlow0 = fConst1 * double(fHslider0);
	double fSlow1 = fConst1 * double(fHslider1);
	double fSlow2 = fConst1 * std::pow(1e+01, 0.05 * double(fHslider2));
	double fSlow3 = double(fEntry0) + -9e+01;
	double fSlow4 = std::sqrt(-0.005555555555555556 * fSlow3);
	double fSlow5 = double(fEntry1) + -9e+01;
	double fSlow6 = std::sqrt(-0.005555555555555556 * fSlow5);
	double fSlow7 = std::sqrt(0.005555555555555556 * fSlow3 + 1.0);
	double fSlow8 = std::sqrt(0.005555555555555556 * fSlow5 + 1.0);
	for (int i0 = 0; i0 < count; i0 = i0 + 1) {
		fRec0[0] = fSlow0 + fConst2 * fRec0[1];
		double fTemp0 = std::tan(fConst3 * fRec0[0]);
		double fTemp1 = 1.0 / fTemp0;
		double fTemp2 = (fTemp1 + 0.168404871113589) / fTemp0 + 1.069358407707312;
		double fTemp3 = mydsp_faustpower2_f(fTemp0);
		double fTemp4 = 1.0 / fTemp3;
		double fTemp5 = (fTemp1 + 0.512478641889141) / fTemp0 + 0.689621364484675;
		double fTemp6 = fTemp4 + 7.621731298870603;
		double fTemp7 = (fTemp1 + 0.782413046821645) / fTemp0 + 0.24529150870616;
		double fTemp8 = 9.9999997055e-05 / fTemp3;
		double fTemp9 = fTemp8 + 0.000433227200555;
		double fTemp10 = double(input0[i0]);
		fVec0[IOTA0 & 8191] = fTemp10;
		fRec8[0] = fSlow1 + fConst2 * fRec8[1];
		double fTemp11 = fConst5 * fRec8[0];
		double fTemp12 = ((fRec4[1] != 0.0) ? (((fRec5[1] > 0.0) & (fRec5[1] < 1.0)) ? fRec4[1] : 0.0) : (((fRec5[1] == 0.0) & (fTemp11 != fRec6[1])) ? 0.0078125 : (((fRec5[1] == 1.0) & (fTemp11 != fRec7[1])) ? -0.0078125 : 0.0)));
		fRec4[0] = fTemp12;
		fRec5[0] = std::max<double>(0.0, std::min<double>(1.0, fRec5[1] + fTemp12));
		fRec6[0] = (((fRec5[1] >= 1.0) & (fRec7[1] != fTemp11)) ? fTemp11 : fRec6[1]);
		fRec7[0] = (((fRec5[1] <= 0.0) & (fRec6[1] != fTemp11)) ? fTemp11 : fRec7[1]);
		double fTemp13 = fVec0[(IOTA0 - int(std::min<double>(fConst4, std::max<double>(0.0, fRec6[0])))) & 8191];
		fRec3[0] = fTemp13 + fRec5[0] * (fVec0[(IOTA0 - int(std::min<double>(fConst4, std::max<double>(0.0, fRec7[0])))) & 8191] - fTemp13) - (fRec3[2] * ((fTemp1 + -0.782413046821645) / fTemp0 + 0.24529150870616) + 2.0 * fRec3[1] * (0.24529150870616 - fTemp4)) / fTemp7;
		fRec2[0] = (fRec3[0] * fTemp9 + 2.0 * fRec3[1] * (0.000433227200555 - fTemp8) + fRec3[2] * fTemp9) / fTemp7 - (fRec2[2] * ((fTemp1 + -0.512478641889141) / fTemp0 + 0.689621364484675) + 2.0 * fRec2[1] * (0.689621364484675 - fTemp4)) / fTemp5;
		fRec1[0] = (fRec2[0] * fTemp6 + 2.0 * fRec2[1] * (7.621731298870603 - fTemp4) + fRec2[2] * fTemp6) / fTemp5 - (fRec1[2] * ((fTemp1 + -0.168404871113589) / fTemp0 + 1.069358407707312) + 2.0 * fRec1[1] * (1.069358407707312 - fTemp4)) / fTemp2;
		fRec9[0] = fSlow2 + fConst2 * fRec9[1];
		double fTemp14 = fRec9[0] * (2.0 * fRec1[1] * (53.53615295455673 - fTemp4) + (fTemp4 + 53.53615295455673) * (fRec1[0] + fRec1[2])) / fTemp2;
		output0[i0] = FAUSTFLOAT(fSlow6 * fTemp10 + fSlow4 * fTemp14);
		output1[i0] = FAUSTFLOAT(fSlow8 * fTemp10 + fSlow7 * fTemp14);
		fRec0[1] = fRec0[0];
		IOTA0 = IOTA0 + 1;
		fRec8[1] = fRec8[0];
		fRec4[1] = fRec4[0];
		fRec5[1] = fRec5[0];
		fRec6[1] = fRec6[0];
		fRec7[1] = fRec7[0];
		fRec3[2] = fRec3[1];
		fRec3[1] = fRec3[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fRec1[2] = fRec1[1];
		fRec1[1] = fRec1[0];
		fRec9[1] = fRec9[0];
	}
#undef fHslider0
#undef fHslider1
#undef fHslider2
#undef fEntry0
#undef fEntry1
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DELAYMILLISECONDS: 
		fHslider1_ = static_cast<float*>(data); // , 2e+01, 1.0, 4e+01, 1.0 
		break;
	case IMAGEVOLUME: 
		fHslider2_ = static_cast<float*>(data); // , 0.0, -96.0, 0.0, 0.1 
		break;
	case LOWPASSFILTERFREQ: 
		fHslider0_ = static_cast<float*>(data); // , 8e+03, 2e+01, 2e+04, 1e+02 
		break;
	case IMAGEPAN: 
		fEntry0_ = static_cast<float*>(data); // , 2e+01, -9e+01, 9e+01, 1.0 
		break;
	case ORIGINALPAN: 
		fEntry1_ = static_cast<float*>(data); // , -2e+01, -9e+01, 9e+01, 1.0 
		break;
	default:
		break;
	}
}

Dsp *plugin() {
	return new Dsp();
}

void Dsp::del_instance(Dsp *p)
{
	delete p;
}
} // end namespace monospatializer
