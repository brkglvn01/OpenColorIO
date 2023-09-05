// SPDX-License-Identifier: BSD-3-Clause
// Copyright Contributors to the OpenColorIO Project.

#ifndef INCLUDED_OFX_OCIOFILE_H
#define INCLUDED_OFX_OCIOFILE_H

#include "OCIOUtils.h"

#include <string>

#include "ofxsImageEffect.h"

class OCIOFile : public OFX::ImageEffect
{
protected:
    // Do not need to delete these. The ImageEffect is managing them for us.
    OFX::Clip* dstClip_;
    OFX::Clip* srcClip_;

    OFX::ChoiceParam* srcPathNameParam_;
    OFX::BooleanParam* inverseParam_;

    ParamMap contextParams_;

public:
    OCIOFile(OfxImageEffectHandle handle);

    /* Override the render */
    void render(const OFX::RenderArguments& args) override;

    /* Override identity (~no-op) check */
    bool isIdentity(const OFX::IsIdentityArguments& args,
        OFX::Clip*& identityClip,
        double& identityTime) override;

    /* Override changedParam */
    void changedParam(const OFX::InstanceChangedArgs& args,
        const std::string& paramName) override;

};

mDeclarePluginFactory(OCIOFileFactory, {}, {});

#endif // INCLUDED_OFX_OCIOFILE_H