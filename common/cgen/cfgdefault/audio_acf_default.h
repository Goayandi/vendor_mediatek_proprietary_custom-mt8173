/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * audio_acf_default.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 * This file is the header of audio customization related parameters or definition.
 *
 * Author:
 * -------
 * Tina Tsai
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 04 22 2013 kh.hung
 * [ALPS00580843] [MT6572tdv1_phone[lca]][music][Symbio][Free test] 音?播放器播放音?的?音?大?小，不?定
 * Use default DRC setting.
 * 
 * Review: http://mtksap20:8080/go?page=NewReview&reviewid=59367
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef AUDIO_ACF_DEFAULT_H
#define AUDIO_ACF_DEFAULT_H
#if defined(MTK_AUDIO_BLOUD_CUSTOMPARAMETER_V5)
/* Compensation Filter HSF coeffs: default all pass filter       */
    /* BesLoudness also uses this coeffs    */ 
#define BES_LOUDNESS_ACF_L_HPF_FC       400
#define BES_LOUDNESS_ACF_L_HPF_ORDER    2
#define BES_LOUDNESS_ACF_L_BPF_FC       4000, 500, 2000, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_L_BPF_BW       1421, 284, 1421, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_L_BPF_GAIN     6 << 8, -6 << 8, 6 << 8, 0 << 8, 0 << 8, 0 << 8, 0 << 8, 0 << 8
#define BES_LOUDNESS_ACF_L_LPF_FC       0
#define BES_LOUDNESS_ACF_L_LPF_ORDER    0
#define BES_LOUDNESS_ACF_R_HPF_FC       400
#define BES_LOUDNESS_ACF_R_HPF_ORDER    2
#define BES_LOUDNESS_ACF_R_BPF_FC       4000, 500, 2000, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_R_BPF_BW       1421, 284, 1421, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_R_BPF_GAIN     6 << 8, -6 << 8, 6 << 8, 0 << 8, 0 << 8, 0 << 8, 0 << 8, 0 << 8
#define BES_LOUDNESS_ACF_R_LPF_FC       0
#define BES_LOUDNESS_ACF_R_LPF_ORDER    0
	
#define BES_LOUDNESS_ACF_SEP_LR_FILTER  0

#define BES_LOUDNESS_ACF_WS_GAIN_MAX    0
#define BES_LOUDNESS_ACF_WS_GAIN_MIN    0
#define BES_LOUDNESS_ACF_FILTER_FIRST   0

#define BES_LOUDNESS_ACF_NUM_BANDS      0
#define BES_LOUDNESS_ACF_FLT_BANK_ORDER 0
#define BES_LOUDNESS_ACF_DRC_DELAY      0
#define BES_LOUDNESS_ACF_CROSSOVER_FREQ 0, 0, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_SB_MODE        0, 0, 0, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_SB_GAIN        0, 0, 0, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_GAIN_MAP_IN    \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_GAIN_MAP_OUT   \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0,                  \
        0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_ATT_TIME       \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_REL_TIME       \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0
#define BES_LOUDNESS_ACF_HYST_TH        \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0,               \
        0, 0, 0, 0, 0, 0

#define BES_LOUDNESS_ACF_LIM_TH     0
#define BES_LOUDNESS_ACF_LIM_GN     0
#define BES_LOUDNESS_ACF_LIM_CONST  0
#define BES_LOUDNESS_ACF_LIM_DELAY  0

#elif defined(MTK_AUDIO_BLOUD_CUSTOMPARAMETER_V4)              
/* Compensation Filter HSF coeffs: default all pass filter       */
    /* BesLoudness also uses this coeffs    */ 
    #define BES_LOUDNESS_HSF_COEFF \
