/* -LICENSE-START-
** Copyright (c) 2014 Blackmagic Design
**
** Permission is hereby granted, free of charge, to any person or organization
** obtaining a copy of the software and accompanying documentation covered by
** this license (the "Software") to use, reproduce, display, distribute,
** execute, and transmit the Software, and to prepare derivative works of the
** Software, and to permit third-parties to whom the Software is furnished to
** do so, all subject to the following:
** 
** The copyright notices in the Software and this entire statement, including
** the above license grant, this restriction and the following disclaimer,
** must be included in all copies of the Software, in whole or in part, and
** all derivative works of the Software, unless such copies or derivative
** works are solely in the form of machine-executable object code generated by
** a source language processor.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
** -LICENSE-END-
*/

#ifndef BMD_DECKLINKAPICONFIGURATION_H
#define BMD_DECKLINKAPICONFIGURATION_H


#ifndef BMD_CONST
    #if defined(_MSC_VER)
        #define BMD_CONST __declspec(selectany) static const
    #else
        #define BMD_CONST static const
    #endif
#endif

// Type Declarations


// Interface ID Declarations

BMD_CONST REFIID IID_IDeckLinkConfiguration                       = /* C679A35B-610C-4D09-B748-1D0478100FC0 */ {0xC6,0x79,0xA3,0x5B,0x61,0x0C,0x4D,0x09,0xB7,0x48,0x1D,0x04,0x78,0x10,0x0F,0xC0};

/* Enum BMDDeckLinkConfigurationID - DeckLink Configuration ID */

typedef uint32_t BMDDeckLinkConfigurationID;
enum _BMDDeckLinkConfigurationID {

    /* Serial port Flags */

    bmdDeckLinkConfigSwapSerialRxTx                              = 'ssrt',

    /* Video Input/Output Flags */

    bmdDeckLinkConfigUse1080pNotPsF                              = 'fpro',

    /* Video Input/Output Integers */

    bmdDeckLinkConfigHDMI3DPackingFormat                         = '3dpf',
    bmdDeckLinkConfigBypass                                      = 'byps',
    bmdDeckLinkConfigClockTimingAdjustment                       = 'ctad',

    /* Audio Input/Output Flags */

    bmdDeckLinkConfigAnalogAudioConsumerLevels                   = 'aacl',

    /* Video output flags */

    bmdDeckLinkConfigFieldFlickerRemoval                         = 'fdfr',
    bmdDeckLinkConfigHD1080p24ToHD1080i5994Conversion            = 'to59',
    bmdDeckLinkConfig444SDIVideoOutput                           = '444o',
    bmdDeckLinkConfig3GBpsVideoOutput                            = '3gbs',
    bmdDeckLinkConfigBlackVideoOutputDuringCapture               = 'bvoc',
    bmdDeckLinkConfigLowLatencyVideoOutput                       = 'llvo',

    /* Video Output Integers */

    bmdDeckLinkConfigVideoOutputConnection                       = 'vocn',
    bmdDeckLinkConfigVideoOutputConversionMode                   = 'vocm',
    bmdDeckLinkConfigAnalogVideoOutputFlags                      = 'avof',
    bmdDeckLinkConfigReferenceInputTimingOffset                  = 'glot',
    bmdDeckLinkConfigVideoOutputIdleOperation                    = 'voio',
    bmdDeckLinkConfigDefaultVideoOutputMode                      = 'dvom',
    bmdDeckLinkConfigDefaultVideoOutputModeFlags                 = 'dvof',

    /* Video Output Floats */

    bmdDeckLinkConfigVideoOutputComponentLumaGain                = 'oclg',
    bmdDeckLinkConfigVideoOutputComponentChromaBlueGain          = 'occb',
    bmdDeckLinkConfigVideoOutputComponentChromaRedGain           = 'occr',
    bmdDeckLinkConfigVideoOutputCompositeLumaGain                = 'oilg',
    bmdDeckLinkConfigVideoOutputCompositeChromaGain              = 'oicg',
    bmdDeckLinkConfigVideoOutputSVideoLumaGain                   = 'oslg',
    bmdDeckLinkConfigVideoOutputSVideoChromaGain                 = 'oscg',

    /* Video Input Flags */

