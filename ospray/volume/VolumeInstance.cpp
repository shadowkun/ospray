// ======================================================================== //
// Copyright 2009-2019 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

// ospray
#include "VolumeInstance.h"
// ispc exports
#include "VolumeInstance_ispc.h"

namespace ospray {

  VolumeInstance::VolumeInstance(Volume *volume)
  {
    if (volume == nullptr)
      throw std::runtime_error("NULL Volume given to VolumeInstance!");

    instancedVolume = volume;

    this->ispcEquivalent = ispc::VolumeInstance_create(this, volume->getIE());
  }

  std::string VolumeInstance::toString() const
  {
    return "ospray::VolumeInstance";
  }

  void VolumeInstance::commit()
  {
    // Get transform information //

    instanceXfm.l.vx = getParam3f("xfm.l.vx", vec3f(1.f, 0.f, 0.f));
    instanceXfm.l.vy = getParam3f("xfm.l.vy", vec3f(0.f, 1.f, 0.f));
    instanceXfm.l.vz = getParam3f("xfm.l.vz", vec3f(0.f, 0.f, 1.f));
    instanceXfm.p    = getParam3f("xfm.p", vec3f(0.f, 0.f, 0.f));

    const box3f b = instancedVolume->bounds;
    const vec3f v000(b.lower.x, b.lower.y, b.lower.z);
    const vec3f v001(b.upper.x, b.lower.y, b.lower.z);
    const vec3f v010(b.lower.x, b.upper.y, b.lower.z);
    const vec3f v011(b.upper.x, b.upper.y, b.lower.z);
    const vec3f v100(b.lower.x, b.lower.y, b.upper.z);
    const vec3f v101(b.upper.x, b.lower.y, b.upper.z);
    const vec3f v110(b.lower.x, b.upper.y, b.upper.z);
    const vec3f v111(b.upper.x, b.upper.y, b.upper.z);

    instanceBounds = empty;
    instanceBounds.extend(xfmPoint(instanceXfm, v000));
    instanceBounds.extend(xfmPoint(instanceXfm, v001));
    instanceBounds.extend(xfmPoint(instanceXfm, v010));
    instanceBounds.extend(xfmPoint(instanceXfm, v011));
    instanceBounds.extend(xfmPoint(instanceXfm, v100));
    instanceBounds.extend(xfmPoint(instanceXfm, v101));
    instanceBounds.extend(xfmPoint(instanceXfm, v110));
    instanceBounds.extend(xfmPoint(instanceXfm, v111));

    AffineSpace3f rcp_xfm = rcp(instanceXfm);

    ispc::VolumeInstance_set(getIE(),
                             (ispc::AffineSpace3f &)instanceXfm,
                             (ispc::AffineSpace3f &)rcp_xfm);
  }

  box3f VolumeInstance::bounds() const
  {
    return instanceBounds;
  }

  AffineSpace3f VolumeInstance::xfm() const
  {
    return instanceXfm;
  }

}  // namespace ospray
