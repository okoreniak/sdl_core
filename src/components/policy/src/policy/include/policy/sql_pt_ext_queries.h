/*
 Copyright (c) 2013, " Ford Motor Company
 All rights reserved.

 Redistribution and use in source and binary forms, " with or without
 modification, " are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, " this
 list of conditions and the following disclaimer.

 Redistributions in binary form must reproduce the above copyright notice, "
 this list of conditions and the following
 disclaimer in the documentation and/or other materials provided with the
 distribution.

 Neither the name of the Ford Motor Company nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, " INCLUDING, " BUT NOT LIMITED TO, " THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, " INDIRECT, " INCIDENTAL, " SPECIAL, " EXEMPLARY, " OR
 CONSEQUENTIAL DAMAGES (INCLUDING, " BUT NOT LIMITED TO, " PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, " DATA, " OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, " WHETHER IN
 CONTRACT, " STRICT LIABILITY, " OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, " EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_POLICY_INCLUDE_POLICY_SQL_PT_EXT_QUERIES_H_
#define SRC_COMPONENTS_POLICY_INCLUDE_POLICY_SQL_PT_EXT_QUERIES_H_

#include <string>

namespace policy {
namespace sql_pt_ext {

extern const char* kSelectKeepContext;
extern const char* kSelectStealFocus;
extern const char* kResetDeviceConsents;
extern const char* kResetAppConsents;
extern const char* kCountDeviceConsentGroup;
extern const char* kCountDevice;
extern const char* kSelectDeviceConsentedGroup;
extern const char* kUpdateDeviceConsentedGroup;
extern const char* kUpdateDevice;
extern const char* kInsertDeviceConsentedGroup;
extern const char* kInsertDevice;
extern const char* kSelectDeviceData;
extern const char* kSelectConsentGroup;
extern const char* kInsertPreconsentedGroups;
extern const char* kSelectPreconsentedGroups;
extern const char* kDeletePreconsentedGroups;
extern const char* kSelectUsageAndErrorCount;
extern const char* kSelectAppLevels;
extern const char* kUpdateGlobalCounters;
extern const char* kInsertDeviceData;
extern const char* kDeleteDeviceData;
extern const char* kInsertConsentGroups;
extern const char* kCountUnconsentedGroups;
extern const char* kSelectModuleMeta;
extern const char* kUpdateMetaParams;
extern const char* kUpdateModuleMetaVinParam;
extern const char* kSaveModuleMeta;
extern const char* kSelectMetaParams;
extern const char* kCountAppLevel;
extern const char* kUpdateGroupPermissions;
extern const char* kSelectDefaultHmi;
extern const char* kInsertApplication;
extern const char* kSelectFriendlyMsg;
extern const char* kCollectFriendlyMsg;
extern const char* kSelectAppGroupsId;
extern const char* kSelectConsentedGroupsId;
extern const char* kCountAppConsents;
extern const char* kSelectPreconsentedGroupsId;
extern const char* kSelectFunctionalGroupNames;
extern const char* kSelectAppPolicies;
extern const char* kUpdateMetaLanguage;
extern const char* kDeleteDeviceConsent;
extern const char* kDeleteAppGroupConsent;
extern const char* kSelectGroupId;
extern const char* kSelectApplicationIsPreData;
extern const char* kUpdateIsPredata;
extern const char* kHasAppPreloadedGroups;
extern const char* kUpdateUnpairedDevice;
extern const char* kSelectUnpairedDevices;
extern const char* kHasMsgLanguageCode;
extern const char* kDeletePreconsentedGroupsByApplicationId;
extern const char* kDeleteAppConsent;

}  // namespace sql_pt_ext
}  // namespace policy

#endif  // SRC_COMPONENTS_POLICY_INCLUDE_POLICY_SQL_PT_EXT_QUERIES_H_
