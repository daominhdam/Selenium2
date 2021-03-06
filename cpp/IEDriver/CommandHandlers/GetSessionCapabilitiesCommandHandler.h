// Copyright 2011 Software Freedom Conservancy
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WEBDRIVER_IE_GETSESSIONCAPABILITIESCOMMANDHANDLER_H_
#define WEBDRIVER_IE_GETSESSIONCAPABILITIESCOMMANDHANDLER_H_

#include "../Browser.h"
#include "../IECommandHandler.h"
#include "../IECommandExecutor.h"

namespace webdriver {

class GetSessionCapabilitiesCommandHandler : public IECommandHandler {
 public:
  GetSessionCapabilitiesCommandHandler(void) {
  }

  virtual ~GetSessionCapabilitiesCommandHandler(void) {
  }

 protected:
  void ExecuteInternal(const IECommandExecutor& executor,
                       const LocatorMap& locator_parameters,
                       const ParametersMap& command_parameters,
                       Response* response) {
    // ASSUMPTION: Version string will never be larger than 2 characters
    // (+1 for the null terminator).
    int version = executor.browser_version();
    char buffer[3];
    _itoa_s(version, buffer, 3, 10);
    std::string version_string = buffer;

    Json::Value capabilities;
    capabilities["browserName"] = "internet explorer";
    capabilities["version"] = version_string;
    capabilities["javascriptEnabled"] = true;
    capabilities["platform"] = "WINDOWS";
    capabilities["nativeEvents"] = executor.input_manager()->enable_native_events();
    capabilities["cssSelectorsEnabled"] = true;
    capabilities["takesScreenshot"] = true;
    capabilities["handlesAlerts"] = true;
    capabilities["enablePersistentHover"] = executor.enable_persistent_hover();
    capabilities["unexpectedAlertBehaviour"] = executor.unexpected_alert_behavior();
    capabilities["elementScrollBehavior"] = executor.input_manager()->scroll_behavior();
    capabilities["allowAsynchronousJavaScript"] = executor.allow_asynchronous_javascript();
    capabilities["ignoreProtectedModeSettings"] = executor.ignore_protected_mode_settings();
    capabilities["ignoreZoomSetting"] = executor.ignore_zoom_setting();
    capabilities["initialBrowserUrl"] = executor.initial_browser_url();
    capabilities["enableElementCacheCleanup"] = executor.enable_element_cache_cleanup();
    capabilities["requireWindowFocus"] = executor.input_manager()->require_window_focus();
    response->SetSuccessResponse(capabilities);
  }
};

} // namespace webdriver

#endif // WEBDRIVER_IE_GETSESSIONCAPABILITIESCOMMANDHANDLER_H_
