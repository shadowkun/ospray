#include <gtest/gtest.h>
#include "embree3/rtcore.h"
#include "openvkl/openvkl.h"
#include "ospray/OSPEnums.h"

TEST(Enums, VKLDataType)
{
  ASSERT_LE(sizeof(OSPDataType), sizeof(VKLDataType));
  ASSERT_EQ(OSP_CHAR, VKL_CHAR);
  ASSERT_EQ(OSP_UCHAR, VKL_UCHAR);
  ASSERT_EQ(OSP_VEC2UC, VKL_VEC2UC);
  ASSERT_EQ(OSP_VEC3UC, VKL_VEC3UC);
  ASSERT_EQ(OSP_VEC4UC, VKL_VEC4UC);
  ASSERT_EQ(OSP_SHORT, VKL_SHORT);
  ASSERT_EQ(OSP_USHORT, VKL_USHORT);
  ASSERT_EQ(OSP_INT, VKL_INT);
  ASSERT_EQ(OSP_VEC2I, VKL_VEC2I);
  ASSERT_EQ(OSP_VEC3I, VKL_VEC3I);
  ASSERT_EQ(OSP_VEC4I, VKL_VEC4I);
  ASSERT_EQ(OSP_UINT, VKL_UINT);
  ASSERT_EQ(OSP_VEC2UI, VKL_VEC2UI);
  ASSERT_EQ(OSP_VEC3UI, VKL_VEC3UI);
  ASSERT_EQ(OSP_VEC4UI, VKL_VEC4UI);
  ASSERT_EQ(OSP_LONG, VKL_LONG);
  ASSERT_EQ(OSP_VEC2L, VKL_VEC2L);
  ASSERT_EQ(OSP_VEC3L, VKL_VEC3L);
  ASSERT_EQ(OSP_VEC4L, VKL_VEC4L);
  ASSERT_EQ(OSP_ULONG, VKL_ULONG);
  ASSERT_EQ(OSP_VEC2UL, VKL_VEC2UL);
  ASSERT_EQ(OSP_VEC3UL, VKL_VEC3UL);
  ASSERT_EQ(OSP_VEC4UL, VKL_VEC4UL);
  ASSERT_EQ(OSP_FLOAT, VKL_FLOAT);
  ASSERT_EQ(OSP_VEC2F, VKL_VEC2F);
  ASSERT_EQ(OSP_VEC3F, VKL_VEC3F);
  ASSERT_EQ(OSP_VEC4F, VKL_VEC4F);
  ASSERT_EQ(OSP_DOUBLE, VKL_DOUBLE);
  ASSERT_EQ(OSP_BOX1I, VKL_BOX1I);
  ASSERT_EQ(OSP_BOX2I, VKL_BOX2I);
  ASSERT_EQ(OSP_BOX3I, VKL_BOX3I);
  ASSERT_EQ(OSP_BOX4I, VKL_BOX4I);
  ASSERT_EQ(OSP_BOX1F, VKL_BOX1F);
  ASSERT_EQ(OSP_BOX2F, VKL_BOX2F);
  ASSERT_EQ(OSP_BOX3F, VKL_BOX3F);
  ASSERT_EQ(OSP_BOX4F, VKL_BOX4F);
  ASSERT_EQ(OSP_DATA, VKL_DATA);
}

TEST(Enums, VKLUnstructuredCellType)
{
  ASSERT_LE(sizeof(OSPUnstructuredCellType), sizeof(VKLUnstructuredCellType));
  ASSERT_EQ(OSP_TETRAHEDRON, VKL_TETRAHEDRON);
  ASSERT_EQ(OSP_HEXAHEDRON, VKL_HEXAHEDRON);
  ASSERT_EQ(OSP_WEDGE, VKL_WEDGE);
  ASSERT_EQ(OSP_PYRAMID, VKL_PYRAMID);
}

TEST(Enums, VKLAMRMethod)
{
  ASSERT_LE(sizeof(OSPAMRMethod), sizeof(VKLAMRMethod));
  ASSERT_EQ(OSP_AMR_CURRENT, VKL_AMR_CURRENT);
  ASSERT_EQ(OSP_AMR_FINEST, VKL_AMR_FINEST);
  ASSERT_EQ(OSP_AMR_OCTANT, VKL_AMR_OCTANT);
}

TEST(Enums, RTCSubdivisionMode)
{
  ASSERT_LE(sizeof(OSPSubdivisionMode), sizeof(RTCSubdivisionMode));
  ASSERT_EQ(OSP_SUBDIVISION_NO_BOUNDARY, RTC_SUBDIVISION_MODE_NO_BOUNDARY);
  ASSERT_EQ(OSP_SUBDIVISION_SMOOTH_BOUNDARY, RTC_SUBDIVISION_MODE_SMOOTH_BOUNDARY);
  ASSERT_EQ(OSP_SUBDIVISION_PIN_CORNERS, RTC_SUBDIVISION_MODE_PIN_CORNERS);
  ASSERT_EQ(OSP_SUBDIVISION_PIN_BOUNDARY, RTC_SUBDIVISION_MODE_PIN_BOUNDARY);
  ASSERT_EQ(OSP_SUBDIVISION_PIN_ALL, RTC_SUBDIVISION_MODE_PIN_ALL);
}
