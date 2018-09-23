/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#define LOG_TAG "isp_tuning_idx"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif

#include <string.h>
#include <cutils/properties.h>
#include <stdlib.h>
#include <aaa_log.h>
#include <aaa_types.h>
#include "camera_custom_nvram.h"
#include <isp_tuning.h>
#include <awb_param.h>
#include <ae_param.h>
#include <af_param.h>
#include <flash_param.h>
#include <isp_tuning_cam_info.h>
#include <isp_tuning_idx.h>
#include "cfg_isp_tuning_idx_preview.h"
#include "cfg_isp_tuning_idx_video.h"
#include "cfg_isp_tuning_idx_capture.h"
#include "cfg_isp_tuning_idx_feature.h"

using namespace NSIspTuning;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
namespace
{
    enum EIndexNum
    {
        NUM_OBC         =   NVRAM_OBC_TBL_NUM,
        NUM_BPC         =   NVRAM_BPC_TBL_NUM,
        NUM_NR1         =   NVRAM_NR1_TBL_NUM,
        NUM_CFA         =   NVRAM_CFA_TBL_NUM,
        NUM_GGM         =   NVRAM_GGM_TBL_NUM,
        NUM_ANR         =   NVRAM_ANR_TBL_NUM,
        NUM_CCR         =   NVRAM_CCR_TBL_NUM,
        NUM_EE          =   NVRAM_EE_TBL_NUM,
        NUM_NR3D        =   NVRAM_NR3D_TBL_NUM,
        NUM_MFB         =   NVRAM_MFB_TBL_NUM,
        NUM_LCE         =   NVRAM_LCE_TBL_NUM
    };

