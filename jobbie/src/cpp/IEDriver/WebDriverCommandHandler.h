#ifndef WEBDRIVER_IE_WEBDRIVERCOMMANDHANDLER_H_
#define WEBDRIVER_IE_WEBDRIVERCOMMANDHANDLER_H_

#include <map>
#include <string>
#include "json.h"

using namespace std;

namespace webdriver {

// Forward declaration of classes to avoid
// circular include files.
class BrowserManager;
class ElementWrapper;
class WebDriverResponse;

class WebDriverCommandHandler {
public:
	WebDriverCommandHandler(void);
	virtual ~WebDriverCommandHandler(void);
	void Execute(BrowserManager *manager, std::map<std::string, std::string> locator_parameters, std::map<std::string, Json::Value> command_parameters, WebDriverResponse * response);

protected:
	virtual void ExecuteInternal(BrowserManager *manager, std::map<std::string, std::string> locatorParameters, std::map<std::string, Json::Value> commandParameters, WebDriverResponse * response);
	int GetElement(BrowserManager *manager, std::wstring element_id, ElementWrapper **element_wrapper);
};

} // namespace webdriver

#endif // WEBDRIVER_IE_WEBDRIVERCOMMANDHANDLER_H_