0x7d1273d,   0xf05db185,   0x7d1273d,   0x7d09c2e4,   0x0,     \
0x7cd0ff2,   0xf065e01c,   0x7cd0ff2,   0x7cc6c324,   0x0,     \
0x7ba2211,   0xf08bbbde,   0x7ba2211,   0x7b8fc44a,   0x0,     \
0x7a36091,   0xf0b93ede,   0x7a36091,   0x7a14c5a8,   0x0,     \
0x79b63e3,   0xf0c9383a,   0x79b63e3,   0x798ec622,   0x0,     \
0x776a522,   0xf112b5bc,   0x776a522,   0x7720c84b,   0x0,     \
0x74aedf3,   0xf16a241a,   0x74aedf3,   0x742ecad0,   0x0,     \
0x73bb426,   0xf18897b4,   0x73bb426,   0x7324cbad,   0x0,     \
0x6f66ffb,   0xf2132009,   0x6f66ffb,   0x6e52cf84,   0x0,     \
    \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0

    /* Compensation Filter BPF coeffs: default all pass filter      */ 
    #define BES_LOUDNESS_BPF_COEFF \
0x3fd08185,   0x3ef07e7a,   0xc13e0000,     \
0x3fcc81ae,   0x3ed87e51,   0xc15a0000,     \
0x3fb9827a,   0x3e6a7d85,   0xc1db0000,     \
0x3fa2838f,   0x3de67c70,   0xc2770000,     \
0x3f9a83f9,   0x3db77c06,   0xc2ad0000,     \
0x3f758619,   0x3ce079e6,   0xc3a90000,     \
    \
0x3fc08259,   0x3e977da6,   0xc1a70000,     \
0x3fbb829e,   0x3e787d61,   0xc1cc0000,     \
0x3fa28403,   0x3de67bfc,   0xc2770000,     \
0x3f8385ff,   0x3d387a00,   0xc3440000,     \
0x3f7886c6,   0x3cfb7939,   0xc38c0000,     \
0x3f478ae1,   0x3be1751e,   0xc4d60000,     \
    \
0x40000000,   0x38200000,   0xc7df0000,     \
0x4000108b,   0x3779ef74,   0xc8860000,     \
0x40005264,   0x3486ad9b,   0xcb790000,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x3f2fab0e,   0x38f054f1,   0xc7df0000,     \
0x3f1eb195,   0x385a4e6a,   0xc8860000,     \
0x3ed0d368,   0x35b52c97,   0xcb790000,     \
0x3e760000,   0x32a50000,   0xcee40000,     \
0x3e570f80,   0x3199f07f,   0xd00e0000,     \
0x3dce4b7e,   0x2cf4b481,   0xd53c0000,     \
    \
0x40000000,   0x86c0000,   0xf7930000,     \
0x40000982,   0x4aef67d,   0xfb510000,     \
0x40002440,   0xf345dbbf,   0xcba0000,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x40000000,   0x86c0000,   0xf7930000,     \
0x40000982,   0x4aef67d,   0xfb510000,     \
0x40002440,   0xf345dbbf,   0xcba0000,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0
  
    
    #define BES_LOUDNESS_LPF_COEFF \
0x1bc91bc9,   0x86c,   0x0,     \
0x1da81da8,   0x4ae,   0x0,     \
0x265d265d,   0xf345,   0x0,     \
0x32793279,   0xdb0c,   0x0,     \
0x37cb37cb,   0xd069,   0x0,     \
0x0,   0x0,   0x0

    #define BES_LOUDNESS_WS_GAIN_MAX  0x399A 
           
    #define BES_LOUDNESS_WS_GAIN_MIN  0x2666
           
    #define BES_LOUDNESS_FILTER_FIRST  0
           
    #define BES_LOUDNESS_GAIN_MAP_IN \
    -45, -44, -43, -18,  0
   
    #define BES_LOUDNESS_GAIN_MAP_OUT \            
    12, 12, 12, 12, 0

	#define BES_LOUDNESS_ATT_TIME	0xa4
	#define BES_LOUDNESS_REL_TIME	0x4010
