// Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMEOS_PLATFORM_UPDATE_ENGINE_POLICY_MANAGER_FAKE_SYSTEM_PROVIDER_H_
#define CHROMEOS_PLATFORM_UPDATE_ENGINE_POLICY_MANAGER_FAKE_SYSTEM_PROVIDER_H_

#include "update_engine/policy_manager/fake_variable.h"
#include "update_engine/policy_manager/system_provider.h"

namespace chromeos_policy_manager {

// Fake implementation of the SystemProvider base class.
class FakeSystemProvider : public SystemProvider {
 public:
  FakeSystemProvider() {}

 protected:
  virtual bool DoInit() {
    set_var_is_normal_boot_mode(
        new FakeVariable<bool>("is_normal_boot_mode", kVariableModeConst));
    set_var_is_official_build(
        new FakeVariable<bool>("is_official_build", kVariableModeConst));
    return true;
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(FakeSystemProvider);
};

}  // namespace chromeos_policy_manager

#endif  // CHROMEOS_PLATFORM_UPDATE_ENGINE_POLICY_MANAGER_FAKE_SYSTEM_PROVIDER_H_