    bmdDeckLinkConfigVideoInputScanning                          = 'visc',	// Applicable to H264 Pro Recorder only
    bmdDeckLinkConfigUseDedicatedLTCInput                        = 'dltc',	// Use timecode from LTC input instead of SDI stream

    /* Video Input Integers */

    bmdDeckLinkConfigVideoInputConnection                        = 'vicn',
    bmdDeckLinkConfigAnalogVideoInputFlags                       = 'avif',
    bmdDeckLinkConfigVideoInputConversionMode                    = 'vicm',
    bmdDeckLinkConfig32PulldownSequenceInitialTimecodeFrame      = 'pdif',
    bmdDeckLinkConfigVANCSourceLine1Mapping                      = 'vsl1',
    bmdDeckLinkConfigVANCSourceLine2Mapping                      = 'vsl2',
    bmdDeckLinkConfigVANCSourceLine3Mapping                      = 'vsl3',

    /* Video Input Floats */

    bmdDeckLinkConfigVideoInputComponentLumaGain                 = 'iclg',
    bmdDeckLinkConfigVideoInputComponentChromaBlueGain           = 'iccb',
    bmdDeckLinkConfigVideoInputComponentChromaRedGain            = 'iccr',
    bmdDeckLinkConfigVideoInputCompositeLumaGain                 = 'iilg',
    bmdDeckLinkConfigVideoInputCompositeChromaGain               = 'iicg',
    bmdDeckLinkConfigVideoInputSVideoLumaGain                    = 'islg',
    bmdDeckLinkConfigVideoInputSVideoChromaGain                  = 'iscg',

    /* Audio Input Integers */

    bmdDeckLinkConfigAudioInputConnection                        = 'aicn',

    /* Audio Input Floats */

    bmdDeckLinkConfigAnalogAudioInputScaleChannel1               = 'ais1',
    bmdDeckLinkConfigAnalogAudioInputScaleChannel2               = 'ais2',
    bmdDeckLinkConfigAnalogAudioInputScaleChannel3               = 'ais3',
    bmdDeckLinkConfigAnalogAudioInputScaleChannel4               = 'ais4',
    bmdDeckLinkConfigDigitalAudioInputScale                      = 'dais',

    /* Audio Output Integers */

    bmdDeckLinkConfigAudioOutputAESAnalogSwitch                  = 'aoaa',

    /* Audio Output Floats */

    bmdDeckLinkConfigAnalogAudioOutputScaleChannel1              = 'aos1',
    bmdDeckLinkConfigAnalogAudioOutputScaleChannel2              = 'aos2',
    bmdDeckLinkConfigAnalogAudioOutputScaleChannel3              = 'aos3',
    bmdDeckLinkConfigAnalogAudioOutputScaleChannel4              = 'aos4',
    bmdDeckLinkConfigDigitalAudioOutputScale                     = 'daos'
};

// Forward Declarations

class IDeckLinkConfiguration;

/* Interface IDeckLinkConfiguration - DeckLink Configuration interface */

class IDeckLinkConfiguration : public IUnknown
{
public:
    virtual HRESULT SetFlag (/* in */ BMDDeckLinkConfigurationID cfgID, /* in */ bool value) = 0;
    virtual HRESULT GetFlag (/* in */ BMDDeckLinkConfigurationID cfgID, /* out */ bool *value) = 0;
    virtual HRESULT SetInt (/* in */ BMDDeckLinkConfigurationID cfgID, /* in */ int64_t value) = 0;
    virtual HRESULT GetInt (/* in */ BMDDeckLinkConfigurationID cfgID, /* out */ int64_t *value) = 0;
    virtual HRESULT SetFloat (/* in */ BMDDeckLinkConfigurationID cfgID, /* in */ double value) = 0;
    virtual HRESULT GetFloat (/* in */ BMDDeckLinkConfigurationID cfgID, /* out */ double *value) = 0;
    virtual HRESULT SetString (/* in */ BMDDeckLinkConfigurationID cfgID, /* in */ CFStringRef value) = 0;
    virtual HRESULT GetString (/* in */ BMDDeckLinkConfigurationID cfgID, /* out */ CFStringRef *value) = 0;
    virtual HRESULT WriteConfigurationToPreferences (void) = 0;

protected:
    virtual ~IDeckLinkConfiguration () {}; // call Release method to drop reference count
};

/* Functions */

extern "C" {


};


#endif /* defined(BMD_DECKLINKAPICONFIGURATION_H) */