#else
	 /* Compensation Filter HSF coeffs: default all pass filter       */
    /* BesLoudness also uses this coeffs    */ 
    #define BES_LOUDNESS_HSF_COEFF \
0x7d1273d,   0xf05db185,   0x7d1273d,   0x7d09c2e4,   0x0,     \
0x7cd0ff2,   0xf065e01c,   0x7cd0ff2,   0x7cc6c324,   0x0,     \
0x7ba2211,   0xf08bbbde,   0x7ba2211,   0x7b8fc44a,   0x0,     \
0x7a36091,   0xf0b93ede,   0x7a36091,   0x7a14c5a8,   0x0,     \
0x79b63e3,   0xf0c9383a,   0x79b63e3,   0x798ec622,   0x0,     \
0x776a522,   0xf112b5bc,   0x776a522,   0x7720c84b,   0x0,     \
0x74aedf3,   0xf16a241a,   0x74aedf3,   0x742ecad0,   0x0,     \
0x73bb426,   0xf18897b4,   0x73bb426,   0x7324cbad,   0x0,     \
0x6f66ffb,   0xf2132009,   0x6f66ffb,   0x6e52cf84,   0x0,     \
    \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,   0x0,   0x0

    /* Compensation Filter BPF coeffs: default all pass filter      */ 
    #define BES_LOUDNESS_BPF_COEFF \
0x3fd08185,   0x3ef07e7a,   0xc13e0000,     \
0x3fcc81ae,   0x3ed87e51,   0xc15a0000,     \
0x3fb9827a,   0x3e6a7d85,   0xc1db0000,     \
0x3fa2838f,   0x3de67c70,   0xc2770000,     \
0x3f9a83f9,   0x3db77c06,   0xc2ad0000,     \
0x3f758619,   0x3ce079e6,   0xc3a90000,     \
    \
0x3fc08259,   0x3e977da6,   0xc1a70000,     \
0x3fbb829e,   0x3e787d61,   0xc1cc0000,     \
0x3fa28403,   0x3de67bfc,   0xc2770000,     \
0x3f8385ff,   0x3d387a00,   0xc3440000,     \
0x3f7886c6,   0x3cfb7939,   0xc38c0000,     \
0x3f478ae1,   0x3be1751e,   0xc4d60000,     \
    \
0x40000000,   0x38200000,   0xc7df0000,     \
0x4000108b,   0x3779ef74,   0xc8860000,     \
0x40005264,   0x3486ad9b,   0xcb790000,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x3f2fab0e,   0x38f054f1,   0xc7df0000,     \
0x3f1eb195,   0x385a4e6a,   0xc8860000,     \
0x3ed0d368,   0x35b52c97,   0xcb790000,     \
0x3e760000,   0x32a50000,   0xcee40000,     \
0x3e570f80,   0x3199f07f,   0xd00e0000,     \
0x3dce4b7e,   0x2cf4b481,   0xd53c0000,     \
    \
0x40000000,   0x86c0000,   0xf7930000,     \
0x40000982,   0x4aef67d,   0xfb510000,     \
0x40002440,   0xf345dbbf,   0xcba0000,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x40000000,   0x86c0000,   0xf7930000,     \
0x40000982,   0x4aef67d,   0xfb510000,     \
0x40002440,   0xf345dbbf,   0xcba0000,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
    \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0,     \
0x0,   0x0,   0x0

    
    #define BES_LOUDNESS_DRC_FORGET_TABLE \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000, \
    0x00000000, 0x00000000   

    #define BES_LOUDNESS_WS_GAIN_MAX  0
           
    #define BES_LOUDNESS_WS_GAIN_MIN  0
           
    #define BES_LOUDNESS_FILTER_FIRST  0
           
    #define BES_LOUDNESS_GAIN_MAP_IN \
    0, 0, 0, 0,  0
              
    #define BES_LOUDNESS_GAIN_MAP_OUT \            
    0, 0, 0, 0, 0   
#endif
#endif