    template <EIndexNum Num>
    inline MBOOL setIdx(UINT16 &rIdxTgt, UINT16 const IdxSrc)
    {
        if  (IdxSrc < Num)
        {
            rIdxTgt = IdxSrc;
            return  MTRUE;
        }
        return  MFALSE;
    }

};  //  namespace


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL IndexMgr::setIdx_OBC(UINT16 const idx)   { return setIdx<NUM_OBC>(OBC, idx); }
MBOOL IndexMgr::setIdx_BPC(UINT16 const idx)   { return setIdx<NUM_BPC>(BPC, idx); }
MBOOL IndexMgr::setIdx_NR1(UINT16 const idx)   { return setIdx<NUM_NR1>(NR1, idx); }
MBOOL IndexMgr::setIdx_CFA(UINT16 const idx)   { return setIdx<NUM_CFA>(CFA, idx); }
MBOOL IndexMgr::setIdx_GGM(UINT16 const idx)   { return setIdx<NUM_GGM>(GGM, idx); }
MBOOL IndexMgr::setIdx_ANR(UINT16 const idx)   { return setIdx<NUM_ANR>(ANR, idx); }
MBOOL IndexMgr::setIdx_CCR(UINT16 const idx)   { return setIdx<NUM_CCR>(CCR, idx); }
MBOOL IndexMgr::setIdx_EE(UINT16 const idx)    { return setIdx<NUM_EE>(EE, idx);   }
MBOOL IndexMgr::setIdx_NR3D(UINT16 const idx)  { return setIdx<NUM_NR3D>(NR3D, idx); }
MBOOL IndexMgr::setIdx_MFB(UINT16 const idx)   { return setIdx<NUM_MFB>(MFB, idx);   }
MBOOL IndexMgr::setIdx_LCE(UINT16 const idx)   { return setIdx<NUM_LCE>(LCE, idx);   }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void
IndexMgr::
dump() const
{
    MY_LOG(
        "[IndexMgr][dump]"
        " OBC:%d, BPC:%d, NR1:%d, CFA:%d, GGM:%d, ANR:%d, CCR:%d, EE:%d, NR3D:%d, MFB:%d, LCE:%d"
        , OBC, BPC, NR1, CFA, GGM, ANR, CCR, EE, NR3D, MFB, LCE
    );
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
IdxSetMgrBase&
IdxSetMgrBase::
getInstance()
{
    static IdxSetMgr singleton;

    static struct link
    {
        link(IdxSetMgr& r)
        {
            r.linkIndexSet();
        }
    } link_singleton(singleton);
    
    return  singleton;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MVOID
IdxSetMgr::
linkIndexSet()
{
    ::memset(m_pPreview,              0, sizeof(m_pPreview));
    ::memset(m_pVideo,                0, sizeof(m_pVideo));
    ::memset(m_pCapture,              0, sizeof(m_pCapture));
    ::memset(m_pN3D_Preview,          0, sizeof(m_pN3D_Preview));
    ::memset(m_pN3D_Video,            0, sizeof(m_pN3D_Video));
    ::memset(m_pN3D_Capture,          0, sizeof(m_pN3D_Capture));
    ::memset(m_pMFB_Blending_All_Off, 0, sizeof(m_pMFB_Blending_All_Off));
    ::memset(m_pMFB_Blending_All_Off_SWNR, 0, sizeof(m_pMFB_Blending_All_Off_SWNR));    
    ::memset(m_pMFB_PostProc_Mixing,  0, sizeof(m_pMFB_PostProc_Mixing));
    ::memset(m_pMFB_PostProc_Mixing_SWNR,  0, sizeof(m_pMFB_PostProc_Mixing_SWNR));
    ::memset(m_pMFB_Capture_EE_Off,   0, sizeof(m_pMFB_Capture_EE_Off));
    ::memset(m_pIHDR_Preview,         0, sizeof(m_pIHDR_Preview));
    ::memset(m_pIHDR_Video,           0, sizeof(m_pIHDR_Video));
    ::memset(m_pMulti_Pass_ANR1,      0, sizeof(m_pMulti_Pass_ANR1));
    ::memset(m_pMulti_Pass_ANR2,      0, sizeof(m_pMulti_Pass_ANR2));
    ::memset(m_pMFB_Multi_Pass_ANR1,  0, sizeof(m_pMFB_Multi_Pass_ANR1));
    ::memset(m_pMFB_Multi_Pass_ANR2,  0, sizeof(m_pMFB_Multi_Pass_ANR2));

#define LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, scene)\
    link(sensor, scene, eIDX_ISO_100);\
    link(sensor, scene, eIDX_ISO_200);\
    link(sensor, scene, eIDX_ISO_400);\
    link(sensor, scene, eIDX_ISO_800);\
    link(sensor, scene, eIDX_ISO_1200);\
    link(sensor, scene, eIDX_ISO_1600);\
    link(sensor, scene, eIDX_ISO_2000);\
    link(sensor, scene, eIDX_ISO_2400);\
    link(sensor, scene, eIDX_ISO_2800);\
    link(sensor, scene, eIDX_ISO_3200);

#define LINK_ONE_SCENE_SENSORS_ISOs(link, scene)\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, ESensorMode_Preview, scene);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, ESensorMode_Video, scene);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, ESensorMode_Capture, scene);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, ESensorMode_SlimVideo1, scene);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, ESensorMode_SlimVideo2, scene);

#define LINK_ONE_SENSOR_SCENEs_ISOs(link, sensor)\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_UNSUPPORTED);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_NORMAL);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_ACTION);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_PORTRAIT);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_LANDSCAPE);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_NIGHT);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_NIGHT_PORTRAIT);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_THEATRE);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_BEACH);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_SNOW);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_SUNSET);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_STEADYPHOTO);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_FIREWORKS);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_SPORTS);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_PARTY);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_CANDLELIGHT);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_HDR);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_FACE_PRIORITY);\
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(link, sensor, MTK_CONTROL_SCENE_MODE_BARCODE);

#define LINK_SENSORs_SCENEs_ISOs(link)\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Preview);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Video);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Capture);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_SlimVideo1);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_SlimVideo2);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Custom1);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Custom2);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Custom3);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Custom4);\
    LINK_ONE_SENSOR_SCENEs_ISOs(link, ESensorMode_Custom5);

#define LINK_CAPTURE(sensor, scene, iso)\
m_pCapture[sensor][scene][iso] = &IdxSet<EIspProfile_Capture, sensor, scene, iso>::idx

#define LINK_VIDEO(sensor, scene, iso)\
m_pVideo[sensor][scene][iso] = &IdxSet<EIspProfile_Video, sensor, scene, iso>::idx

#define LINK_PREVIEW(sensor, scene, iso)\
m_pPreview[sensor][scene][iso] = &IdxSet<EIspProfile_Preview, sensor, scene, iso>::idx

    LINK_SENSORs_SCENEs_ISOs(LINK_CAPTURE);
    LINK_SENSORs_SCENEs_ISOs(LINK_VIDEO);
    LINK_SENSORs_SCENEs_ISOs(LINK_PREVIEW);


//==================================================================================================

#define LINK_N3D_PREVIEW(sensor, scene, iso)\
m_pN3D_Preview[iso] = &IdxSet<EIspProfile_N3D_Preview, sensor, scene, iso>::idx

#define LINK_N3D_VIDEO(sensor, scene, iso)\
m_pN3D_Video[iso] = &IdxSet<EIspProfile_N3D_Video, sensor, scene, iso>::idx

#define LINK_N3D_CAPTURE(sensor, scene, iso)\
m_pN3D_Capture[iso] = &IdxSet<EIspProfile_N3D_Capture, sensor, scene, iso>::idx

#define LINK_MFB_BLENDING_ALL_OFF(sensor, scene, iso)\
m_pMFB_Blending_All_Off[iso] = &IdxSet<EIspProfile_MFB_Blending_All_Off, sensor, scene, iso>::idx

#define LINK_MFB_BLENDING_ALL_OFF_SWNR(sensor, scene, iso)\
m_pMFB_Blending_All_Off_SWNR[iso] = &IdxSet<EIspProfile_MFB_Blending_All_Off_SWNR, sensor, scene, iso>::idx

#define LINK_MFB_POSTPROC_MIXING(sensor, scene, iso)\
m_pMFB_PostProc_Mixing[iso] = &IdxSet<EIspProfile_MFB_PostProc_Mixing, sensor, scene, iso>::idx

#define LINK_MFB_POSTPROC_MIXING_SWNR(sensor, scene, iso)\
m_pMFB_PostProc_Mixing_SWNR[iso] = &IdxSet<EIspProfile_MFB_PostProc_Mixing_SWNR, sensor, scene, iso>::idx

#define LINK_IHDR_PREVIEW(sensor, scene, iso)\
m_pIHDR_Preview[iso] = &IdxSet<EIspProfile_IHDR_Preview, sensor, scene, iso>::idx

#define LINK_IHDR_VIDEO(sensor, scene, iso)\
m_pIHDR_Video[iso] = &IdxSet<EIspProfile_IHDR_Video, sensor, scene, iso>::idx

#define LINK_MULTI_PASS_ANR1(sensor, scene, iso)\
m_pMulti_Pass_ANR1[iso] = &IdxSet<EIspProfile_Capture_MultiPass_ANR_1, sensor, scene, iso>::idx

#define LINK_MULTI_PASS_ANR2(sensor, scene, iso)\
m_pMulti_Pass_ANR2[iso] = &IdxSet<EIspProfile_Capture_MultiPass_ANR_2, sensor, scene, iso>::idx

#define LINK_MFB_MULTI_PASS_ANR1(sensor, scene, iso)\
m_pMFB_Multi_Pass_ANR1[iso] = &IdxSet<EIspProfile_MFB_MultiPass_ANR_1, sensor, scene, iso>::idx

#define LINK_MFB_MULTI_PASS_ANR2(sensor, scene, iso)\
m_pMFB_Multi_Pass_ANR2[iso] = &IdxSet<EIspProfile_MFB_MultiPass_ANR_2, sensor, scene, iso>::idx

    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_N3D_PREVIEW, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_N3D_VIDEO, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_N3D_CAPTURE, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MFB_BLENDING_ALL_OFF, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MFB_BLENDING_ALL_OFF_SWNR, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MFB_POSTPROC_MIXING, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MFB_POSTPROC_MIXING_SWNR, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_IHDR_PREVIEW, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_IHDR_VIDEO, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MULTI_PASS_ANR1, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MULTI_PASS_ANR2, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MFB_MULTI_PASS_ANR1, 0, 0);
    LINK_ONE_SENSOR_ONE_SCENE_ISOs(LINK_MFB_MULTI_PASS_ANR2, 0, 0);

//==================================================================================================
#define LINK_MFB_CAPTURE_EE_OFF(sensor, scene, iso)\
m_pMFB_Capture_EE_Off[sensor][iso] = &IdxSet<EIspProfile_MFB_Capture_EE_Off, sensor, scene, iso>::idx

    LINK_ONE_SCENE_SENSORS_ISOs(LINK_MFB_CAPTURE_EE_OFF, 0);

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
INDEX_T const*
IdxSetMgr::
get(MUINT32 ispProfile, MUINT32 sensor/*=-1*/, MUINT32 const scene/*=-1*/, MUINT32 const iso/*=-1*/) const
{
	char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("enable.isp.profile", value, "0");
    MBOOL bEnableIspProfileSetting = atoi(value);

    // for AE1 video mode tuning purpose
    if (bEnableIspProfileSetting) {
        property_get("set.isp.profile", value, "1");
        MINT32 i4NewIspProfile = atoi(value);
        ispProfile = static_cast<MUINT32>(i4NewIspProfile);
        MY_LOG("i4NewIspProfile = %d", i4NewIspProfile);
    }
    
    // Add for new sensor mode after MP
#if 0
    if (sensor > ESensorMode_SlimVideo2) { // sensor mode re-mapping for ISP tuning paramter sharing
        sensor = static_cast<MUINT32>(ESensorMode_SlimVideo2);
    }
#endif

    switch  (ispProfile)
    {
    //  Normal
    case EIspProfile_Preview:
        return  get_Preview(sensor, scene, iso);
    case EIspProfile_Video:
    case EIspProfile_VFB_PostProc:
        return  get_Video(sensor, scene, iso);
    case EIspProfile_Capture:
    case EIspProfile_ZSD_Capture:
    case EIspProfile_VSS_Capture:
    case EIspProfile_PureRAW_Capture:
    case EIspProfile_MFB_PostProc_ANR_EE:
    case EIspProfile_VSS_MFB_PostProc_ANR_EE:
    case EIspProfile_MFB_PostProc_ANR_EE_SWNR:
    case EIspProfile_VSS_MFB_PostProc_ANR_EE_SWNR:
    case EIspProfile_Capture_SWNR:  
    case EIspProfile_VSS_Capture_SWNR:      
    case EIspProfile_PureRAW_Capture_SWNR:    
        return  get_Capture(sensor, scene, iso);
    case EIspProfile_MHDR_Capture: // temp solution: scenario = video, sensor mode = capture
        return  get_Video(sensor, scene, iso);
    case EIspProfile_N3D_Preview:
        return get_N3D_Preview(sensor, scene, iso);
    case EIspProfile_N3D_Video:
        return get_N3D_Video(sensor, scene, iso);
    case EIspProfile_N3D_Capture:
        return get_N3D_Capture(sensor, scene, iso);
    case EIspProfile_MFB_Blending_All_Off:
    case EIspProfile_VSS_MFB_Blending_All_Off:
        return get_MFB_Blending_All_Off(sensor, scene, iso);
    case EIspProfile_MFB_Blending_All_Off_SWNR:
    case EIspProfile_VSS_MFB_Blending_All_Off_SWNR:
        return get_MFB_Blending_All_Off_SWNR(sensor, scene, iso);        
    case EIspProfile_MFB_Capture_EE_Off:
    case EIspProfile_VSS_MFB_Capture_EE_Off:
    case EIspProfile_MFB_Capture_EE_Off_SWNR:
    case EIspProfile_VSS_MFB_Capture_EE_Off_SWNR:
    case EIspProfile_MFB_PostProc_EE_Off:
    case EIspProfile_VSS_MFB_PostProc_EE_Off:
        return get_MFB_Capture_EE_Off(sensor, scene, iso);
    case EIspProfile_MFB_PostProc_Mixing:
    case EIspProfile_VSS_MFB_PostProc_Mixing:
        return get_MFB_PostProc_Mixing(sensor, scene, iso);
    case EIspProfile_MFB_PostProc_Mixing_SWNR:
    case EIspProfile_VSS_MFB_PostProc_Mixing_SWNR:
        return get_MFB_PostProc_Mixing_SWNR(sensor, scene, iso);
    case EIspProfile_IHDR_Preview:
    case EIspProfile_MHDR_Preview:    
        return get_IHDR_Preview(sensor, scene, iso);
    case EIspProfile_IHDR_Video:
    case EIspProfile_MHDR_Video:    
        return get_IHDR_Video(sensor, scene, iso);
    case EIspProfile_Capture_MultiPass_ANR_1:
    case EIspProfile_VSS_Capture_MultiPass_ANR_1:
        return get_Multi_Pass_ANR1(sensor, scene, iso);
    case EIspProfile_Capture_MultiPass_ANR_2:
    case EIspProfile_VSS_Capture_MultiPass_ANR_2:
        return get_Multi_Pass_ANR2(sensor, scene, iso);
    case EIspProfile_MFB_MultiPass_ANR_1:
    case EIspProfile_VSS_MFB_MultiPass_ANR_1:
        return get_MFB_Multi_Pass_ANR1(sensor, scene, iso);
    case EIspProfile_MFB_MultiPass_ANR_2:
    case EIspProfile_VSS_MFB_MultiPass_ANR_2:
        return get_MFB_Multi_Pass_ANR2(sensor, scene, iso);
    default:
        break;
    }
    return  NULL;
}


