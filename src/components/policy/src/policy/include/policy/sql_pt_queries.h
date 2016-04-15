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

#ifndef SRC_COMPONENTS_POLICY_INCLUDE_POLICY_SQL_PT_QUERIES_H_
#define SRC_COMPONENTS_POLICY_INCLUDE_POLICY_SQL_PT_QUERIES_H_

#include <string>

namespace policy {
namespace sql_pt {

extern const char* kSelectPriority;
extern const char* kCreateSchema;
extern const char* kDropSchema;
extern const char* kDeleteData;
extern const char* kCheckPgNumber;
extern const char* kCheckDBIntegrity;
extern const char* kSelectRpc;
extern const char* kSelectPreloaded;
extern const char* kIsFirstRun;
extern const char* kSetNotFirstRun;
extern const char* kSelectEndpoint;
extern const char* kSelectLockScreenIcon;
extern const char* kSelectModuleConfig;
extern const char* kSelectEndpoints;
extern const char* kSelectNotificationsPerMin;
extern const char* kSelectNotificationsPerPriority;
extern const char* kSelectAppLevels;
extern const char* kSelectDeviceData;
extern const char* kSelectFunctionalGroups;
extern const char* kSelectAllRpcs;
extern const char* kSelectUserMsgsVersion;
extern const char* kSelectAppPolicies;
extern const char* kSelectAppGroups;
extern const char* kSelectNicknames;
extern const char* kSelectAppTypes;
extern const char* kSelectRequestTypes;
extern const char* kSelectSecondsBetweenRetries;
extern const char* kSelectIgnitionCycles;
extern const char* kSelectKilometers;
extern const char* kSelectDays;
extern const char* kSelectTimeoutResponse;
extern const char* kInsertFunctionalGroup;
extern const char* kInsertRpc;
extern const char* kInsertRpcWithParameter;
extern const char* kInsertApplication;
extern const char* kInsertAppGroup;
extern const char* kInsertNickname;
extern const char* kInsertAppType;
extern const char* kInsertRequestType;
extern const char* kInsertMessageType;
extern const char* kInsertLanguage;
extern const char* kInsertMessageString;
extern const char* kUpdateVersion;
extern const char* kUpdateModuleConfig;
extern const char* kInsertEndpoint;
extern const char* kInsertSecondsBetweenRetry;
extern const char* kInsertNotificationsByPriority;
extern const char* kInsertDeviceData;
extern const char* kInsertAppLevel;
extern const char* kDeleteSecondsBetweenRetries;
extern const char* kDeleteEndpoint;
extern const char* kDeleteAppLevel;
extern const char* kDeleteMessageString;
extern const char* kDeleteFunctionalGroup;
extern const char* kDeleteRpc;
extern const char* kDeleteAppGroup;
extern const char* kDeleteApplication;
extern const char* kDeleteRequestType;
extern const char* kDeleteDevice;
extern const char* kIncrementIgnitionCycles;
extern const char* kResetIgnitionCycles;
extern const char* kUpdateFlagUpdateRequired;
extern const char* kSelectFlagUpdateRequired;
extern const char* kUpdateCountersSuccessfulUpdate;
extern const char* kSelectApplicationRevoked;
extern const char* kUpdateApplicationCustomData;
extern const char* kSelectApplicationRepresented;
extern const char* kSelectApplicationIsDefault;
extern const char* kUpdateIsDefault;
extern const char* kInsertInitData;
extern const char* kDeleteAppGroupByApplicationId;
extern const char* kInsertApplicationFull;
extern const char* kDeletePreconsentedGroupsByApplicationId;
extern const char* kSelectApplicationFull;
extern const char* kUpdatePreloaded;

}  // namespace sql_pt
}  // namespace policy

#endif  // SRC_COMPONENTS_POLICY_INCLUDE_POLICY_SQL_PT_QUERIES_H_
